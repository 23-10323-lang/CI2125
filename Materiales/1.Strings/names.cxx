///
///
///

#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> ffirst = {
    "Alicia",
    "Beatriz",
    "Cecilia",
    "Diana",
    "Erica"
    "F",
    "G",
    "H",
    "I",
    "J",
    "Kayla",
    "Lucia",
    "Monica",
    "N",
    "Olga",
    "Patricia",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "Victoria",
    "Wanda",
    "X",
    "Y",
    "Zoila"
};

vector<string> mfirst = {
    "Andres",
    "B",
    "Carlos",
    "David",
    "E"
    "F",
    "G",
    "H",
    "Ignacio",
    "Javier",
    "K",
    "Luis",
    "Mauricio",
    "N",
    "O",
    "Pedro",
    "Q",
    "Roberto",
    "S",
    "T",
    "U",
    "Victor",
    "Walter",
    "Xavier",
    "Y",
    "Zoila"
};

vector<string> last = {
    "Alvarado",
    "B",
    "C",
    "D",
    "Echeverria",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "Montoya",
    "N",
    "Ordoñez",
    "Peña",
    "Q",
    "R",
    "Sanchez",
    "Torres",
    "U",
    "V",
    "Weiss",
    "Xavi",
    "Yanez",
    "Zamora"
};

void run() {
    for (auto f: first) {
        for (auto l: last) {
            fprintf(stdout, "%s %s\n", f.c_str(), l.c_str());
        }
    }
}

int main() {
    run();
    return 0;
}
