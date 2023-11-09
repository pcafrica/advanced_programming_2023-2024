#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>

template <typename Container>
void print(const std::string &string, const Container &cont) {
  std::cout << string << ":" << std::endl;
  for (const auto &v : cont) {
    std::cout << v << " ";
  }
  std::cout << std::endl << std::endl;
}

int main() {
  // Initialize random number generator engine.
  std::default_random_engine gen(42);
  // Or, with a random seed:
  // std::random_device rd;
  // std::default_random_engine gen(rd());

  // Initialize probability distribution.
  std::uniform_int_distribution<unsigned int> distribution(0, 9);

  // Generate vector of 100 random integers between 0 and 9.
  std::vector<unsigned int> random_numbers(100);
  for (unsigned int &num : random_numbers) {
    num = distribution(gen);
  }
  print("Original vector", random_numbers);

  // Sort the vector.
  std::vector<unsigned int> sorted_numbers(random_numbers);
  std::sort(sorted_numbers.begin(), sorted_numbers.end());
  print("Sorted numbers", sorted_numbers);

  // Remove duplicates while sorting.
  const std::set<unsigned int> random_numbers_set(random_numbers.begin(),
                                                  random_numbers.end());
  const std::vector<unsigned int> sorted_unique_numbers(
      random_numbers_set.begin(), random_numbers_set.end());

  // Or:
  // std::vector<unsigned int> sorted_unique_numbers(random_numbers);
  // std::sort(sorted_unique_numbers.begin(), sorted_unique_numbers.end());
  // auto unique_end =
  //   std::unique(sorted_unique_numbers.begin(),
  //     sorted_unique_numbers.end());
  // sorted_unique_numbers.erase(unique_end, sorted_unique_numbers.end());

  print("Sorted unique numbers", sorted_unique_numbers);

  // Remove duplicates without sorting.
  std::vector<unsigned int> unsorted_unique_numbers;
  std::unordered_set<unsigned int> search_list(random_numbers_set.begin(),
                                               random_numbers_set.end());

  for (const unsigned int &element : random_numbers) {
    if (search_list.count(element) > 0) {
      search_list.erase(element);
      unsorted_unique_numbers.push_back(element);
    }
  }

  print("Unsorted unique numbers", unsorted_unique_numbers);

  return 0;
}
