///
/// test.cxx
///
/// programa para probar el ordenamiento de datos de tipo 'double' (punto flotante de doble precisión)
///
/// @@@ NOTA: La idea es que este programa funcione como lo hace el ordenamiento de datos enteros
/// la única diferencia es que aqui lo hacemos con valores de punto flotante de doble precisión
///

#include <cstdio>
#include <cstdlib>

#include "sort_double.h"

using std::vector;

// Un simple generador de numeros aleatorios
// de acuerdo a la distribucion uniforme estandard: 0 <= x <= 1
double uniform() {
    double numerator = double(rand());
    double denominator = double(RAND_MAX);
    return numerator / denominator;
}

// Un simple generador de numeros aleatorios en el intervalo [lb .. ub]
// Asume (sin chequear) que lb es menor o igual a ub
double random(double lb, double ub) {
    return (ub - lb) * uniform() + lb;
}

// genera el vector (muestra) de datos para la prueba de ordenamiento
vector<double> generate_vector(int n) {
    vector<double> data = {};
    for (int i = 0; i < n; ++i) {
        double x = random(-8.0, 8.0);
        data.push_back(x);
    }
    return data;
}

// @@@ TIP
// En lo que sigue, usen el ejemplo de ordenamiento de datos enteros como inspiración.
// Pueden copiar las partes que deben completar, PERO ..
// .. no olviden que ahora estan trabajando con datos de tipo 'double' en vez de 'int'

// @@@ TAREA: implementar la funcion 'show' que muestra el vector
void show(const char *label, const vector<double>& data) {
    // van a tener que usar un especificador de formato (format specifier) para punto flotante
    // No se limiten a usar %f: usen uno de la forma %W.Df donde:
    // W es el ancho necesario para mostrar los números con el punto decimal bien alineado
    // D es el número de digitos a la derecha del punto decimal: sugiero D igual a 6
    
    fprintf(stdout, "%s\n", label);
    const int n = data.size();
    for (int i = 0; i < n; ++i) {
        // Usamos %10.6f para alinear: 10 de ancho total, 6 dígitos decimales
        fprintf(stdout, "%4d: %10.6f\n", i, data[i]);
    }
    fprintf(stdout, "\n");
}

void run(int n) {
    // @@@ TAREA: completar
    
    // 1. iniciamos la muestra 'data', de tamaño 'n', con números aleatorios
    vector<double> data = generate_vector(n);

    // 2. muestra los datos (desordenados) antes de ordenarlos
    show("datos antes:", data);

    // 3. invoca el algoritmo (selection sort) que ordena los datos
    selection_sort(data);

    // 4. muestra el vector despues de ordenar los datos
    show("datos despues:", data);
}

void bad_usage(const char *program) {
    fprintf(stderr, "uso: %s n (para 0 <= n < 128)\n", program);
}

int main(int argc, const char *argv[]) {
    // @@@ TAREA: completar
    
    // argc debe ser 2 porque el programa requiere pasar n (tamaño de la muestra) como argumento
    if (argc != 2) {
        bad_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // extraemos el tamaño de la muestra especificado por el usuario
    int n = atoi(argv[1]);
    // Ajustado al límite de la tarea
    if (n < 0 || 128 <= n) {
        bad_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // todo bien, asi que ejecutamos la prueba ..
    run(n);

    // EXIT_SUCCESS es igual a 0: el código de salida que indica que no hubo error.
    return EXIT_SUCCESS;
}