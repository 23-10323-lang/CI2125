///
/// args.cxx
///
/// Este ejemplo muestra los argumentos argc y argv pasados a main al ejecutar el programa
///

#include <stdio.h>

/*

*/

int main(int argc, const char *argv[])
{
  fprintf(stdout, "argc: %d\n\n", argc);
  for (int i = 0; i < argc; ++i) {
    fprintf(stdout, "argv[%d]: %s\n", i, argv[i]);
  }
}
