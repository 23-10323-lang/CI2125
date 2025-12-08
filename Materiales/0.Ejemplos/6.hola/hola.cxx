///
/// hola.cxx
///
/// Ejercicio: completar el programa
///

#include <stdio.h>

int main(int argc, const char *argv[])
{
  if (argc == 1) {
    // ... imprimir "Hola!"
  } else if (argc == 2) {
    // ... imprimir "Hola <nombre>!"
  } else {
    fprintf(stderr, "uso: %s [<nombre>]\n", argv[0]);
    return 1;
  }
  return 0;
}
