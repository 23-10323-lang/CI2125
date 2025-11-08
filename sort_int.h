///
/// sort_int.h
///
/// Interfaz de la función que implementa el algoritmo de ordenamiento
///

#pragma once

#include <vector>

// El algoritmo de ordenamiento (selection_sort) recibe una referencia a la muestra.
// Noten que el parámetro 'data' (muestra) no es declarado const: ¡esto no es es una omisión!
// El algoritmo de ordenamiento ordena los datos 'in situ', es decir en el vector original
// Por definición, esto altera el vector, aunque los datos son preservados: ¡solo el orden cambia!
// Si 'data' fuese declarada como una referencia a un vector constante, no podriamos ordenar el vector.
// Es uns buena práctica de programación usar 'const' cada vez que sea posible, sobre todo con referencias.
// Con dicha disciplina, la ausencia de const señala que se esta haciendo una cambio (mutación) de estado.
void selection_sort(std::vector<int>& data);
