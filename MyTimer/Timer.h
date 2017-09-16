#pragma once
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

void PeriodFunction(milliseconds period, vector<int(*)(int)> handler);

class Timer
{
public:
	Timer(int period);
	~Timer();
	void Handler_add(int(*method)(int));
	void Start();
	private:

	chrono::milliseconds _period;
	vector<int(*)(int)> _handler;
};

