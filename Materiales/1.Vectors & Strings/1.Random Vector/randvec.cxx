///
/// randvec
///
/// random vector example
/// ejemplo que usa vectores de num
///

#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using std::vector;

// un simple generador de números aleatorios x, tales que 0 <= x <= 1
// otra forma de decir que retorna valores de una distribución unifome estandar
double uniform() {
    double denominator = double(RAND_MAX); // RAND_MAX es una constante entera definida en cstdlib
    double numerator = double(rand()); // rand() retorna un entero aleatorio x tal que 0 <= x <= RAND_MAX
    return numerator / denominator;
}

// random_data retorna un vector con n valores aleatorios
// los valores son sonformes con una distribucion uniforme entre lb (lower bound) y ub (upper bound)
vector<double> random_data(int n, double lb, double ub) {
    vector<double> data;
    for (int i = 0; i < n; ++i) {
        double x = (ub - lb) * uniform() + lb;
        data.push_back(x);
    }
    return data;
}

// muestra los valores de un vector con elementos de tipo double
void show_vector(const vector<double>& data) {
    for (auto x: data) {
        fprintf(stdout, "%f\n", x);
    }
}

int main(int argc, const char *argv[]) {
    if (argc < 2 || 4 < argc) {
        fprintf(stderr, "uso %s <n> <lb>? <ub>?\n", argv[0]);
    }

    int n = atoi(argv[1]);
    double lb = (argc < 3 ? 0.0: atoi(argv[2])); // la cota inferior (lower bound) es 0.0 por defecto
    double ub = (argc < 4 ? 1.0: atoi(argv[3])); // la cota superior (upper bound) es 1.0 por defecto

    // generate vector
    vector<double> data = random_data(n, lb, ub);

    // show vector
    show_vector(data);

    return 0;
}

