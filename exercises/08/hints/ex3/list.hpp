#ifndef LIST_HPP__
#define LIST_HPP__

#include "node.hpp"

// Double-linked list.
class List {
public:
  List() : head(nullptr) {}

  ~List() {
    if (head != nullptr)
      delete head;
  }

  void append(Node *new_node);

  void append(int value);

  void erase(Node *node);

  void erase(int value);

  Node *find(int value) const;

  void print() const;

private:
  Node *head;
};

#endif /* LIST_HPP__ */
