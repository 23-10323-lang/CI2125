///
/// Zilly in C++
///
/// A partial emulation of Zilly in C++, with sample usage
///

#include <cstdio>

/// Zilly Emulator | Emulador de Zilly

typedef int Z;

/// Zilly primitive functions | Funciones primitivas de Zilly

// less than | menor que
Z lt(Z n, Z k) {
    // return k < n;
    return k < n ? 1 : 0;
}

// subtract | resta
Z sub(Z n, Z k) {
    return k - n;
}

///
/// Programmer defined functions | Funciones definidas por el programador
/// De aqui en adelante, todal las definiciones deben hacerse usando las primitivas ..
/// .. o funciones que derivaron anteriormente a partir de las primitivas.
///

// Change sign | Cambio de signo (negativo <=> positivo) es decir .. negación
Z chs(Z n) {
    // return -n;
    // -n es 0 - n, que en Zilly es sub(n, 0)
    return sub(n, 0); // <== @@@ TAREA: ¡cambiar esto para que haga lo correcto!
}

// Add | Suma
Z add(Z n, Z k) {
    // return n + k;
    // n + k es k - (-n).
    // -n es chs(n)
    // k - chs(n) es sub(chs(n), k)
    return sub(chs(n), k); // <== @@@ TAREA: ¡cambiar esto para que haga lo correcto!
}

// Less or equal to | Menor o igual a
Z le(Z n, Z k) {
    // return k <= n;
    // k <= n es lo mismo que NO (n < k)
    // n < k es lt(k, n)
    // NO (x) se puede implementar como 1 - x (ya que x es 0 o 1)
    // 1 - lt(k, n) es sub(lt(k, n), 1)
    return sub(lt(k, n), 1); // <== @@@ TAREA: ¡cambiar esto para que haga lo correcto!
}

/// Test cases | Casos de prueba

void test00() {
    fprintf(stdout, "lt(0, -1) ==> %3d\n", lt(0, -1));
    fprintf(stdout, "lt(0,  0) ==> %3d\n", lt(0,  0));
    fprintf(stdout, "lt(0,  1) ==> %3d\n", lt(0,  1));
}

void test01() {
    fprintf(stdout, "sub(42,  0) ==> %3d\n", sub( 0, 42));
    fprintf(stdout, "sub(42,  0) ==> %3d\n", sub(42,  0));
    fprintf(stdout, "sub( 0, 67) ==> %3d\n", sub( 0, 67));
    fprintf(stdout, "sub(67,  0) ==> %3d\n", sub(67,  0));
    fprintf(stdout, "sub(42, 67) ==> %3d\n", sub(42, 67));
    fprintf(stdout, "sub(67, 42) ==> %3d\n", sub(67, 42));
}

void test02() {
    Z r1 = 42 - (67 - 25);
    Z r2 = sub(sub(25, 67), 42); // traducción de la expresión arriba, usando sólo las primitivas de Zilly

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test03() {
    Z r1 = 1024 - 512 - (67 - (42 - 512));
    // (42 - 512)       ==> sub(512, 42)
    // (67 - ...)       ==> sub(sub(512, 42), 67)
    // (1024 - 512)     ==> sub(512, 1024)
    // (...) - (...)    ==> sub(sub(sub(512, 42), 67), sub(512, 1024))
    Z r2 = sub(sub(sub(512, 42), 67), sub(512, 1024)); // <== @@@ TAREA: traducir la expresión arriba a la equivalente usando sólo las primitivas de Zilly

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test04() {
    // @@@ TAREA: defina casos de prueba para 'chs'
    fprintf(stdout, "\n--- Test chs ---\n");
    fprintf(stdout, "chs(42)  ==> %3d (debe ser -42)\n", chs(42));
    fprintf(stdout, "chs(-42) ==> %3d (debe ser 42)\n", chs(-42));
    fprintf(stdout, "chs(0)   ==> %3d (debe ser 0)\n", chs(0));
}

void test05() {
    // @@@ TAREA: defina casos de prueba para 'add'
    fprintf(stdout, "\n--- Test add ---\n");
    fprintf(stdout, "add(5, 3)   ==> %3d (debe ser 8)\n", add(5, 3));
    fprintf(stdout, "add(5, -3)  ==> %3d (debe ser 2)\n", add(5, -3));
    fprintf(stdout, "add(-5, 3)  ==> %3d (debe ser -2)\n", add(-5, 3));
    fprintf(stdout, "add(-5, -3) ==> %3d (debe ser -8)\n", add(-5, -3));
}

void test06() {
    // @@@ TAREA: defina casos de prueba para 'le'
    fprintf(stdout, "\n--- Test le ---\n");
    fprintf(stdout, "le(5, 3)  ==> %3d (k <= n) (3 <= 5) (debe ser 1)\n", le(5, 3));
    fprintf(stdout, "le(3, 5)  ==> %3d (k <= n) (5 <= 3) (debe ser 0)\n", le(3, 5));
    fprintf(stdout, "le(5, 5)  ==> %3d (k <= n) (5 <= 5) (debe ser 1)\n", le(5, 5));
}

// --- Funciones auxiliares para Tareas 07 y 08 ---
// Estas son funciones derivadas permitidas por la tarea

// Multiplicación (requiere 'add')
Z mul(Z n, Z k) {
    // k == 0 ? 0 : n + mul(n, k-1)
    // Asumimos k >= 0
    // k < 1 (o sea k == 0) es lt(1, k)
    return lt(1, k) ? 0 : add(n, mul(n, sub(1, k)));
}

// División entera (requiere 'lt', 'sub', 'add')
Z div(Z n, Z k) {
    // n / k (asumimos n >= 0, k > 0)
    // n < k ? 0 : 1 + div(n - k, k)
    return lt(k, n) ? 0 : add(1, div(sub(k, n), k));
}

// Modulo (requiere 'lt', 'sub')
Z mod(Z n, Z k) {
    // n % k (asumimos n >= 0, k > 0)
    // n < k ? n : mod(n - k, k)
    return lt(k, n) ? n : mod(sub(k, n), k);
}

// Igualdad (requiere 'le', 'mul')
Z eq(Z n, Z k) {
    // n == k es (n <= k) Y (k <= n)
    // (k <= n) es le(n, k)
    // (n <= k) es le(k, n)
    // Y se puede emular con mul()
    return mul(le(n, k), le(k, n));
}
// --- Fin funciones auxiliares ---


int square(int n) {
    // <== @@@ TAREA: implemente esta función, que computa el cuadrado de n (positivo)
    // Pero deben hacerlo tan sólo con primitivas de Zilly
    // Y pueden hacerlo con recursión .. ¡sumando numeros impares!
    // Ayudas: a) sumen de mayor a menor; b) consigan la relacion de square(n) con square(n-1)
    // Tip: impleméntela primero en C++, usando suma y recursión .. ¡con expresión condicional, obviamente!
    // Después de conseguir la fórmula recursiva mágica, compílenla a las primitivas de Zilly:
    // sólo se vale usar sub, lt (opcional), y recursión .. bien fundada con condicional.
    
    // Fórmula recursiva: square(n) = square(n-1) + (2n - 1)
    // Caso base: square(0) = 0
    //
    // En Zilly:
    // n == 0 (para n >= 0) es n < 1, que es lt(1, n)
    // n - 1             es sub(1, n)
    // 2n - 1            es (n + n) - 1, que es sub(1, add(n, n))
    // A + B             es add(A, B)

    // return (n == 0) ? 0 : (square(n-1) + (2*n - 1));
    return lt(1, n) ? 0 : add( square(sub(1, n)) , sub(1, add(n, n)) ); // λλλ Reemplazar el 0 por el λλλ chorizo λλλ mágico
}

void test07() {
    fprintf(stdout, "\n--- Test square ---\n");
    for (int i = 0; i < 9; ++i) {
        Z r1 = i * i;       // Broadway the easy way
        Z r2 = square(i);   // Broadway the hard way
        fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
    }
}

// --- Funciones auxiliares para palindromo ---
// (div, mod, mul, add, eq ya están definidas arriba)
// Estas funciones auxiliares están permitidas por la tarea

// rev_aux(n, acumulador)
Z rev_aux(Z n, Z acc) {
    // Caso base: n == 0 (n < 1)
    // return n == 0 ? acc : rev_aux(n / 10, acc * 10 + n % 10)
    Z es_cero = lt(1, n);
    Z diez = add(9, 1); // 10
    Z n_div_10 = div(n, diez);
    Z n_mod_10 = mod(n, diez);
    Z acc_por_10 = mul(acc, diez);
    Z nuevo_acc = add(n_mod_10, acc_por_10);
    
    return es_cero ? acc : rev_aux(n_div_10, nuevo_acc);
}

Z reverse(Z n) {
    return rev_aux(n, 0);
}
// --- Fin funciones auxiliares palindromo ---


int palindromo(int i){
  // @@@ TAREA: implemente esta función, que determina si un número es palíndromo
  // Debe hacerlo tan sólo con primitivas de Zilly
  // Puede definir cualquier función auxiliar que necesite (las cuales dependan de las primitivas de zilly)
  // Y pueden hacerlo con recursión.
  // Retorna 1 si lo es
  // Retorna 0 si en caso contrario.

  // Un número es palíndromo si es igual a su reverso.
  // palindromo(i) = (i == reverse(i))
  return eq(i, reverse(i));
}

void test08(){
  fprintf(stdout, "\n--- Test palindromo ---\n");
  int numeros[] = {121, 123, 454, 789, 1331, 12321, 1234321, 123456};
  for(int i = 0; i < 8; ++i){
    int n = numeros[i];
    int r = palindromo(n);
    fprintf(stdout, "palindromo(%d) ==> %d\n", n, r);
  }
}

int main() {
    test00();
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08(); // <-- Asegúrate de llamar a test08!
    return 0;
}