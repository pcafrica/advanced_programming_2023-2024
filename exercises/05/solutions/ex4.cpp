#include <iostream>

// Template class to calculate the factorial at compile time.
template <unsigned int N> class Factorial {
public:
  static constexpr unsigned int value = N * Factorial<N - 1>::value;
};

// Specialization for Factorial<0> (base case).
template <> class Factorial<0> {
public:
  static constexpr unsigned int value = 1;
};

int main() {
  constexpr unsigned int n1 = 5;
  constexpr unsigned int n2 = 7;
  constexpr unsigned int n3 = 10;

  static_assert(Factorial<n1>::value == 120, "Factorial of 5 is not 120");
  static_assert(Factorial<n2>::value == 5040, "Factorial of 7 is not 5040");
  static_assert(Factorial<n3>::value == 3628800,
                "Factorial of 10 is not 3628800");

  std::cout << "Factorial of " << n1 << " is: " << Factorial<n1>::value
            << std::endl;
  std::cout << "Factorial of " << n2 << " is: " << Factorial<n2>::value
            << std::endl;
  std::cout << "Factorial of " << n3 << " is: " << Factorial<n3>::value
            << std::endl;

  return 0;
}
