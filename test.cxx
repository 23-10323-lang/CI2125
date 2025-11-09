///
/// test.cxx
///
/// programa para probar el ordenamiento de datos enteros
///

#include <cstdio>
#include <cstdlib>

#include "sort_int.h"

using std::vector;

// La función 'random' es un generador extremadamente simple de números aleatorios
// Dado el parámetro n, cada llamada a random(n) genera un entero x tal que 0 <= x < n
// La función random se deriva de la función de librería (stdlib) 'rand'
// Cada llamada a rand() genera un entero z tal que 0 <= z <= RAND_MAX
// Recuerdan el operador % ? Una expresión de la forma m % n computa m módulo n ..
// .. que, como les dijimos en clase, es el resto de la division entera de m entre n.
// El valor de RAND_MAX depende de la implementacion, pero garantiza ser por lo menos 32767.
// Por ejemplo: 18 % 7 es igual a 4. Prueba: 18 == 2 * 7 + 4 => 2 es el cociente y 4 el resto.
// En este ejemplo, limitamos n a ser menor que 1000, asi que la función rand es adecuada.
// Referencias:
// https://en.cppreference.com/w/cpp/numeric/random/rand.html
// https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/
int random(int n) {
    return rand() % n;        
}

// genera un vector de n enteros (x's) aleatorios, donde cada x cumple 0 <= x < 1000
vector<int> generate_vector(int n) {
    vector<int> xs = {};
    for (int i = 0; i < n; ++i) {
        int x = random(1000);
        xs.push_back(x);
    }
    return xs;
}

// muestra los elementos de un vector de enteros (data), prefijados por una etiqueta (label)
void show(const char *label, const vector<int>& data) {
    fprintf(stdout, "%s\n", label);
    const int n = data.size();
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "%4d: %4d\n", i, data[i]);
    }
    fprintf(stdout, "\n");
}

// 'run' corre el corazón del programa: 4 pasos sencillos para probar que funciona
// El parámetro n indica el tamaño del vector (muestra) a ser ordenado
// 'run' no retorna nada ('void' es 'vacio') pero muestra los datos y resultados
void run(int n) {
    // 1. iniciamos la muestra 'data', de tamaño 'n', con números aleatorios para probar el ordenamiento
    vector<int> data = generate_vector(n);

    // 2. muestra los datos (desordenados) antes de ordenarlos
    show("datos antes:", data);

    // 3. invoca el algoritmo (selection sort) que ordena los datos
    selection_sort(data);

    // 4. muestra el vector despues de ordenar los datos
    show("datos despues:", data);
}

// se queja del mal uso del programa, si ese es el caso
void bad_usage(const char *program) {
    fprintf(stderr, "uso: %s n (para 0 <= n < 1000)\n", program);
}

// procedimiento principal: la interfaz con el shell (comandos interactivos) del usuario
int main(int argc, const char *argv[]) {
    // argc debe ser 2 porque el programa requiere pasar n (tamaño de la muestra) como argumento
    if (argc != 2) {
        bad_usage(argv[0]);
        // EXIT_FAILURE es un código de salida del programa que indica que hubo error
        // si su ambiente de desarrollo no lo define, pueden reemplazarlo con facilidad
        // todo número distinto de 0 indica que hubo una falla.
        return EXIT_FAILURE;
    }

    // extraemos el tamaño de la muestra especificado por el usuario
    int n = atoi(argv[1]);
    if (n < 0 || 1000 <= n) {
        bad_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // todo bien, asi que ejecutamos la prueba ..
    run(n);

    // EXIT_SUCCESS es igual a 0: el código de salida que indica que no hubo error.
    return EXIT_SUCCESS;
}
