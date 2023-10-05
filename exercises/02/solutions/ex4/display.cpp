#include "display.hpp"
#include <iostream>

void display_students(const std::vector<Student> &students) {
  for (const Student &student : students) {
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Age: " << student.age << std::endl;
    std::cout << "Grade Average: " << student.grade_average << std::endl;
    std::cout << "-------------" << std::endl;
  }
}
