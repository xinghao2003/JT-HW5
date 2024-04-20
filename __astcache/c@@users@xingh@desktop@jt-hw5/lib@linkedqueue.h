#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T> class LinkedQueue {
private:
  struct Node {
    T data;
    Node *next;
  };
  Node *front, *rear;

public:
  LinkedQueue() : front(nullptr), rear(nullptr) {}

  ~LinkedQueue() { clear(); }

  // Enqueues an element at the end of the queue.
  bool enqueue(T element) {
    Node *newNode = new Node{element, nullptr};
    if (rear == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
	  rear = newNode;
	}
    return true;
  }

  // Dequeues and returns the element at the front of the queue; throws if the queue is empty.
  T dequeue() {
    if (front == nullptr) {
      throw out_of_range("Queue is empty");
    }
    Node *temp = front;
    T data = front->data;
    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    }
    delete temp;
    return data;
  }

  bool isEmpty() const { return front == nullptr; }

  // Clears all elements from the queue.
  bool clear() {
    while (front != nullptr) {
      dequeue();
	}
	return true;
  }

  bool randomInsert(int n, T rangeStart, T rangeEnd) {
    for (int i = 0; i < n; ++i) {
      T randNum = rangeStart + (rand() % (rangeEnd - rangeStart + 1));
	  enqueue(randNum);
	}
	return true;
  }

  std::string visualize() const {
    std::stringstream ss;
    if (front == nullptr) {
      ss << "Queue is empty.";
    } else {
	  Node *current = front;
      while (current) {
        ss << "(" << current->data << ") -> ";
        current = current->next;
      }
	  ss << "<";
	}
    std::cout << ss.str() << std::endl;
    return ss.str();
  }

  std::string print() const {
    std::stringstream ss;
    if (front == nullptr) {
      ss << "Queue is empty.";
    }
    Node *current = front;
    while (current) {
      ss << current->data << " ";
      current = current->next;
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
  }
};

#endif // LINKED_QUEUE_H
