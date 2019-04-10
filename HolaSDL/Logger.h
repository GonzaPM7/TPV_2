#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <functional>
#include "Worker.h"

using namespace std;

class Logger
{
public:
	inline static Logger* instance() {
		return instance_.get();
	}

	inline static void initInstance(string filename)
	{
		if (instance_.get() == nullptr) {
			instance_.reset(new Logger(filename));
		}
	}

	virtual ~Logger();
	Logger(Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	void log(string info);
	void log(function<string()> f);
private:
	Logger(string filename);
	static unique_ptr<Logger> instance_;
	Worker worker_;
	ofstream log_;

};

