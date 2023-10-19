#include <iostream>
#include <vector>

class Array {
public:
  Array(const std::vector<double> &data) : data(data) {}

  // Access operator, non-const version.
  double &operator()(const unsigned int i) {
    std::cout << "non-const version" << std::endl;
    return data[i];
  }

  // Access operator, const version.
  const double &operator()(const unsigned int i) const {
    std::cout << "const version" << std::endl;
    return data[i];
  }

private:
  std::vector<double> data;
};

int main() {
  Array a{{-2.3, 5, 1.2, 0.0, 7}};

  const double x = a(2); // non-const version.

  a(1) = a(2) = 3; // non-const version.

  std::cout << a(1) << std::endl << a(2) << std::endl; // non-const version.

  const Array &a_const = a;
  std::cout << a_const(2) << std::endl; // const version.

  return 0;
}
