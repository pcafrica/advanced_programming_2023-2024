#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
  // Define file paths.
  const std::string input_file_path = "../input.txt";
  const std::string output_file_path = "output.txt";

  // Open input file.
  std::ifstream input_file(input_file_path);
  if (!input_file.is_open()) {
    std::cerr << "Error opening input file: " << input_file_path << std::endl;
    return 1;
  }

  // Create a map to store word-frequency pairs.
  std::map<std::string, int> word_frequency_map;

  // Read input text file.
  std::string line;
  while (getline(input_file, line)) {
    // Split the line into words.
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
      // Convert word to lowercase for case-insensitive analysis
      // and remove punctuation.
      std::transform(word.begin(), word.end(), word.begin(),
                     [](char ch) -> char {
                       if (ispunct(ch))
                         return '\0';
                       return tolower(ch);
                     });

      // Increment word frequency. operator[] automatically allocates a new
      // entry if it was not present yet.
      word_frequency_map[word]++;
    }
  }

  // Close input file.
  input_file.close();

  // Sort the output by frequency, in descending order.
  // If two words have the same frequency, then sort them alphabetically.

  // Being an associative container, a std::map cannot be sorted.
  // So let's convert it to a std::vector, and sort it instead.
  std::vector<std::pair<std::string, int>> word_frequency_vector(
      word_frequency_map.begin(), word_frequency_map.end());
  std::sort(word_frequency_vector.begin(), word_frequency_vector.end(),
            [](const auto &a, const auto &b) {
              return (a.second > b.second || a.first < b.first);
            });

  // Open output file.
  std::ofstream output_file(output_file_path);
  if (!output_file.is_open()) {
    std::cerr << "Error opening output file: " << output_file_path << std::endl;
    return 1;
  }

  // Write word-frequency pairs to output file.
  for (const auto &[word, frequency] : word_frequency_vector) {
    output_file << word << ": " << frequency << std::endl;
  }

  // Close output file.
  output_file.close();

  return 0;
}
