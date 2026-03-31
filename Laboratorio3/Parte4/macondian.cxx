///
/// macondian.cxx
///

#include "macondian.h"

#include <cstdio>
#include <vector>

using std::vector;

// Valor recomendado para el radio de tolerancia Macondiano
// Pueden recalibrar el valor a su antojo pero deben preservar al nombre
// Los encargados del control de calidad pueden y van a usar otros valores
// Código bien diseñado deberia funcionar bien para distintas tolerancias
const double macondian_tolerance = 0.2;

// IMPORTANTE:
// Aqui es donde deben acumular el resultado durante el procesamientos
static Result result = {};

// Esta función esta lista - no la cambien
// Inicializa el vector de resultados (vector<MacondianSeries>)
void start(int n) {
    result.resize(n);
}

// Esta función es un "regalo" para ayudarles a ver los datos de entrada
// no debe utilizarse en la tarea
static void chequeo(const Sensors& sensors) {
    fprintf(stdout, "-------- new batch --------\n");
    int i = 0;
    for (const auto& sensor: sensors) {
        fprintf(stdout, "\tMacondian %2d [ ", i);
        for (auto micro: sensor) {
            fprintf(stdout, "%7.3f ", micro);
        }
        fprintf(stdout, "]\n");
        ++i;
    }
}

// @@IMPLEMENTAR: Esta es la función que deben implementar 
// Procesa una carga (batch) de datos de todos los sensores Macondianos
void batch(const Sensors& sensors) {
    // IMPORTANTE: quiten el comentario delante de 'chequeo(sensors)' si quieren ver la entrada.
    // Pero vuelvan a poner el comentario o quiten el chequeo completamente, antes de entrgar la tarea.
    chequeo(sensors);
}

// Esta función retorna el resultado - ya está lista
const Result& final() {
    return result;
}
