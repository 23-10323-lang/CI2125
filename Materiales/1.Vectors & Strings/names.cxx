///
/// strings
///

#include <cstdlib>
#include <string>
#include <vector>

using std::string;
using std::vector;

int random_index(int n) {
    return rand() % n;        
}

vector<string> ffirst = {
    "Alicia",
    "Beatriz",
    "Cecilia",
    "Diana",
    "Erica",
    "Fernanda",
    "Graciela",
    "Hannah",
    "Irina",
    "Julia",
    "Kayla",
    "Lucia",
    "Monica",
    "Noelia",
    "Olga",
    "Patricia",
    "Quimera",
    "Raquel",
    "Susana",
    "Tatiana",
    "Ursula",
    "Victoria",
    "Wanda",
    "Xena",
    "Yolanda",
    "Zoila"
};

vector<string> mfirst = {
    "Andres",
    "Bruno",
    "Carlos",
    "David",
    "Ernesto"
    "Francisco",
    "Gabriel",
    "Héctor",
    "Ignacio",
    "Javier",
    "Kurt",
    "Luis",
    "Mauricio",
    "Néstor",
    "Oscar",
    "Pedro",
    "Quirino",
    "Roberto",
    "Samuel",
    "Tomás",
    "Ulises",
    "Victor",
    "Walter",
    "Xavier",
    "Yannick",
    "Zoila"
};

vector<string> last = {
    "Alvarado",
    "Brito",
    "Campos",
    "Domínguez",
    "Echeverria",
    "Fuentes",
    "Gil",
    "Hernández",
    "Iriarte",
    "Jiménez",
    "Koch",
    "León",
    "Montoya",
    "Navarro",
    "Ordoñez",
    "Peña",
    "Quevedo",
    "Ruiz",
    "Sanchez",
    "Torres",
    "Uribe",
    "Villegas",
    "Weber",
    "Xu",
    "Yanez",
    "Zamora"
};

string generate_name() {
    int f_index = random_index(ffirst.size());
    int l_index = random_index(last.size());
    string full_name = ffirst[f_index] + " " + last[l_index];
    return full_name;
}

void run(int n) {
    for (int i = 0; i < n; ++i) {
        string full_name = generate_name();
        fprintf(stdout, "%s\n", full_name.c_str());
    }
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "uso: %s n (para 0 < n < 128)\n", argv[0]);
        return 2;
    }
    int n = atoi(argv[1]);
    run(n);
    return 0;
}
