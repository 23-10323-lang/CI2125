///
/// stats.cxx
///
/// Funciones Estadísticas - Statistic functions
///

#include <cstdlib>

#include "stats.h"

using std::vector;

FP uniform() {
    return FP(rand()) / FP(RAND_MAX);
}

// promedio
FP average(const Data& x) {
    const size_t n = x.size();
    FP sx = 0.0;
    for (size_t i = 0; i < n; ++i) {
        sx += x[i];
    }
    return sx / n;
}

// promedio: mismo algoritmo, usando lazo estilo "foreach"
FP average_alt(const Data& x) {
    const size_t n = x.size();
    FP sx = 0.0;
    for (double v: x) {
        sx += v;
    }
    return sx / n;
}

// varianza
FP varp(const Data& data) {
    const FP mean = average(data);
    const size_t n = data.size();
    FP dev2 = 0.0;
    for (size_t i = 0; i < n; ++i) {
        const FP dev = data[i] - mean;
        dev2 += dev * dev;
    }
    return dev2 / n;
}

// varianza usando la forma computacional
FP varp_c(const Data& data) {
    const size_t n = data.size();
    FP sx = 0.0;
    FP sx2 = 0.0;
    for (size_t i = 0; i < n; ++i) {
        const FP x = data[i];
        sx += x;
        sx2 += x * x;
    }
    const FP mean = sx / n;
    return sx2 / n - mean * mean;
}
