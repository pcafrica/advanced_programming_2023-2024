#include "list.hpp"
#include <iostream>

void List::append(Node *new_node) {
  if (head == nullptr) {
    head = new_node;
  } else {
    Node *tail = head;

    while (tail->get_next()) {
      tail = tail->get_next();
    }

    tail->set_next(new_node);
    new_node->set_previous(tail);
  }
}

void List::append(int value) {
  if (find(value) != nullptr) {
    std::cout << "Value " << value
              << " already exists in the list. Not appending." << std::endl;
    return;
  }

  Node *new_node = new Node(value);
  append(new_node);
}

void List::erase(Node *node) {
  if (node == nullptr) {
    return;
  }

  if (node->get_previous() != nullptr) {
    node->get_previous()->set_next(node->get_next());
  } else {
    head = node->get_next();
  }

  if (node->get_next() != nullptr) {
    node->get_next()->set_previous(node->get_previous());
  }

  node->set_next(nullptr);
  node->set_previous(nullptr);

  delete node;
}

void List::erase(int value) {
  Node *node = find(value);

  if (node != nullptr) {
    erase(node);
  } else {
    std::cout << "Value " << value
              << " does not exist in the list. Not erasing." << std::endl;
  }
}

Node *List::find(int value) const {
  Node *current = head;

  while (current != nullptr) {
    if (current->get_data() == value)
      return current;

    current = current->get_next();
  }

  return nullptr;
}

void List::print() const {
  std::cout << "List: ";

  Node *current = head;

  if (current == nullptr) {
    std::cout << "empty";
  }

  while (current != nullptr) {
    std::cout << current->get_data();
    if (current->get_next() != nullptr)
      std::cout << ", ";
    current = current->get_next();
  }

  std::cout << std::endl;
}
