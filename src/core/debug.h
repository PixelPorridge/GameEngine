#pragma once

#include <string>
#include <vector>
#include <iostream>

class Debug {
public:
	enum LogLevel {
		INFO,
		SUCCESS,
		WARNING,
		ERROR
	};

	static void log(const std::string& message, LogLevel level = INFO) {
		switch (level) {
		case INFO:
			std::cout << "\033[36m" << "INFO " << "\033[0m" << message << std::endl; break;
		case SUCCESS:
			std::cout << "\033[32m" << "SUCCESS " << "\033[0m" << message << std::endl; break;
		case WARNING:
			std::cout << "\033[33m" << "WARNING " << "\033[0m" << message << std::endl; break;
		case ERROR:
			std::cout << "\033[31m" << "ERROR " << "\033[0m" << message << std::endl; break;
		}
	}
};