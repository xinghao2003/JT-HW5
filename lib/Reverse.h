#ifndef REVERSE_H
#define REVERSE_H

#include "LinkedQueue.h"
#include "LinkedStack.h"

template <typename T> bool reverseLinkedQueue(LinkedQueue<T> &queue) {
  LinkedStack<T> stack;
  if(queue.isEmpty()){
	return false;
  }
  while (!queue.isEmpty()) {
    stack.push(queue.dequeue());
  }
  while (!stack.isEmpty()) {
    queue.enqueue(stack.pop());
  }
  return true;
}

template <typename T> bool reverseLinkedStack(LinkedStack<T> &stack) {
  LinkedQueue<T> queue;
  if(stack.isEmpty()){
	return false;
  }
  while (!stack.isEmpty()) {
	queue.enqueue(stack.pop());
  }
  while (!queue.isEmpty()) {
    stack.push(queue.dequeue());
  }
  return true;
}

#endif // REVERSE_H
