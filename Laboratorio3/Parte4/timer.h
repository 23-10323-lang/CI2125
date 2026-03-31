///
/// timer.h
///

#pragma once

#include <ctime>

class Timer {
public:
    // creates and starts the clock on construction
	Timer();

    // returns elapsed time from last start
	double elapsed();

    // returns elapsed time from last start and restarts the clock
	double restart();

private:
	clock_t start_;
};
