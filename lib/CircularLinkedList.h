#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
template <typename T> class CircularLinkedList {
private:
  struct Node {
    T data;
    Node *next;
  };
  Node *header;
  Node *last;
public:
  // Constructor: Initializes a circular linked list with a dummy header node that points to itself.
  CircularLinkedList() {
	header = new Node{T(), nullptr};
	header->next = header;
	last = header;
  }
  // Destructor: Clears the list and deletes the header node to prevent memory leaks.
  ~CircularLinkedList() {
	clear();
	delete header;
  }
  Node *getHeader() const { return header; }
  std::string visualize() const {
	std::stringstream ss;
	if (header->next == header) {
	  ss << "List is empty.";
	} else {
	  Node *current = header->next;
	  while (current != header) {
		ss << "(" << current->data << ") -> ";
		current = current->next;
	  }
	  ss << "X";
	}
    std::cout << ss.str() << std::endl;
	return ss.str();
  }
  std::string print() const {
	std::stringstream ss;
	if (header->next == header) {
      ss << "List is empty.";
	}
    Node *current = header->next;
	while (current != header) {
      ss << current->data << " ";
      current = current->next;
	}
	std::cout << ss.str() << std::endl;
	return ss.str();
  }
  // Inserts a new element at the beginning of the list, immediately after the header.
  bool insertFirst(T element) {
	Node *newNode = new Node{element, header->next};
    header->next = newNode;
    if (last == header)
	  last = newNode;
	return true;
  }
  // Appends a new element at the end of the list, updating the 'last' pointer accordingly.
  bool insertLast(T element) {
    Node *newNode = new Node{element, header};
	last->next = newNode;
	last = newNode;
	return true;
  }
  int find(T target) {
	Node* current = header->next;
	int index = 0;
	while (current != header) {
		if (current->data == target) {
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
  }
  // Attempts to find a target element and insert a new element after it; returns true if successful.
  bool findAndInsertAfter(T target, T element) {
    Node *current = header->next;
    while (current != header && current->data != target) {
      current = current->next;
	}
    if (current != header) {
      Node *newNode = new Node{element, current->next};
      current->next = newNode;
	  if (current == last)
        last = newNode;
    } else {
      cout << "Target not found." << endl;
	  return false;
    }
    return true;
  }
  bool findAndInsertBefore(T target, T element) {
    Node *current = header;
    while (current->next != header && current->next->data != target) {
      current = current->next;
	}
    if (current->next != header) {
      Node *newNode = new Node{element, current->next};
      current->next = newNode;
	  if (current == last)
        last = newNode;
    } else {
	  cout << "Target not found." << endl;
	  return false;
    }
    return true;
  }
  // Deletes a node with the specified target value; returns true if the node was found and deleted.
  bool deleteNode(T target) {
    Node *current = header;
    while (current->next != header && current->next->data != target) {
      current = current->next;
	}
    if (current->next != header) {
      Node *temp = current->next;
      current->next = temp->next;
	  if (temp == last)
        last = current;
      delete temp;
    } else {
	  cout << "Target not found." << endl;
      return false;
    }
    return true;
  }
  // Randomly insert n value ranging from Start to End into list
  bool randomInsert(int n, T rangeStart, T rangeEnd) {
	for (int i = 0; i < n; ++i) {
	  T randNum = rangeStart + (rand() % (rangeEnd - rangeStart + 1));
	  insertLast(randNum);
	}
	return true;
  }
  // Delete all the nodes in the list
  bool clear() {
    Node *current = header->next;
	while (current != header) {
      Node *temp = current;
	  current = current->next;
      delete temp;
    }
    header->next = header;
	last = header;
	return true;
  }
  // Reverses the order of the nodes in the list.
  bool reverse() {
	if (header->next == header)
	  return true;
	Node *prev = header, *current = header->next, *next = nullptr;
    Node *originalLast = last;
	do {
      next = current->next;
	  current->next = prev;
      prev = current;
	  current = next;
    } while (current != header);
    header->next = originalLast;
	last = header->next;
	return true;
  }
};
#endif // CIRCULAR_LINKED_LIST_H
