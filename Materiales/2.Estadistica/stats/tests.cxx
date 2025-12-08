///
/// tests.cxx
///

#include "stats.h"

#include <cstdio>
#include <string>
#include <vector>

using std::string;
using std::vector;

const bool debug = false;

vector<double> random_data(int n, double lb, double ub) {
    vector<double> data(n);
    for (int i = 0; i < n; ++i) {
        double x = (ub - lb) * uniform() + lb;
        data[i] = x;
    }
    return data;
}

bool test(int n, double lb, double ub) {
    vector<double> data = random_data(n, lb, ub);
    if (n <= 10) {
        for (auto x: data) {
            fprintf(stdout, "%f\n", x);
        }
    }
    double avg = average(data);
    double vrp = varp(data);
    double vrc = varp_c(data);
    fprintf(stdout, "%f %f %f\n", avg, vrp, vrc);
    return true;
}

int run(const vector<string>& args) {
    if (args.size() != 4) {
        string name = args[0].c_str();
        fprintf(stderr, "Uso correcto: %s <n> <lb> <ub>\n", name.c_str());
        fprintf(stderr, "\tn:  número de elementos a generar\n");
        fprintf(stderr, "\tlb:  (lower bound) limite inferior\n");
        fprintf(stderr, "\tub:  (lower bound) limite superior\n");
        fprintf(stderr, "%s genera <n> valores x, tales que <lb> <= x < <ub>\n", name.c_str());
        fprintf(stderr, "Los valores generados son retornados en un arreglo\n");
        return EXIT_FAILURE;
    }
    int n = atoi(args[1].c_str());
    double lb = atof(args[2].c_str());
    double ub = atof(args[3].c_str());
    bool status = test(n, lb, ub);
    return status ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(const int argc, const char *const argv[]) {
    // vector para almacenar los argumentos
    vector<string> args = {};
    for (int i = 0; i < argc; ++i) {
        const char *s = argv[i];
        if (debug) {
            fprintf(stdout, "argv[%2d]: %s\n", i, s);
        }
        args.push_back(s);
    }
    int status = run(args);
    return status;
}
