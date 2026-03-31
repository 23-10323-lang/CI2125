///
/// main.cxx
///
/// Programa principal
///
/// Ejemplos de uso:
/// ./test --help
/// ./test
/// ./test 8 32
/// ./test 8 32 74
///

#include "main.h"
#include "macondian.h"
#include "rand997.h"

#include <cstdio>
#include <string>

using std::string;
using std::vector;

MacondianSensor Yushan() {
    return MacondianSensor(6); // Yushan tiene 6 micro-sensores
}

MacondianSensor Lhotse() {
    return MacondianSensor(8); // Lhotse tiene 8 micro-sensores
}

// Inicialización del sistema
Sensors initialize(int n) {
    start(n);
    Sensors sensors = {};
    for (int i = 0; i < n; ++i) {
        sensors.push_back(rand997() < 0.5 ? Yushan() : Lhotse());
    }
    return sensors;   
}

// Simulación del sistema
void simulate(int B, Sensors& sensors) {
    for (int b = 0; b < B; ++b) {
        const double macondian_anomaly = 64.0 + 0.1 * (1 - 2 * rand997());
        for (auto& sensor: sensors) {
            const double macondian_mass = rand997();
            const double macondian_spin = rand997();
            double x = 2.0 + 0.25 * Box(macondian_mass, macondian_spin);
            double nf = sensor.size() / macondian_anomaly;
            for (auto& mini: sensor) {
                const double macondian_x = rand997();
                const double macondian_y = rand997();
                mini = x + nf * Mueller(macondian_x, macondian_y);
            }
        }
        batch(sensors);
    }
}

void report() {
    const Result& result = final();
    size_t N = result.size();
    fprintf(stdout, "==========================\n");
    fprintf(stdout, "Reporte final: %2zu sensores\n", N);
    for (size_t i = 0; i < N; ++i) {
        fprintf(stdout, "Macondian %2zu: [", i);
        const MacondianSeries& series = result[i];
        for (double macondos: series) {
            fprintf(stdout, "%7.3f", macondos);
        }
        fprintf(stdout, "]\n");
    }
    fprintf(stdout, "==========================\n");
}

int main(int argc, const char *argv[]) {
    if (4 < argc || 1 < argc && string(argv[1]) == "--help") {
        fprintf(stderr, "Uso: %s [<N>] [<B>] [<S>]\n", argv[0]);
        fprintf(stderr, "<N>: número de sensores (por defecto %d)\n", DEFAULT_N);
        fprintf(stderr, "<B>: número de batches (por defecto %d)\n", DEFAULT_B);
        fprintf(stderr, "<S>: semilla inicial (por defecto %d)\n", DEFAULT_S);
        return EXIT_FAILURE;
    }
    const unsigned int N = argc < 2 ?  DEFAULT_N : atoi(argv[1]);
    const unsigned int B = argc < 3 ?  DEFAULT_B : atoi(argv[2]);
    const unsigned int S = argc < 4 ?  DEFAULT_S : atol(argv[3]);

    // PRNG initialization | inicialización del generador de números pseudo-aleatorios
    seed(S);

    // Inicialización del sistema
    Sensors sensors = initialize(N);

    // Simulación del sistema
    simulate(B, sensors);

    // Reporte de los resultados finales
    report();

    return EXIT_SUCCESS;
}
