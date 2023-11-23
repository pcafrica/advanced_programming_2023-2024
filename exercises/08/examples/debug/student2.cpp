#include <cassert>
#include <iostream>
#include <string>

class Name {
public:
  Name(const std::string given_name, const std::string family_name)
      : given_name(given_name), family_name(family_name) {
    std::cout << "Invoking Name constructor in file " << __FILE__ << " on line "
              << __LINE__ << std::endl;
  }

  ~Name() {}

  std::string get_name() const { return (given_name + " " + family_name); }

private:
  std::string given_name;
  std::string family_name;
};

class Student {
public:
  Student(std::string given_name, std::string family_name, int id)
      : name(new Name(given_name, family_name)), id(id) {
    name = nullptr; // Bug!
  }

  ~Student() {
    // delete name; // Missing!
  }

  int get_id() const { return id; }

  std::string get_name() const {
    // assert(name != nullptr); // Missing!
    return name->get_name();
  }

private:
  Name *name;
  int id;
};

int main(int argc, char **argv) {
  // Create an instance of the student on the heap.
  Student *student = new Student("Terry", "Jones", 111234);

  std::cout << "Student name: " << student->get_name() << ", "
            << "#ID: " << student->get_id() << std::endl;

  delete student;

  return 0;
}
