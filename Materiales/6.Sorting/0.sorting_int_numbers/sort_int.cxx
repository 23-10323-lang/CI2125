///
/// sort_int.cxx
///
/// Definición de la función que implementa el algoritmo de ordenamiento
///

#include "sort_int.h"

#include <cstdio>
#include <cstdlib>

using std::vector;

// min
//
// Synopsis: consigue el índice del menor elemento en un subrango de un vector
//
// Parámetros:
// int lb: (lower bound) el índice de comienzo del rango
// int ub: (upper bound) el índice que marca el fin del rango - NO es parte del rango
// const vector<T>& data: referencia al vector de elementos de tipo T
//
// Valor retornado :
// el índice del menor elemento en el subrango data[lb .. <ub], donde <ub indica que ub está excluido
//
// Notas:
// - la referencia es a un vector constante (const vector) ya que min no modifica el vector
// - min funciona con cualquier vector de elementos de tipo T, siempre y cuando ..
// .. los valores de tipo T puedan ser completamente ordenados
int min(int lb, int ub, const vector<int>& data) {
    // obtenemos el tamaño del vector
    const int n = data.size();

    //
    // Chequeo de precondiciones
    //

    // si el vector es vacio, no puede tener un elemento mínimo
    if (n == 0) {
        return -1; // retornamos un índice negativo, para indicar error
    }
    // el comienzo del rango no puede ser negativo o salirse del limite superior
    if (lb < 0 || lb >= ub) {
        return -1;
    }
    // si lo anterior se cumple, pero el límite superior se sale del rango del vector ..
    if (ub > n) {
        return -1; // .. podemos indicar error o .. (pueden escoger el que prefieran)
        // ub = n; // .. ajustar el límite superior (este es un 'hack" que funciona)
    }

    // Algo "divertido" ..
    // Si analizan el programa completo, pueden darse cuenta que los casos anteriores no ocurren.
    // Entonces .. ¿Porqué chequear condiciones que no pueden ocurrir?
    // 1. cambios al resto del programa pueden violar las condiciones, pero min va a pillar el error
    // 2. la función min podría ser reusada en programas que no garantizan eses las condiciones
    // Una respuesta única sería: "para que la correctitud de min no dependa del entorno."
    // Nota: el caso 2 implica que la función no es privada: está disponible a traves de una interfaz ..
    // .. a menos que el reuso consiste en "copiar y pegar": de ser asi, es una variante del caso 1.
    // Por razones de eficiencia, algunas funciones no chequean sus pre-condiciones de correctitud.
    // En otras palabras, cumplir las pre-condiciones es responsabilidad del codigo que llama la función.
    // Sin embargo, en ese caso, los buenos programadores profesionales hacen lo siguiente:
    // A) documentan en el encabezado las precondiciones que deben cumplirse al llamar a la función, y ..
    // B) (bonus points) implementan una versión de prueba y una versión eficiente de la función.
    // La versión de prueba es usada durante el desarrollo y cada vez que se hacen cambios al programa.
    // De esta manera, mediante pruebas empíricas, es posible pillar errores en el programa.
    // Si el programa satisface las pruebas, podemos aceptar el riesgo de usar la versión rápida, pero ..
    // recuerden: "las pruebas empíricas solo pueden conseguir errores, no garantizar su ausencia" [Dijkstra]
    // Este es uno de los "trade-offs" (dilemas/compromisos) más importantes en la ingeniería de software.

    // Sorpresas te da' la vida, ¿no?
    // Acaban de tener una leccion de ingeniería gratis .. y no solo ingeniería de software
    
    // Lo anterior aplica (mutatis mutandis) a ingeniería electrónica, eléctrica, y hasta mecánica.
    // De hecho, he visto ejemplos de las tres, *juntas* (!), en el desarrollo de nun sistema RAID.
    // (https://en.wikipedia.org/wiki/RAID) y el CTO de la compañia era un profesor de la USB.

    // Por fin, aqui tenemos el algoritmo para conseguir el índice del menor elemento en un rango.

    int mindex = lb; // minindex (min index: el índice del menor elemento) se inicializa con lb
    int minimum = data[mindex]; // lo cual equivale a decir que (tentativamente) el primer elemento es el menor

    for (int i = lb + 1; i < ub; ++i) {
        // si el i-esimo elemento es menor que el "mínimo" que teniamos hasta la fecha ..
        if (data[i] < minimum) {
            mindex = i; // el nuevo índice del mínimo es i ..
            minimum = data[mindex]; // y el nuevo mínimo es data[i] que puede escribirse data[mindex]

            // Hacerlo en ese orden hace evidente este invariante: minimum es igual a data[mindex]
            // .. comparen la linea 88 con la inicializacion de minimum en la linea 82 .. ¿cool no?
            // Expertos en C/C++ a menudo escriben lo anterior asi: minimum = data[mindex = i];
            // Pero no tengo tiempo para explicar lo anterior (y posibles pifias) en detalle
        }
    }
    // convénzanse que al salir del lazo (aqui), minindex es a juro el índice del menor elemento
    // también noten que el vector no fué alterado
    return mindex;
}

// min
//
// Synopsis: consigue el índice del menor elemento de un vector
//
// Esta función no esta siendo usada en este programa.
// La puse para que vean la correspondencia (de hecho se encarama) con la anterior
// Lo que permite usar el *mismo* nombre para esta función es el concepto de "overloading":
// la capacidad de ciertos lenguajes de distinguir funciones dado el tipo de sus argumentos.
// Casi todos los lenguajes tienen algo de "overloading", particularmente con operadores
int min(const vector<int>& data) {
    const int n = data.size();
    int index = min(0, n, data);
    if (index < 0) {
        exit(EXIT_FAILURE);
    }
    return index;
}

// selection_sort ordena un vector usando el algoritmo llamado: selection sort
// Que podemos traducir como: ordenamiento por selección.
// En vez de describirlo aqui en lenguaje natural, que no es tan dificil, ..
// Uds. deben analizar (i.e. correr en frio, en su mente) su comportamiento en detalle.
// Esto es clave para desarrollar el pensamiento computacional: sin esfuerzo no hay aprendizaje.
// Si lo hacen bien se convenzerán que el algoritmo ordena.
void selection_sort(vector<int>& data) {
    const int n = data.size();
    if (n == 0) {
        return; // nada que hacer: ¡los elementos de toda colección vacía están ordenados!
    }

    for (int i = 0; i < n-1; ++i) {

        // usando la función min, obtenemos el índice del menor elemento en el rango data[i .. <n]
        int mindex = min(i, n, data);

        // (swap) intercambiamos data[i] con data[mindex], usando una variable temporal (tmp)
        // las llaves abajo no son necesarias, pero ayudan a separar visualmente el intercambio ..
        // .. y a enfatizar que el alcance de la variable temporal se limita al bloque del intercambio.
        {
            // swap data[i] <-> data[mindex]
            int tmp = data[i];
            data[i] = data[mindex];
            data[mindex] = tmp;
        }
    }
}
