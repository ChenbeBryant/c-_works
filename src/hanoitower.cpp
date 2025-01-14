#include <iostream>
using  	std::cin;
using  	std::cout;
using 	std::endl;

void move(char cSource,char cTarget)
{
	static int iStep = 0;
	cout << "Step" <<++iStep<<" :Move from " << cSource << " to "<<cTarget<<endl;
}

void hanoi(int iHeight, char cSource ,char cAssistant, char cTarget)
{
	if (1 == iHeight)
	{
		move(cSource,cTarget);
		return;
	}
	hanoi(iHeight-1,cSource,cTarget,cAssistant);
	move(cSource,cTarget);
	hanoi(iHeight-1,cAssistant,cSource,cTarget);
}

int main()
{
	cout <<"input your height of tower"<<endl;
	int iHeight=0;
	cin >> iHeight;
	hanoi(iHeight,'A','B','C');
	cout << "Finished"<<endl;
	return 0;
}