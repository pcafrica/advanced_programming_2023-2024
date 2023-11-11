#include "compare_policy.hpp"
#include <iostream>
#include <vector>

int main() {
  const std::string name1 = "Pasquale Claudio Africa";
  const std::string name2 = "pasquale claudio africa";
  std::cout.setf(std::ios::boolalpha);

  std::cout << "*** Comparison policy with a function ***" << std::endl;

  // Case sensitive comparison.
  std::cout << "Case sensitive comparison:" << std::endl;
  std::cout << "\"" << name1 << "\" is equal to \"" << name2
            << "\": " << equal<CaseCompare>(name1, name2) << std::endl
            << std::endl;

  // Case insensitive comparison.
  std::cout << "Case insensitive comparison:" << std::endl;
  std::cout << "\"" << name1 << "\" is equal to \"" << name2
            << "\": " << equal<NoCaseCompare>(name1, name2) << std::endl;

  // ----------

  std::cout << std::endl
            << "*** Comparison policy with a functor ***" << std::endl;

  // Case sensitive comparison using functor.
  CompareString<CaseCompare> c1;
  std::cout << "Case sensitive comparison:" << std::endl;
  std::cout << "\"" << name1 << "\" is equal to \"" << name2
            << "\": " << c1(name1, name2) << std::endl
            << std::endl;

  // Case insensitive comparison using functor.
  CompareString<NoCaseCompare> c2;
  std::cout << "Case insensitive comparison:" << std::endl;
  std::cout << "\"" << name1 << "\" is equal to \"" << name2
            << "\": " << c2(name1, name2) << std::endl;

  return 0;
}
