///
/// de1aN.cxx
///
/// programa que cuenta de 1 a N
///
/// Ejercicio: corregir y completar el programa para hacerlo robusto (Windows y Linux)
///

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  // obtener el valor de N a partir del argumento
  int N = atoi(argv[1]);

  // contar de 1 a N
  int i = 1;
  while (i <= N) {
    fprintf(stdout, "%d\n", i);
    i = i + 1;
  }

  return 0;
}
