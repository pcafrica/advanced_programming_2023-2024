#include <iostream>
#include <vector>

class Array {
private:
  std::vector<double> data;

  class ArrayProxy {
  private:
    double &val;

  public:
    ArrayProxy(double &val) : val(val) {}

    // Reading operator.
    operator double() const {
      std::cout << "const version" << std::endl;
      return val;
    }

    // Writing operator.
    ArrayProxy operator=(const double &x) {
      std::cout << "non-const version" << std::endl;
      val = x;
      return *this;
    }

    // Copy assignment operator.
    ArrayProxy &operator=(const ArrayProxy &other) {
      std::cout << "non-const version" << std::endl;
      val = other.val;
      return *this;
    }
  };

public:
  // Constructor.
  Array(const std::vector<double> &data) : data(data) {}

  // Access operator for both reading and writing.
  ArrayProxy operator()(const unsigned int idx) {
    return ArrayProxy(data[idx]);
  }
};

int main() {
  Array a{{-2.3, 5, 1.2, 0.0, 7}};

  const double x = a(2);                          // const version.
  a(1) = a(2) = 3;                                // non-const version (twice).
  std::cout << a(1) << ", " << a(2) << std::endl; // const version.

  return 0;
}
