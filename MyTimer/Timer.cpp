#include "stdafx.h"
#include "Timer.h"

void PeriodFunction(milliseconds period, vector<int(*)(int)> handler)
{
	milliseconds time = milliseconds(0);
	while (true)
	{
		//_time.operator+=(period);
		time += period;
		this_thread::sleep_for(period);
		for (auto method : handler)
		{
			method(time.count());
			//thread thr(method, time.count());
			//thr.join();
		}
	}
}

Timer::Timer(int period)
{
	_period = milliseconds(period);
}


Timer::~Timer()
{
}

void Timer::Handler_add(int(*method)(int))
{
	_handler.push_back(method);
}

void Timer::Start()
{
	thread thr(PeriodFunction, _period, _handler);
	thr.detach();
}


