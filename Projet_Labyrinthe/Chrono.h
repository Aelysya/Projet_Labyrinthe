#pragma once
#include <chrono>
#include <string>

class Chrono
{
public:
	/**
	 * Constructor to create a chrono.
	 */
	Chrono();
	~Chrono();

	/**
	 * Launch the chrono by saving the current time in an attribute.
	 * 
	 */
	void launchChrono();

	/**
	 * Stop the chrono by saving the current time in an attribute.
	 * 
	 */
	void stopChrono();

	/**
	 * Getter for the time elapsed between the start and the stop of the chrono in seconds.
	 * 
	 * \return The time in seconds
	 */
	double getElapsedTimeSeconds();

	/**
	 * Getter for the time elapsed between the start and the stop of the chrono in milliseconds.
	 *
	 * \return The time in milliseconds
	 */
	double getElapsedTimeMilliSeconds();

private:
	std::chrono::steady_clock::time_point timeWhenStarted; /*The time when the chrono was started*/
	std::chrono::steady_clock::time_point timeWhenStopped; /*The time when the chrono was stopped*/
};