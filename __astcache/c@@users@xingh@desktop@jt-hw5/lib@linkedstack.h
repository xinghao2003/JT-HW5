#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T> class LinkedStack {
private:
  struct Node {
    T data;
    Node *next;
  };
  Node *top;

public:
  LinkedStack() : top(nullptr) {}

  ~LinkedStack() { clear(); }

  // Pushes an element onto the stack.
  bool push(T element) {
    Node *newNode = new Node{element, top};
	top = newNode;
	return true;
  }
  // Pops the top element from the stack and returns it; throws if the stack is empty.
  T pop() {
    if (top == nullptr) {
      throw out_of_range("Stack is empty");
    }
    Node *temp = top;
    T data = top->data;
    top = top->next;
    delete temp;
    return data;
  }

  T peek() const {
    if (top == nullptr) {
      throw out_of_range("Stack is empty");
    }
    return top->data;
  }

  bool isEmpty() const { return top == nullptr; }

  // Clears all elements from the stack.
  bool clear() {
    while (top != nullptr) {
      pop();
	}
	return true;
  }

  bool randomInsert(int n, T rangeStart, T rangeEnd) {
    for (int i = 0; i < n; ++i) {
      T randNum = rangeStart + (rand() % (rangeEnd - rangeStart + 1));
      push(randNum);
	}
    return true;
  }

  std::string print() const {
    std::stringstream ss;
    if (top == nullptr) {
      ss << "Stack is empty.";
    }
    Node *current = top;
    while (current) {
      ss << current->data << " ";
      current = current->next;
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
  }

  std::string visualize() const {
    std::stringstream ss;
    if (top == nullptr) {
      ss << "Stack is empty.";
    } else {
	  Node *current = top;
      while (current) {
        ss << "(" << current->data << ") -> ";
        current = current->next;
      }
      ss << "<";
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
  }
};

#endif // LINKED_STACK_H
