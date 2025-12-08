///
/// test.cxx
///
/// Programa de prueba del generador de nombres
///

#include "names.h"

#include <cstdio>
#include <cstdlib>

using std::string;
using std::vector;

// Muestra los elementos de un vector de strings de C++
// Cada elemento se muestra en una línea de la pantalla (stdout)
// El '&' indica que el parámetro es una referencia al vector ..
// .. el const indica que el vector no puede modificarse
void show(const vector<string>& strings) {
    // Este tipo de lazo 'for' puede leerse de esta manera
    // Para todo elemento 's' de la coleccion 'strings', hacer .. (lo que hace el bloque)
    // Funciona para varios tipos de colecciones en C++
    for (string s: strings) {
        // No olviden aplicar el método c_str() al imprimir una variable de tipo string usando '%s'
        fprintf(stdout, "%s\n", s.c_str());
    }
}

// Comandos sugeridos para probar el programa:
//  ./test 32
//  ./test 128 | less
// En el caso del segundo comando, pueden ver una pantalla completa de nombres a la vez!
// Denle a la barra espaciadora para ver la siguiente pantalla!
// Acaban de ver un ejemplo de 'pipelining' '|' combinado con el comando 'less'
// Pueden imaginarse el 'pipelining' como una cadena de montaje

int main(int argc, const char *argv[]) {
    // El comando del usuario debe tener 2 elementos:
    // nombre del archivo a ejecutar y el número de nombres a generar.
    // Por lo tanto, si argc es distinto de 2, hay que ..
    if (argc != 2) {
        // .. reportar mal uso del programa y ..
        fprintf(stderr, "uso: %s n - donde n es el número de nombres a generar\n", argv[0]);
        // .. retornar un código de falla (típicamente 1 o 2) al sistema de operación.
        return EXIT_FAILURE;
    }

    // Ahora si: aqui vamos con los 4 pasos obvios:
    int n = atoi(argv[1]); // 1. obtener el valor de n a partir del comando del usuario
    vector<string> names = generate_names(n); // 2. generar los nombres
    show(names); // 3. mostrar los nombres
    return EXIT_SUCCESS; // 4. salir del programa con el código de exito (que es 0)
}
