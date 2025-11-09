///
/// sort_double.cxx
///

#include "sort_double.h"

#include <cstdio>
#include <cstdlib>

using std::vector;

// Copiar el código de sort_int y modificarlo ayuda .. pero ..
// no olviden que ahora estan trabajando con 'double' en vez de 'int'
// Sin embargo, noten que los índices de los vectores son de tipo int .. duh!
// Presten atención para diferenciar si estan trabajando con datos o indices!

int min(int lb, int ub, const vector<double>& data) {
    // @@@ TAREA: completar
    const int n = data.size();

    if (n == 0) {
        return -1; 
    }
    if (lb < 0 || lb >= ub) {
        return -1;
    }
    if (ub > n) {
        return -1;
    }

    int mindex = lb; 
    // ¡Cambiamos a double!
    double minimum = data[mindex]; 

    for (int i = lb + 1; i < ub; ++i) {
        // La comparación funciona igual para doubles
        if (data[i] < minimum) {
            mindex = i; 
            minimum = data[mindex];
        }
    }
    return mindex;
}

int min(const vector<double>& data) {
    const int n = data.size();
    int index = min(0, n, data);
    if (index < 0) {
        exit(EXIT_FAILURE);
    }
    return index;
}

void selection_sort(vector<double>& data) {
    // @@@ TAREA: completar
    const int n = data.size();
    if (n == 0) {
        return; 
    }

    for (int i = 0; i < n-1; ++i) {
        int mindex = min(i, n, data);

        {
            // swap data[i] <-> data[mindex]
            // ¡Cambiamos a double!
            double tmp = data[i];
            data[i] = data[mindex];
            data[mindex] = tmp;
        }
    }
}