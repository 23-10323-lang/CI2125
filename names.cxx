///
/// names.cxx
///
/// Genrador de nombres
///

#include <cstdlib>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Simple implementación de un generador de números enteros aleatorios
// Suficientemente buena para el simple propósito de este módulo
int random_index(int n) {
    return rand() % n;        
}

// Muestra de nombres femeninos
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

// Muestra de nombres masculinos
vector<string> mfirst = {
    "Andres",
    "Bruno",
    "Carlos",
    "David",
    "Ernesto",
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

// Muestra de apellidos
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

// Experimento opcional (no se evalua): agreguen algunos nombres y apellidos adicionales, y preguntense:
// Importa si no los agregan en orden alfabético?
// Importa si los agregan al comienzo o al final?
// Hacen que potencialmente (asumiendo una muestra grande) algunos nombres iniciales no aparezcan?

// Genera un nombre femenino completo con apellido
string generate_female_name() {
    int f_index = random_index(ffirst.size()); // computa el indice del 'primer' nombre (nombre de pila?)
    int m_index = random_index(26); // computa el indice (desplazamiento) de la inicial del nombre intermedio
    int l_index = random_index(last.size()); // computa el indice del apellido
    string full_name = ffirst[f_index] + " " + char('A' + m_index) + ". " + last[l_index];
    return full_name;
}

// Genera un nombre masculino completo con apellido
string generate_male_name() {
    int f_index = random_index(mfirst.size());
    int m_index = random_index(26);
    int l_index = random_index(last.size());
    string full_name = mfirst[f_index] + " " + char('A' + m_index) + ". " + last[l_index];
    return full_name;
}

// Genera los nombres, escogiendo el género de cada uno al azar
// Para simplificarnos la vida, asumimos que el género es binario: (0: femenino, 1: masculino)
vector<string> generate_names(int n) {
    vector<string> names = {};
    for (int i = 0; i < n; ++i) {
        // for simplicity we assume the gender is binary: (0: female, 1: male) :-)
        int gender = random_index(2);
        string full_name = (gender == 0 ? generate_female_name() : generate_male_name());
        names.push_back(full_name);
    }
    return names;
}
