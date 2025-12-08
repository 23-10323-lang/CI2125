///
/// vectorx
///
/// vector example
/// ejemplo de uso de vector
///

#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using std::vector;

vector<double> random_data(int n, double lb, double ub) {
    vector<double> data(n);
    for (int i = 0; i < n; ++i) {
        double x = (ub - lb) * uniform() + lb;
        data[i] = x;
    }
    return data;
}

void show_vector(vector<double> data) {
    vector<double> data = random_data(n, lb, ub);
    for (auto x: data) {
        fprintf(stdout, "%f\n", x);
    }
}
