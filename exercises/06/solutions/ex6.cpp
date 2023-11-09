#include <chrono>
#include <cmath>
#include <iostream>

class Vector {
public:
  // Constructor.
  Vector(const unsigned int &size = 0) : data(new double[size]), size(size) {}

  // Move constructor.
  Vector(Vector &&other) noexcept {
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
  }

  // Copy assignment operator.
  Vector &operator=(const Vector &other) noexcept {
    if (this != &other) {
      delete[] data;

      size = other.size;
      data = new double[size];

      for (unsigned int i = 0; i < other.size; ++i) {
        data[i] = other.data[i];
      }
    }

    return *this;
  }

  // Move assignment operator.
  Vector &operator=(Vector &&other) noexcept {
    if (this != &other) {
      delete[] data;
      data = other.data;
      size = other.size;
      other.data = nullptr;
      other.size = 0;
    }

    return *this;
  }

  // Destructor.
  ~Vector() { delete[] data; }

private:
  double *data;
  unsigned int size;
};

void measure_copy(const unsigned int &size) {
  Vector source(size);
  Vector destination(size);

  auto start = std::chrono::high_resolution_clock::now();
  destination = source;
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken to copy vector of size " << size << ": "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << " milliseconds." << std::endl;
}

void measure_move(const unsigned int &size) {
  Vector source(size);
  Vector destination(size);

  auto start = std::chrono::high_resolution_clock::now();
  destination = std::move(source);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken to move vector of size " << size << ": "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds." << std::endl;
}

int main() {
  for (unsigned int i = 20; i < 31; ++i) {
    measure_copy(std::pow(2, i));
    measure_move(std::pow(2, i));
    std::cout << std::endl;
  }

  return 0;
}
