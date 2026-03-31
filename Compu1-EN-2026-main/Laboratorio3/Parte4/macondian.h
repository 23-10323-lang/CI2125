///
/// macondian.h
///

#pragma once

#include <vector>

//
// Type definitions
// Definiciones de tipos
//

// MacondianSensor: sensor with multiple (redundant) measurements
// MacondianSensor: sensor con múltiples medidas para redundancia
typedef std::vector<double> MacondianSensor;

// Sensors: type of the set of Macondian sensors in the system
// Sensors: tipo del conjunto de sensores Macondianos en el sistema 
typedef std::vector<MacondianSensor> Sensors;

// MacondianSeries: sequence (time series) of the Macondo measures gathered by the sensor
// MacondianSeries: secuencia (en el tiempo) de las medidas (Macondos) obtenidas por el sensor
typedef std::vector<double> MacondianSeries;

// MacondianSeries: collection of Macondian series
// MacondianSeries: conjunto de las series Macondianas
typedef std::vector<MacondianSeries> Result;

//
// Macondian data processing system interface
// Interfaz del sistema de procesamiento de datos del Macondian
//

// starts the system, reporting n active sensors
// arranca el sistema, reportando n sensores activos
void start(int n);

// receives a measurement batch for processing
// recibe un batch de medidas para procesamiento
void batch(const Sensors& sensors);

// reports final results
// reporta los resultados finales
const Result& final();
