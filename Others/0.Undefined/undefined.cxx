///
/// undefined.cxx
///
/// examples of undefined behavior and other weird code
///

#include <cstdlib>
#include <cstdio>
#include <vector>

//
// test0: the order of evaluation of arguments is undetermined
//

void check0(const char *seq, int m, int n, int k) {
    fprintf(stdout, "(%s): (%d, %d, %d)\n", seq, m, n, k);
}

// Warning: undefined behavior
void test0() {
    int a[] = { 0, 1, 2, 3 };

    int i = 0;
    check0("++i, a[i], a[++i]", ++i, a[i], a[++i]);

    i = 0;
    check0("++i, a[++i], a[i]", ++i, a[++i], a[i]);

    i = 0;
    check0("a[i], ++i, a[++i]", a[i], ++i, a[++i]);

    i = 0;
    check0("a[i], a[++i], ++i", a[i], a[++i], ++i);

    i = 0;
    check0("a[++i], ++i, a[i]", a[++i], ++i, a[i]);

    i = 0;
    check0("a[++i], a[i], ++i", a[++i], a[i], ++i);

    i = 0;
    check0("  ++i,  ++i,  ++i",  ++i,  ++i,  ++i);

    fprintf(stdout, "========\n\n");
}

void test1() {
    // Warning: undefined behavior
    int x = 3;
    int y = 7;
    fprintf(stdout, "++[x: %d] + ++[y: %d] ==> %d\n", x, y, ++x + ++y);
    fprintf(stdout, "--------\n");

    // Warning: undefined behavior
    x = 3;
    y = 7;
    fprintf(stdout, "%d <== ++[x: %d] + ++[y: %d]\n", ++x + ++y, x, y);
    fprintf(stdout, "--------\n");

    // Undetermined but defined behavior
    x = 3;
    y = 7;
    fprintf(stdout, "++[x:%d] + ++[y:%d] ==> ", x, y);
    fprintf(stdout, "%d\n", ++x + ++y);

    fprintf(stdout, "========\n\n");
}

void test2() {

    {
        fprintf(stdout, "prefix increment\n");

        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "int x = 1 + ++n ==> ");
        int x = 1 + ++n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        fprintf(stdout, "postfix increment\n");

        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "int x = 1 + n++ ==> ");
        int x = 1 + n++;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        fprintf(stdout, "prefix increment\n");

        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);

        fprintf(stdout, "%s ==> ", "int x = 1 + ++n");
        int x = 1 + ++n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);

        fprintf(stdout, "%s ==> ", "int y = ++n + 1");
        int y = ++n + 1;
        fprintf(stdout, "[n:%d] [x:%d] [y:%d]\n", n, x, y);
    }

    fprintf(stdout, "--------\n");

    {
        fprintf(stdout, "postfix increment\n");

        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);

        fprintf(stdout, "%s ==> ", "int x = 1 + n++");
        int x = 1 + n++;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);

        fprintf(stdout, "%s ==> ", "int y = n++ + 1");
        int y = n++ + 1;
        fprintf(stdout, "[n:%d] [x:%d] [y:%d]\n", n, x, y);
    }

    fprintf(stdout, "========\n\n");
}

void test3() {

    fprintf(stdout, "========\n");
    fprintf(stdout, "prefix increment\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "int x = ++n;");
        int x = ++n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x); // 41 41
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "++n; int x = n; (deconstruction 0)");
        ++n;
        int x = n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "n += 1; int x = n; (deconstruction 1)");
        n += 1;
        int x = n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "n = n + 1; int x = n; (deconstruction 2 - normal form)");
        n = n + 1;
        int x = n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "int x = (n = n + 1); (reconstruction 3)");
        int x = (n = n + 1);
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "int x = n += 1; (reconstruction 4)");
        int x = (n += 1);
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "int x = ++n; (reconstruction 4)");
        int x = ++n;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "========\n");
    fprintf(stdout, "postfix increment\n");

    /*
    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "n++");
        fprintf(stdout, "%d\n", n++);
        fprintf(stdout, "[n:%d]\n", n);
    }
    */

    {
        int n = 40;
        fprintf(stdout, "[n:%d]\n", n);
        fprintf(stdout, "%s ==> ", "int x = n++;");
        int x = n++;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40;
        fprintf(stdout, "%s ==> ", "int t = n; n = n + 1; int x = t (deconstruction 0 - normal form)");
        int t = n;
        n = n + 1;
        int x = t;
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "--------\n");

    {
        int n = 40; int t;
        fprintf(stdout, "%s ==> ", "x = (int t = n, n = n + 1, t) (reconstruction 1)");
        int x = (t = n, n = n + 1, t);
        fprintf(stdout, "[n:%d] [x:%d]\n", n, x);
    }

    fprintf(stdout, "========\n");
}

/*

    Jorge Baralt

    1. x+++y

    2. x +++ y

    3. x + ++y

    4. x++ + y

*/

// Well defined behavior
void test4() {
    int a = 3;
    int b = 7;
    {
        // 1. x+++y
        int x = a;
        int y = b;
        fprintf(stdout, "[x:%d]+++[y:%d]   ==> %d\n", a, b, x+++y);
    }
    fprintf(stdout, "--------\n");
    {
        // 2. x +++ y
        int x = a;
        int y = b;
        fprintf(stdout, "[x:%d] +++ [y:%d] ==> %d\n", a, b, x +++ y);
    }
    fprintf(stdout, "--------\n");
    {
        // 3. x + ++y
        int x = a;
        int y = b;
        fprintf(stdout, "[x:%d] + ++[y:%d] ==> %d\n", a, b, x + ++y);
    }
    fprintf(stdout, "--------\n");
    {
        // 4. x++ + y
        int x = a;
        int y = b;
        fprintf(stdout, "[x:%d]++ + [y:%d] ==> %d\n", a, b, x++ + y);
    }
    fprintf(stdout, "========\n\n");
}

// Warning: undefined behavior
void test5() {
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n + ++n ==> %d\n", n + ++n);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "++n + n ==> %d\n", ++n + n);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n + n++ ==> %d\n", n + n++);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n++ + n ==> %d\n", n++ + n);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "++n + --n ==> %d\n", ++n + --n);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "--n + ++n ==> %d\n", --n + ++n);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n++ + n-- ==> %d\n", n++ + n--);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n-- + n++ ==> %d\n", n-- + n++);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "++n + n-- ==> %d\n", ++n + n--);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "--n + n++ ==> %d\n", --n + n++);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n++ + --n ==> %d\n", n++ + --n);
    }
    {
        int n = 10;
        fprintf(stdout, "n ==> %d\n", n);
        fprintf(stdout, "n-- + ++n ==> %d\n", n-- + ++n);
    }
}

void show(int n, int a[]) {
    fprintf(stdout, "[ ");
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "%s%d", (i ? ", " : ""), a[i]);
    }
    fprintf(stdout, " ]\n");
    fprintf(stdout, "--------\n");
}

// Warning: undefined behavior
void test6() {
    int a[] = { 100, 101, 102, 103, 104, 105, 106, 107 };
    const int N = sizeof(a) / sizeof(a[0]);
    int weird = 888;
    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[i] = weird + ++i; ==> ");
        a[i] = weird + ++i;
        show(N, a);
    }

    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[i] = weird + i++; ==> ");
        a[i] = weird + i++;
        show(N, a);
    }

    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[++i] = weird + i; ==> ");
        a[++i] = weird + i;
        show(N, a);
    }

    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[i++] = weird + i; ==> ");
        a[i++] = weird + i;
        show(N, a);
    }

    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[i++] = weird + i++; ==> ");
        a[i++] = weird + i++;
        show(N, a);
    }

    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[++i] = weird + i++; ==> ");
        a[++i] = weird + i++;
        show(N, a);
    }

    {
        ++weird;
        int i = rand() % 4 + 2;
        fprintf(stdout, "[w:%d] [i:%d]", weird, i);
        fprintf(stdout, " a[i] = 100 + a[i++]; ==> ");
        a[i] = 100 + a[i++];
        // a[i] = 100 + a[i];
        // ++i;
        show(N, a);
    }
}

void (*test[])() = {
    test0,
    test1,
    test2,
    test3,
    test4,
    test5,
    test6
};

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso sin abuso: %s <test number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const int NTESTS = sizeof(test) / sizeof(test[0]);
    int ntest = atoi(argv[1]);
    if (ntest < 0 || NTESTS <= ntest) {
        fprintf(stderr, "%s %s ==> test %d no disponible\n", argv[0], argv[1], ntest);
        return EXIT_FAILURE;
    }
    test[ntest]();
    return EXIT_SUCCESS;
}
