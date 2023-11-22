#include <string>

class Student {
public:
  Student(std::string name, unsigned int id) {
    // Set break point here.
    this->name = name;
    this->id = id;
  }

  ~Student() { id = 0; }

private:
  std::string name;
  unsigned int id;
};

int main(int argc, char **argv) {
  // Instance of Student on the stack.
  Student student("Alice", 112233);

  // Instance of Student on the heap.
  Student *other_student = new Student("Bob", 123456);

  delete other_student;

  return 0;
}
