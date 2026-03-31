///
/// rand997.cxx
///

#include <cmath>
#include <cstdio>
#include <ctime>

const double pi = 3.14159265358979323846;

static double r997 = 0.1415926535897;

void seed(unsigned long iseed) {
    srand(iseed ? iseed : time(0));
    r997 = iseed == 1 ? r997 : (double(rand()) + 0.001) / (double(RAND_MAX) + 0.002);
}

static inline double frac(double num) {
    return num - floor(num);
}

double rand997() {
    return (r997 = frac(997 * r997));
}

double Box(double u1, double u2) {
    return sqrt(-2 * log(u1)) * cos(2 * pi * u2);
}

double Mueller(double u1, double u2) {
    return sqrt(-2 * log(u1)) * sin(2 * pi * u2);
}
