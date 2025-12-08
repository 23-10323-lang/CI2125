///
/// main.cxx
///

#include <cstdio>
#include <string>
#include <vector>

using std::string;
using std::vector;

// activa el lenguaje Español
const bool spanish = true;

int run(const vector<string>& args) {
    fprintf(stdout, "%s (C++ std::string) :\n", spanish ? "argumentos" : "arguments");
    int n = args.size(); // obtenemos el numero de elemntos de args y lo guardammos en la variable n
    for (int i = 0; i < n; i = i + 1) {
        string s = args[i];
        fprintf(stdout, "%d: %s\n", i++, s.c_str());
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    fprintf(stdout, "%s (C strings - const char *) :\n", spanish ? "argumentos" : "arguments");

    // vector para almacenar los argumentos
    vector<string> args = {};
    for (int i = 0; i < argc; i = i + 1) {
        const char *s = argv[i];
        fprintf(stdout, "%d: %s\n", i, s);
        string str = string(s);
        args.push_back(str);
    }
    int status = run(args);
    return status;
}
