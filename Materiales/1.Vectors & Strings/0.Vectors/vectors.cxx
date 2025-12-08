///
/// vectors
///
/// ejemplos usando arreglos y vectores
///

#include <cstdio>
#include <vector>

using std::vector;

// ejemplo que define la variable 'arr' como un arreglo nativo ("desnudo") de números
// en este caso los números (i.e. los elementos de 'arr') son de tipo 'double'
// double: punto flotante de double precisión (64 bits)
double arr[] = {
    0.0,
    2.718281828459,
    3.141592653589
};

// ejemplo que define la variable 'vec' como un vector de números de tipo 'double'
vector<double> vec = {
    0.0,
    2.718281828459,
    3.141592653589,
    9.99
};

// ejemplo que define la variable 'vec' como un vector de números de tipo 'double'
int lottery[] = {
    12,
    88,
    67,
    16,
    42
};

// esta función muestra un arreglo en la pantalla
// sólo funciona para arreglos con elementos de tipo double
// el parámetro 'n' indica el tamaño del arreglo (C/C++ no puede determinarlo)
// la función no retorna un valor ('void' significa vacio)
void show_array_double(int n, double a[]) {
    fprintf(stdout, "[\n");
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "\t%d: %f\n", i, a[i]);
    }
    fprintf(stdout, "]\n");
}

// esta función muestra un vector en la pantalla
// sólo funciona para vectores con elementos de tipo double
// la función no retorna un valor ('void' significa vacio)
void show_vector_double(const vector<double>& v) {
    int n = v.size(); // el método 'size' de la clase vector retorna el número de elementos en el vector
    fprintf(stdout, "[\n");
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "\t%d: %f\n", i, v[i]);
    }
    fprintf(stdout, "]\n");
}

// esta función muestra un arreglo en la pantalla
// sólo funciona para vectores con elementos de tipo int (enteros)
// el parámetro 'n' indica el tamaño del arreglo (C/C++ no puede determinarlo)
// la función no retorna un valor ('void' significa vacio)
void show_array_int(int n, int a[]) {
    // implementar como ejercicio !!
}

int main() {
    // muestra arr
    int m = sizeof(arr)/sizeof(arr[0]);
    fprintf(stdout, "\n<<< double arr[] >>>\n");
    show_array_double(m, arr);
    
    // muestra vec
    fprintf(stdout, "\n<<< vector<double> vec >>>\n");
    show_vector_double(vec);

    // muestra los números de la lotería
    int n = 0;
    show_array_int(n, lottery);
    return 0;
}
