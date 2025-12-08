///
/// base.cxx
///
/// base tipes | primitive types
/// tipos básicos | tipos primitivos
///

#include <math.h>
#include <stdio.h>
#include <string>

using std::string;

// wait_for_user:
// esta función detiene la ejecución del programa,
// esperando que el usuario presione la tecla Enter (retorno)
// El tipo "void" significa que la función no retorna ningun valor
// su utilidad es precisamente la de parar el programa
void wait_for_user() {
  fprintf(stdout, "Hit <Enter> to continue ...");
  getchar();
}

// test_int:
// prueba valores de tipo entero
int test_int() {
  fprintf(stdout, "test integer values\n");
  const int tres = 3;
  const int mil = 1000;

  fprintf(stdout, "%s: %d\n", "tres", tres);
  fprintf(stdout, "%s: %d\n", "mil", mil);
  fprintf(stdout, "%s: %d\n", "tres * mil + tres", tres * mil + tres);
  fprintf(stdout, "%s: %d\n", "3 * 1000 + 3", tres * mil + tres);
  fprintf(stdout, "\n");
  
  wait_for_user();
  return 0;
}

// test_fp:
// prueba valores de tipo punto flotante
// las representaciones de punto flotante se usan para aproximar números reales
// El estándar IEEE 754 (https://en.wikipedia.org/wiki/IEEE_754) incluye dos representaciones
// 'float' (simple precisión) usa 32 bits: 1 para el signo,  8 para el exponente, 23 para la mantisa
// 'double' (doble precisión) usa 64 bits: 1 para el signo, 11 para el exponente, 52 para la mantisa
int test_fp() {
  fprintf(stdout, "test floating point values\n");
  const float pi_sp = M_PI; // single precision / simple precisión
  const double pi_dp = M_PI; // double precision / doble precisión
  fprintf(stdout, "%s: %4.2f\n", "pi (sp)", pi_sp);
  fprintf(stdout, "%s: %4.2f\n", "pi (dp)", pi_dp);

  fprintf(stdout, "%s: %6.4f\n", "pi (sp)", pi_sp);
  fprintf(stdout, "%s: %6.4f\n", "pi (dp)", pi_dp);

  fprintf(stdout, "%s: %8.6f\n", "pi (sp)", pi_sp);
  fprintf(stdout, "%s: %8.6f\n", "pi (dp)", pi_dp);

  fprintf(stdout, "%s: %10.8f\n", "pi (sp)", pi_sp);
  fprintf(stdout, "%s: %10.8f\n", "pi (dp)", pi_dp);

  fprintf(stdout, "%s: %11.9f\n", "pi (sp)", pi_sp);
  fprintf(stdout, "%s: %11.9f\n", "pi (dp)", pi_dp);

  fprintf(stdout, "%s: %12.10f\n", "pi (sp)", pi_sp);
  fprintf(stdout, "%s: %12.10f\n", "pi (dp)", pi_dp);

  fprintf(stdout, "\n");

  // area of a circle of radius 1000
  // área de un círculo de radio 1000

  const float  big_circle_area_sp = M_PI * (1000 * 1000);
  const double big_circle_area_dp = M_PI * (1000 * 1000);

  fprintf(stdout, "%s: %12.10f\n", "area big circle (sp)", big_circle_area_sp);
  fprintf(stdout, "%s: %12.10f\n", "area big circle (dp)", big_circle_area_dp);

  fprintf(stdout, "\n");

  // Beware potentially unwanted integer division!
  // ¡Cuidense de hacer divisiones entera no planeadas!

  // seven divided by two using floating point values
  // siete dividido entre dos, usando valores en punto flotante
  // el resultado debe ser 3.5, como pueden ver al correr el programa
  const double div_ff = 7.0 / 2.0;

  // seven divided by two using only integer values
  // siete dividido entre dos, usando sólo valores enteros
  //
  // Nota: en este caso, C computa el cociente entero, que es 3
  const double div_ii = 7 / 2;

  // Para evitar la 'division entera', es decir computar el cociente entero,
  // .. basta que el numerador o el denominador sea de tipo punto flotante
  // Aqui mostramos las 4 combinaciones posibles,
  // dos de ellas usando las expresiones directamente, sin variables

  fprintf(stdout, "%s (7.0 / 2.0) ==> %12.10f\n", "div_ff", div_ff);
  fprintf(stdout, "%s (7.0 /  2 ) ==> %12.10f\n", "div_fi", 7.0 / 2);
  fprintf(stdout, "%s ( 7  / 2.0) ==> %12.10f\n", "div_if", 7 / 2.0);
  fprintf(stdout, "%s ( 7  /  2 ) ==> %12.10f\n", "div_ii", div_ii);

  fprintf(stdout, "\n");

  wait_for_user();
  return 0;
}

// test_cstring:
// test "naked" C strings (const char *)
// prueba cadenas de caracteres (strings) de C "desnudos" (const char *)
int test_cstring() {
  fprintf(stdout, "test old-style (naked) C string values\n");
  const char *alicia = "Alicia";
  const char *javier = "Javier";

  fprintf(stdout, "%s: %s\n", "Alicia", alicia);
  fprintf(stdout, "%s: %s\n", "Javier", javier);
  fprintf(stdout, "\n");

  wait_for_user();
  return 0;
}

// test_string:
// test values of the standard <string> class (C++ std::string)
// prueba valores de la clase estandar <string> (C++ std::string)
int test_string() {
  fprintf(stdout, "test C++ std::string values\n");
  const string alicia = "Alicia";
  const string javier = "Javier";

  // noten el uso del método c_str para obtener el string desnudo
  // que puede ser impreso son el especificador (formateador) %s
  fprintf(stdout, "%s: %s\n", "Alicia", alicia.c_str());
  fprintf(stdout, "%s: %s\n", "Javier", javier.c_str());

  // noten que las instrucciones siguientes son idénticas a las anteriores ..
  // excepto por no usar el método c_str; remuevan el prefijo de comentario (//) y ..
  // vuelvan a correr el programa .. ¡para que vean qué ocurre!

  // fprintf(stdout, "%s: %s\n", "Alicia", alicia);
  // fprintf(stdout, "%s: %s\n", "Javier", javier);

  fprintf(stdout, "\n");

  wait_for_user();
  return 0;
}


// how to display boolean values
// cómo mostrar valores booleanos

// Tenemos variaciones del tema, porque:
// - a veces queremos mostrar esos valores en Español, y a vace en Inglés
// - podemos retornar el resultado como un string denudo o una instancia de la clase std::string
//
// Basándonos en lo anterior:
// ¿Cuantas variaciones (combinaciones) podemos tener para mostrar valores booleanos de manera "bonita"?

//
// bool to ( (const char *) | std::string) X (English | Spanish) )
//
const char *bool_to_cstring_en(bool b) {
  return b ? "true" : "false";
}

const char *bool_to_cstring_sp(bool b) {
  return b ? "verdadero" : "falso";
}

string bool_to_string_en(bool b) {
  return b ? "true" : "false";
}

string bool_to_string_sp(bool b) {
  return b ? "verdadero" : "falso";
}

// test_bool:
// test boolean values
// prueba valores booleanos
int test_bool() {
  fprintf(stdout, "test boolean values\n");

  // breaking tradition, we give names in Spanish to these variables
  // rompiendo la tradición, le damos nombres en Español a estas variables
  const bool falso = false;
  const bool verdadero = true;

  // bool direct (number) | bool directo (número), sin usar conversión a string
  fprintf(stdout, "%s: %d\n", "falso", falso);
  fprintf(stdout, "%s: %d\n", "verdadero", verdadero);

  // using naked C string: bool => English | usando string de C: bool => Inglés
  fprintf(stdout, "%s: %s\n", "falso", bool_to_cstring_en(falso));
  fprintf(stdout, "%s: %s\n", "verdadero", bool_to_cstring_en(verdadero));

  // using naked C string: bool => Spanish | usando string de C: bool => Español
  fprintf(stdout, "%s: %s\n", "falso", bool_to_cstring_sp(falso));
  fprintf(stdout, "%s: %s\n", "verdadero", bool_to_cstring_sp(verdadero));

  // using C++ std::string: bool => English | usando C++ std::string: bool => Inglés
  fprintf(stdout, "%s: %s\n", "falso", bool_to_string_en(falso).c_str());
  fprintf(stdout, "%s: %s\n", "verdadero", bool_to_string_en(verdadero).c_str());

  // using C++ std::string: bool => Spanish | usando C++ std::string: bool => Español
  fprintf(stdout, "%s: %s\n", "falso", bool_to_string_sp(falso).c_str());
  fprintf(stdout, "%s: %s\n", "verdadero", bool_to_string_sp(verdadero).c_str());

  // Horror: vean qué pasa si omitimos el metodo c_str, como hicimos en 'test_string'
  // fprintf(stdout, "%s: %s\n", "falso", bool_to_string_en(falso));
  // fprintf(stdout, "%s: %s\n", "verdadero", bool_to_string_en(verdadero));

  fprintf(stdout, "\n");

  wait_for_user();
  return 0;
}

// test_char:
// test char values
// prueba de caracteres
int test_char() {
  fprintf(stdout, "test character values\n");

  // Los caracteres son representados con números enteros de 1 byte (8 dígitos binarios)
  // Pueden conseguir tablas de ASCII en la Web. Aqui tienen una buena:
  // https://img.sysnettechsolutions.com/What-is-ASCII-Nedir-01.webp

  // Para denotar un caracter, se le pone entre comillas simples; por ejemplo 'x'
  // En el formato del fprintf, pueden imprimir el caracter usando %c, y ..
  // el codigo ASCII del mismo con %d

  const char a = 97;  // el código ASCII del caracter 'a' es 97: 'a' == 97
  const char b = 'b'; // el código ASCII del caracter 'b' es 98: 'b' == 98
  fprintf(stdout, "%s: %c\n", "a", a);
  fprintf(stdout, "%s: %d\n", "a", a);
  fprintf(stdout, "%s: %c\n", "b", b);
  fprintf(stdout, "%s: %d\n", "b", b);
  fprintf(stdout, "%s: %c\n", "c", 'c'); // imprime el caracter 'c'
  fprintf(stdout, "%s: %d\n", "c", 'c'); // imprime código ASCII de 'c'

  wait_for_user();
  return 0;
}

int main()
{
  fprintf(stdout, "Hello, Test!\n\n");
  // El operador += se interpreta de esta manera
  // 'x += y' es equivalente a 'x = x + y'
  // siempre y cuando la evaluación de 'x' es pura,
  // es decir que no cambia el estado de la máquina.
  int status = 0;
  status += test_int();
  status += test_fp();
  status += test_cstring();
  status += test_string();
  status += test_bool();
  status += test_char();
  return status;
}
