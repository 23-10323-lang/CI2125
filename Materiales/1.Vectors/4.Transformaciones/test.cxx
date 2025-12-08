///
/// test - main program
///

#include "map.h"

#include <cstdio>
#include <cstdlib>
#include <string>

using std::string;
using std::vector;

///
/// Mappers - Transfomadores
///

double dd_mapper(double x) {
    return (1 + x) * (1 + x) * (1 + x) * (1 + x) * (1 + x);
}

bool db_mapper(double x) {
    return x < 0.1 || 0.9 < x;
}

///
/// Reducers
///

// suma
double sum(const vector<double>& vec) {
    double result = 0.0;
    for (double x: vec) {
        result = result + x;
    }
    return result;
}

// contar verdaderos
int count_true(const vector<bool>& vec) {
    int result = 0;
    for (bool x: vec) {
        if (x) {
            result = result + 1;
        }
    }
    return result;
}

// promedio
double mean(const vector<double>& vec ) {
    const int n = vec.size();
    return sum(vec) / n;
}


///
/// Generación de datos de prueba
/// 

double uniform() {
    return double(rand()) / double(RAND_MAX);
}

double uniform(double lb, double ub) {  
    return (ub - lb) * uniform() + lb;
}

/// Genera un vector de números (doble precisión) de tamaño 'n'
vector<double> gen_uniform(int n, double lb, double ub) {
    vector<double> data;
    data.reserve(n);
    for (int i = 0; i < n; ++i) {
        double x = uniform(lb, ub);
        data.push_back(x);
    }
    return data;
}

///
/// Programa principal
///

void run(int n) {
    // Generamos y almacenamos los datos de entrada
    vector<double> input = gen_uniform(n, -0.02, 0.08);

    // Mostramos los datos de entrada
    show(input, "%9.6f", "input");

    // Transformamos la entrada y almacenamos los datos transformados 
    vector<double> transformed = map(dd_mapper, input);

    // Mostramos el resultado
    show_map(input, "%9.6f", transformed, "%6.3f", "input => transformed");

    // Aplicamos un reductor a los datos transformados y almacenamos el resultado
    double result = reduce(mean, transformed); // mean(transformed)

    // Mostramos el resultado final
    fprintf(stdout, "\nresult = %f\n", result);
}

/*
void run(int n) {
    // Generamos y almacenamos los datos de entrada
    vector<double> input = gen_uniform(n, 0, 1);

    // Mostramos los datos de entrada
    show(input, "%7f", "input");

    // Transformamos la entrada y almacenamos los datos transformados 
    vector<bool> transformed = map(db_mapper, input);

    // Mostramos el resultado
    show_map(input, "%7f", transformed, "%d", "input => transformed");

    // Aplicamos un reductor a los datos transformados y almacenamos el resultado
    int result = reduce(count_true, transformed); // mean(transformed)

    // Mostramos el resultado final
    fprintf(stdout, "\nresult = %d\n", result);
}
*/

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "uso: %s <n> .. donde <n> es el número de elementos del vector\n", argv[0]);
        return EXIT_FAILURE; // from stdlib
    }

    int n = atoi(argv[1]);

    run(n);

    return EXIT_SUCCESS; // same as return 0
}
