///
/// stats.h
///
/// Funciones Estadísticas - Statistic functions
///

#ifndef stats_h
#define stats_h

#include <vector>

typedef double FP;

typedef std::vector<FP> Data;

FP uniform();

// promedio
FP average(const Data& x);

// varianza
FP varp(const Data& data);

// varianza usando la forma computacional
FP varp_c(const Data& data);

#endif
