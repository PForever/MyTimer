// MyTimer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Timer.h"
#include <iostream>
using namespace std;

int main()
{
	auto tmr = new Timer(1);
	tmr->Handler_add([](int time)
	{
		int hour = time / 36000;
		int min = (time / 600) % 60;
		int sec = (time / 10) % 60;
		int mil = time % 10;
		system("cls");
		cout << hour << ":" << min << ":" << sec << ":" << mil;
		return 0;
	});
	tmr->Start();
	cin.get();
    return 0;
}

