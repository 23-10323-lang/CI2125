///
/// map.cxx
///

#include "map.h"

#include <vector>
#include <string>

using std::string;
using std::vector;

vector<T> map(T mapper(E element), const vector<E>& input) {
    vector<T> result;
    const int n = input.size();
    result.reserve(n);
    for (E elem: input) {
        T x = mapper(elem);
        result.push_back(x);
    }
    return result;
}

R reduce(R reducer(const vector<T>& input), const vector<T>& input) {
    return reducer(input);
}

///
/// Mostrar datos de entrada y resultados
///

void show(const vector<E>& vec, const char *specifier, const char *label) {
    string format = string("%4d: ") + specifier + "\n";
    const int n = vec.size();
    fprintf(stdout, "\n%s:\n", label);
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, format.c_str(), i, vec[i]);
    }
}

void show_map(const vector<E>& in, const char *ispec, const vector<T>& out, const char *ospec, const char *label) {
    string format = string("%4d: ") + ispec + " => " + ospec + "\n";
    const int n = in.size();
    fprintf(stdout, "\n%s:\n", label);
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, format.c_str(), i, in[i], out[i]);
    }
}
