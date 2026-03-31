///
/// Query.h - interfaz para los ejercicios del examen
///

#pragma once

#include <vector>
#include "Estudiante.h"

struct Query {
    static float q0();
    static std::vector<Estudiante> q1();
    static int q2();
};
