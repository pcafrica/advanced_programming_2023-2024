#include "list.hpp"

int main() {
  List list;
  list.append(5);
  list.append(10);
  list.append(15);
  list.print();

  list.append(15); // Append a duplicate node.
  list.print();

  list.erase(5);
  list.print();
  list.erase(10);
  list.print();
  list.erase(15);
  list.print();
  list.erase(20); // Erase a non-existing node.
  list.print();
  list.erase(nullptr); // Erase a non-existing node.
  list.print();

  return 0;
}
