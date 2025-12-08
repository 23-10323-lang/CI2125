///
/// functions.cxx
///

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

double area_square(double x) {
  return x * x;
}

double area_circle(double radius) {
  return M_PI * pow(radius, 2.0);
}

void bad_usage(int argc, const char *argv[]) {
  fprintf(stderr, "Uso %s <square | circle> <number>\n", argv[0]);
  exit(1);
}

int main(int argc, const char *argv[])
{
  if (argc != 3) {
    bad_usage(argc, argv);
  }

  if (strcmp(argv[1], "square") == 0) {
    double area = area_square(atof(argv[2]));
    fprintf(stdout, "area square: %f\n", area);
  } else if (strcmp(argv[1], "circle") == 0) {
    double area = area_circle(atof(argv[2]));
    fprintf(stdout, "area circle: %f\n", area);
  } else {
    bad_usage(argc, argv);
  }

  return 0;
}
