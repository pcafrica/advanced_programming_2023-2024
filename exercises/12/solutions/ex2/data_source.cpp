#include "data_source.hpp"

FileDataSource::FileDataSource(const std::string &name,
                               const std::string &filename)
    : DataSource(name), filename(filename) {
  file.open(filename);

  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    std::exit(1);
  }
}

FileDataSource::~FileDataSource() {
  if (file.is_open()) {
    std::cout << "Closing file: " << filename << std::endl;
    file.close();
  }
}

void FileDataSource::read_data() {
  std::cout << "Reading data from file: " << filename << std::endl;

  data.clear();

  double value;
  while (file >> value) {
    data.push_back(value);
  }
}

std::ostream &operator<<(std::ostream &os, const DataSource &source) {
  for (unsigned int i = 0; i < source.data.size(); ++i) {
    os << source.data[i];
    if (i < source.data.size() - 1) {
      os << ", ";
    }
  }
  return os;
}

void ConsoleDataSource::read_data() {
  std::cout << "Reading data from the standard input" << std::endl;
  std::cout << "Enter a list of doubles separated by space:" << std::endl;

  data.clear();

  std::string line;

  std::cin.clear();
  std::cin.ignore();
  std::getline(std::cin, line);

  std::istringstream iss(line);
  double value;
  while (iss >> value) {
    data.push_back(value);
  }
}
