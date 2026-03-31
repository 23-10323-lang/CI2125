///
/// timer.cxx
///

#include "timer.h"

Timer::Timer() {
    start_ = clock();
}

double Timer::elapsed()	{
    return double(clock() - start_)/double(CLOCKS_PER_SEC);
}

double Timer::restart()	{
    double elapsed = double(clock() - start_)/double(CLOCKS_PER_SEC);
    start_ = clock();
    return elapsed;
}
