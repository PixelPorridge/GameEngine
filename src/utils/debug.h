#pragma once

#include <string>
#include <iostream>

class Debug {
public:
	static void error(const std::string& message) { get().log(Level::ERROR, message); }
	static void warning(const std::string& message) { get().log(Level::WARNING, message); }
	static void success(const std::string& message) { get().log(Level::SUCCESS, message); }
	static void info(const std::string& message) { get().log(Level::INFO, message); }

private:
	enum Level {
		ERROR,
		WARNING,
		SUCCESS,
		INFO
	};

	inline void log(Level level, const std::string& message) const {
		switch (level) {
		case ERROR:
			std::cout << "\033[31m" << "ERROR " << "\033[0m" << message << std::endl; break;
		case WARNING:
			std::cout << "\033[33m" << "WARNING " << "\033[0m" << message << std::endl; break;
		case SUCCESS:
			std::cout << "\033[32m" << "SUCCESS " << "\033[0m" << message << std::endl; break;
		case INFO:
			std::cout << "\033[36m" << "INFO " << "\033[0m" << message << std::endl; break;
		}
	}

	Debug() {}

	static Debug& get() {
		static Debug instance;
		return instance;
	}

	Debug(const Debug&) = delete;
	Debug& operator=(const Debug&) = delete;
};