#include "Chrono.h"

Chrono::Chrono()
{
}

Chrono::~Chrono()
{
}

void Chrono::launchChrono()
{
	this->timeWhenStarted = std::chrono::steady_clock::now();
}

void Chrono::stopChrono()
{
	this->timeWhenStopped = std::chrono::steady_clock::now();
}

double Chrono::getElapsedTimeSeconds()
{
	std::chrono::duration<double> elapsedTime = timeWhenStopped - timeWhenStarted;
	return elapsedTime.count();
}

double Chrono::getElapsedTimeMilliSeconds()
{
	return getElapsedTimeSeconds() * 1000;
}
