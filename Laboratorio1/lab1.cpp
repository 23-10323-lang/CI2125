///
/// arreglos
///

#include <cstdio>
#include <cmath>

// vector de origen en 4 dimensiones
double o[] = { 0.0, 0.0, 0.0, 0.0 };

double a[] = { 1.0, 1.0, 1.0, 1.0 };
double b[] = { 2.2, 0.0, 1.1, 3.3 };

double x[] = { 1.0, 2.1, 3.0, 5.1, 2.0, 0.0, 6.2, 7.3 };

const int No = sizeof(o) / sizeof(o[0]);
const int Nx = sizeof(x) / sizeof(x[0]);

// La distancia euclidiana entre dos puntos, en un espacio de 'n' dimensiones,
// es la raiz cuadrada de la suma de los cuadrados de las 'n' diferencias
// de las coordenadas correspondientes de esos puntos
// https://es.wikipedia.org/wiki/Distancia_euclidiana

// 'distance': computa la distancia euclidiana de dos vectores de 'n' dimensiones
// 'n': número de dimensiones
// 'v': vector de 'n' dimensiones
// 'w': otro vector de 'n' dimensiones
// la función retorna la distancia euclidiana entre 'v' y 'w'
double distance(int n, double v[], double w[]) {
    double result;
    return result;
}


// 'vec_sum': calcula la suma de dos vectores de 'n' dimensiones
// asumimos que ya conocen la definición de la suma de dos vectores
// Parámetros:
// 'n': número de dimensiones
// 'v': vector de 'n' dimensiones
// 'w': otro vector de 'n' dimensiones
// 'r': vector de la suma de 'v' y 'w' (con memoria ya reservada para 'n' dimensiones)
// la función retorna el resultado en 'r'
void vec_sum(int n, double v[], double w[], double r[]) {
}

// 'show' muestra un vector 'v', de 'n' dimensiones, en la pantalla
// 'n': número de dimensiones
// 'v': vector de 'n' dimensiones
// 'sep': separador para mejorar la salida
void show(int n, double v[], const char *sep) {
    fprintf(stdout, "[ ");
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "%f%s", v[i], sep);
    }
    fprintf(stdout, " ]\n");
}

// 'min' retorna el índice del menor valor en un subrango de un arreglo
// 'i': índice del comienzo del subrango (incluido)
// 'n': índice del final del subrango (excluido)
// 'a': arreglo con los datos
// la función retorna el índice del menor valor en el subrango [ a[i] .. a[n] )
int min(int i, int n, double a[]) {
    double min;
    return min;
}

// 'copy_array': copia un arreglo a otro
// 'n', tamaño del arreglo
// 'a', arreglo con datos
// 'r', arreglo para almacenar la copia (con memoria ya reservada para 'n' elementos)
// la función retorna el resultado (la copia de 'a') en 'r'
void copy_array(int n, double a[], double r[]) {
    for (int i = 0; i < n; ++i) {
        r[i] = a[i];
    }
}

// 'sort': ordena un arreglo 'a', de tamaño 'n' dejando el resultado en otro arreglo
// 'n', tamaño del arreglo
// 'a', arreglo con datos
// 'r', arreglo para almacenar la resultado (con memoria ya reservada para 'n' elementos)
// la función retorna el arreglo ordenado en 'r'
void sort(const int n, double a[], double r[]) {
    // @@@ completar usando el algoritmo aqui descrito @@@

    // 1. conseguir el valor minimo en todo el arreglo 'r', es decir en el rango 'r[0]' .. 'r[n-1]'
    // recuerden: los índices válidos del arreglo van de 0 a 'n' excluido
    // por eso lo típico es iterar como lo hacemo en 'show': 'for (int l = 0; l < n; ++l)'
    // 2. sea 'k' el indice del valor minimo: intercambie 'r[0]' con 'r[k]'
    // ahora el valor minimo de 'r' esta en 'r[0]' y se va a quedar alli para siempre.
    // Repetir 1 y 2 *pero* en el rango r[1] .. r[n-1], es decir los indices de 1 a n excluido
    // e intercambiando el valor minimo en ese rango con 'r[1]', lógicamente.
    // Y asi sucesivamente
}

// Lo mismo que `sort`, solo que usando inteligencia artificial.
// Indiquen en un comentario cual inteligencia artificial usaron.
// Indiquen en un comentario si les dio algun insight que consideren valioso.
void sort_AI(const int n, double a[], double r[]) {
}

// recomendamos que escriban sus propias pruebas
// los preparadores van a probar su código.
void test_distance() {
    fprintf(stdout, "test_distance\n");

    double ao = distance(No, a, o);
    fprintf(stdout, "a <-> o ==> %f\n", ao);

    double bo = distance(No, b, o);
    fprintf(stdout, "b <-> o ==> %f\n", bo);

    double ab = distance(No, a, b);
    fprintf(stdout, "a <-> b ==> %f\n", ab);

    double ba = distance(No, b, a);
    fprintf(stdout, "b <-> a ==> %f\n", ba);
}

void test_vec_sum() {
    fprintf(stdout, "test_vec_sum\n");
    double r[No];

    vec_sum(No, a, b, r); show(No, r, " ");
    vec_sum(No, a, o, r); show(No, r, " ");
    vec_sum(No, o, b, r); show(No, r, " ");
    vec_sum(No, b, a, r); show(No, r, " ");
}

void test_sort() {
    fprintf(stdout, "test_sort\n");
    // aqui reservamos memoria para almacenar el resultado de ordenar a x
    double r[Nx];
    sort(Nx, x, r);
    show(Nx, x, " ");
    show(Nx, r, " ");
}

int main(int argc, const char *argv[]) {
    test_distance();
    test_vec_sum();
    test_sort();
    return 0;
}
