#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include "Worker.h"

using namespace std;

class Logger
{
public:
	inline static Logger* instance() {
		return instance_.get();
	}

	inline static void initInstance(string filename);

	Logger(Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	void log(string info);
	void log(function<string()> f);
private:
	Logger(string filename);
	virtual ~Logger();
	static unique_ptr<Logger> instance_;
	Worker worker_;
	ofstream log_;

};

