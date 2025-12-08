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
    fprintf(stdout, "%s:\n", spanish ? "argumentos" : "arguments");
    int i = 0;
    for (string s: args) {
        fprintf(stdout, "%2d: %s\n", i++, s.c_str());
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    // vector para almacenar los argumentos
    vector<string> args = {};
    for (int i = 0; i < argc; ++i) {
        const char *s = argv[i];
        fprintf(stdout, "%2d: %s\n", i, s);
        args.push_back(s);
    }
    int status = run(args);
    return status;
}
