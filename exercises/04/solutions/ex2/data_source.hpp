#ifndef DATA_SOURCE_HPP__
#define DATA_SOURCE_HPP__

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class DataSource {
public:
  DataSource(const std::string &name) : name(name) {}

  virtual ~DataSource() {}

  virtual void read_data() = 0;

  std::vector<double> &get_data() { return data; }
  const std::vector<double> &get_data() const { return data; }

  void display_info() const {
    std::cout << "Data source name: " << name << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, const DataSource &ds);

protected:
  std::string name;
  std::vector<double> data;
};

class FileDataSource : public DataSource {
public:
  FileDataSource(const std::string &name, const std::string &filename);

  ~FileDataSource();

  void read_data() override;

private:
  std::string filename;
  std::ifstream file;
};

class ConsoleDataSource : public DataSource {
public:
  ConsoleDataSource(const std::string &name) : DataSource(name) {}

  ~ConsoleDataSource() {}

  void read_data() override;
};

#endif /* DATA_SOURCE_HPP__ */
