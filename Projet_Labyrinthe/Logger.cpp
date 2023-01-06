#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>


Logger::Logger(const std::string& name, const LogLevel& initialLogLevel, const std::string& output)
{
	this->name = name;
	this->logLevel = initialLogLevel;
	this->showTimestamps = true;
	this->output = output;

	this->logLevelMap[SEVERE] = "SEVERE";
	this->logLevelMap[WARN] = "WARN";
	this->logLevelMap[INFO] = "INFO";
	this->logLevelMap[DEBUG] = "DEBUG";
}

Logger::~Logger()
{
}

void Logger::setLogLevel(const LogLevel& logLevel)
{
	this->logLevel = logLevel;
}

void Logger::setOutput(const std::string& output)
{
	this->output = output;
}

void Logger::setShowTimestamps(const bool& showTimestamps)
{
	this->showTimestamps = showTimestamps;
}

bool Logger::getShowTimestamps()
{
	return this->showTimestamps;
}

void Logger::log(const std::string& message, const LogLevel& logLevel)
{
	if (this->logLevel <= logLevel) {
		std::string timestamp = "";
		if (showTimestamps) {
			std::time_t currentTime = time(NULL);
			char currentTime_array[26];
			ctime_s(currentTime_array, sizeof currentTime_array, &currentTime);

			//Conversion of char array to string to delete the year at the end of the timestamp
			std::string currentTime_str(currentTime_array);
			currentTime_str.erase(currentTime_str.end() - 5, currentTime_str.end());
			timestamp = currentTime_str + ": ";
		}

		if (this->output == "stdout") {
			std::cout << "[" << timestamp << this->logLevelMap[logLevel] << "] " << this->name << " : " << message << std::endl;
		}
		else if (this->output == "stderr") {
			std::cerr << "[" << timestamp << this->logLevelMap[logLevel] << "] " << this->name << " : " << message << std::endl;
		}
		else {
			std::ofstream fileStream;
			fileStream.open(this->output, std::ios_base::app);
			fileStream << "[" << timestamp << this->logLevelMap[logLevel] << "] " << this->name << " : " << message << std::endl;
			fileStream.close();
		}
	}
}

void Logger::severe(const std::string& message)
{
	this->log(message, SEVERE);
}

void Logger::warn(const std::string& message)
{
	this->log(message, WARN);
}

void Logger::info(const std::string& message)
{
	this->log(message, INFO);
}

void Logger::debug(const std::string& message)
{
	this->log(message, DEBUG);
}
