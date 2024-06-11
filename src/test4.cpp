#include <windows.h>
#include <iostream>

// ����һ����ʱ���ص�����
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	std::cout << "Timer event occurred. Time: " << dwTime << std::endl;
}

int main() {
	// ����һ����ʱ����ÿ�봥��һ��
	UINT_PTR timerId = SetTimer(NULL, 0, 1000, TimerProc);
	if (timerId == 0) {
		std::cerr << "Failed to create timer." << std::endl;
		return 1;
	}

	std::cout << "Timer set. Press Enter to exit." << std::endl;

	// ������Ϣѭ�����ȴ���ʱ���¼�
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// ����ʱ��
	KillTimer(NULL, timerId);

	return 0;
}
