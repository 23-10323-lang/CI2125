///
/// map.h
///

#pragma once

#include <vector>

typedef double E; // tipo de los elementos de entrada
typedef double T; // tipo de los elementos transformados
typedef double R; // tipo del resultado

// map
std::vector<T> map(T mapper(E element), const std::vector<E>& input);

// reduce
R reduce(R reducer(const std::vector<T>& input), const std::vector<T>& input);

///
/// Output helpers | Funciones auxiliares para mostrar resultados
///

/// show vector polymorphism hack style
void show(const std::vector<E>& vec, const char *specifier, const char *label);

/// show map polymorphism hack style
void show_map(const std::vector<E>& in, const char *ispec, const std::vector<T>& out, const char *ospec, const char *label);
