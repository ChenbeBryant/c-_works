#include <windows.h>
#include <iostream>

// 定义一个定时器回调函数
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	std::cout << "Timer event occurred. Time: " << dwTime << std::endl;
}

int main() {
	// 设置一个定时器，每秒触发一次
	UINT_PTR timerId = SetTimer(NULL, 0, 1000, TimerProc);
	if (timerId == 0) {
		std::cerr << "Failed to create timer." << std::endl;
		return 1;
	}

	std::cout << "Timer set. Press Enter to exit." << std::endl;

	// 进入消息循环，等待定时器事件
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// 清理定时器
	KillTimer(NULL, timerId);

	return 0;
}
