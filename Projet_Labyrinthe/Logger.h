#pragma once
#include <string>
#include <map>
#include "LogLevel.h"

/**
* Logger to print log messages with options
*/
class Logger
{
public:
	/**
	* Logger constructor, logs' timestamps are shown by default
	* \param name The symbolic name of the logger
	* \param initialLogLevel The lowest level of logs to show, lower levels of logs will be filtered
	* \param output The name of the output to use when printing the logs, stdout for the standard output, stderr for the error output, all other values will be read as a file name
	*/
	Logger(const std::string& name, const LogLevel& initialLogLevel, const std::string& output);
	~Logger();

	/**
	* Setter for the log level used by the logger as a filter
	* \param logLevel The lowest log level to show when using the logger
	*/
	void setLogLevel(const LogLevel& logLevel);

	/**
	* Setter for the output used by the logger
	* \param output The output to use when printing a log, stdout for the standard output, stderr for the error output, all other values will be read as a file name
	*/
	void setOutput(const std::string& output);

	/**
	* Setter for the option to show timestamps with printed logs
	* \param showTimestamps Wether or not to show the timestamps
	*/
	void setShowTimestamps(const bool& showTimestamps);

	/**
	* Getter for the showTimestamps member value
	* \return Return if the logger is set to show the logs' timestamps
	*/
	bool getShowTimestamps();

	/**
	* Print a log message to the set output stream
	* \param message The message to print
	* \param logLevel The log level of the message
	*/
	void log(const std::string& message, const LogLevel& logLevel);

	/**
	* Shortcut to print a log message to the set output stream with SEVERE log level
	* \param message The message to print
	*/
	void severe(const std::string& message);

	/**
	* Shortcut to print a log message to the set output stream with WARN log level
	* \param message The message to print
	*/
	void warn(const std::string& message);

	/**
	* Shortcut to print a log message to the set output stream with INFO log level
	* \param message The message to print
	*/
	void info(const std::string& message);

	/**
	* Shortcut to print a log message to the set output stream with DEBUG log level
	* \param message The message to print
	*/
	void debug(const std::string& message);
	
private:
	std::string name; /*The symbolic name of the logger*/
	LogLevel logLevel; /*The lowest value of logs the logger is allowed to print*/
	std::string output; /*The output used by the logger*/
	bool showTimestamps; /*Tells wether the logger will show a timestamp alongside the log when printed*/
	std::map<LogLevel, std::string> logLevelMap;
};