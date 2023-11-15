#include "functions.hpp"
#include <cmath>

extern "C" {
double square(const double &x) { return x * x; }

double cube(const double &x) { return x * x * x; }

double square_root(const double &x) { return std::sqrt(x); }
}
