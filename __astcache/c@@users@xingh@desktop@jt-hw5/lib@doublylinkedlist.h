﻿#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
template <typename T> class DoublyLinkedList {
private:
  struct Node {
    T data;
    Node *prev;
    Node *next;
  };
  Node *head;
  Node *tail;
public:
  // Constructor: Sets up a doubly linked list with dummy head and tail nodes.
  DoublyLinkedList() {
    head = new Node{T(), nullptr, nullptr};
    tail = new Node{T(), head, nullptr};
    head->next = tail;
  }
  // Destructor: Clears the list and deletes head and tail nodes to prevent memory leaks.
  ~DoublyLinkedList() {
    clear();
    delete head;
    delete tail;
  }
  Node *getHead() const { return head->next; }
  void setHead(Node *node) {
    if (node != nullptr) {
      node->prev = head;
      head->next = node;
    } else {
      head->next = tail;
      tail->prev = head;
    }
  }
  // Inserts a new element at the front of the list, right after the head.
  bool insertFront(T element) {
    Node *newNode = new Node{element, head, head->next};
    head->next->prev = newNode;
	head->next = newNode;
	return true;
  }
  // Appends a new element at the end of the list just before the tail.
  bool insertLast(T element) {
    Node *newNode = new Node{element, tail->prev, tail};
    tail->prev->next = newNode;
	tail->prev = newNode;
	return true;
  }
  int find(T target) {
	Node* current = head->next;
    int index = 0;
	while (current != tail) {
		if (current->data == target) {
            return index;
        }
        current = current->next;
        index++;
    }
	return -1;
  }
  bool findAndInsertBefore(T target, T element) {
    Node *current = head->next;
    while (current != tail && current->data != target) {
      current = current->next;
    }
    if (current != tail) {
      Node *newNode = new Node{element, current->prev, current};
      current->prev->next = newNode;
      current->prev = newNode;
    } else {
      cout << "Target not found." << endl;
      return false;
    }
	return true;
  }
  bool findAndInsertAfter(T target, T element) {
    Node *current = head->next;
    while (current != tail && current->data != target) {
      current = current->next;
    }
    if (current != tail) {
      Node *newNode = new Node{element, current, current->next};
      current->next->prev = newNode;
      current->next = newNode;
    } else {
      cout << "Target not found." << endl;
      return false;
    }
    return true;
  }
  // Deletes a node with the specified target value; returns true if the node was found and deleted.
  bool deleteNode(T target) {
	Node *current = head->next;
    while (current != tail && current->data != target) {
      current = current->next;
    }
    if (current == tail) {
      cout << "Node not found." << endl;
      return false;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return true;
  }
  bool clear() {
    Node *current = head->next;
    while (current != tail) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
    head->next = tail;
	tail->prev = head;
	return true;
  }
  std::string visualize() const {
    std::stringstream ss;
    if (head->next == tail) {
      ss << "List is empty.";
    } else {
	  Node *current = head->next;
	  while (current != tail) {
		ss << "(" << current->data << ") <-> ";
        current = current->next;
      }
	  ss << "X";
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
  }
  std::string print() const {
    std::stringstream ss;
    if (head->next == tail) {
      ss << "List is empty.";
    }
    Node *current = head->next;
    while (current != tail) {
      ss << current->data << " ";
      current = current->next;
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
  }
  // Reverses the order of the nodes in the list
  bool reverse() {
    Node *current = head->next;
    Node *temp = nullptr;
    if (head->next == tail || head->next->next == tail) {
	  return true;
    }
    while (current != tail) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    temp = head->next;
    head->next = tail->prev;
    tail->prev = temp;
    head->next->prev = head;
	tail->prev->next = tail;
	return true;
  }
  bool randomInsert(int n, T rangeStart, T rangeEnd) {
	for (int i = 0; i < n; ++i) {
	  T randNum = rangeStart + (rand() % (rangeEnd - rangeStart + 1));
	  insertLast(randNum);
	}
	return true;
  }
};
#endif // DOUBLY_LINKED_LIST_H
