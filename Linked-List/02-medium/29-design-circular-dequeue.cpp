/*
 * Leetcode - 641 
 * Design Circular Deque
 * 
 * https://leetcode.com/problems/design-circular-deque/description/
*/

#include <vector>
#include <iostream>

class MyCircularDeque {
  struct DLLNode {
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
      this->data = val;
      this->next = nullptr;
      this->prev = nullptr;
    }

    DLLNode(int val, DLLNode *next, DLLNode *prev) {
      this->data = val;
      this->next = next;
      this->prev = prev;
    }
  };

public:
  int size;
  int capacity;
  DLLNode *head = new DLLNode(-1);
  DLLNode *tail = new DLLNode(-1);

  MyCircularDeque(int k) {
    size = 0;
    capacity = k;
    head->next = tail;
    tail->prev = head;
  }

  bool insertFront(int value) {
    if (size == capacity)
      return false;

    DLLNode *head_next = head->next;
    DLLNode *new_node = new DLLNode(value);

    new_node->next = head_next;
    head_next->prev = new_node;

    new_node->prev = head;
    head->next = new_node;

    size++;
    return true;
  }

  bool insertLast(int value) {
    if (size == capacity)
      return false;

    DLLNode *tail_prev = tail->prev;
    DLLNode *new_node = new DLLNode(value);

    new_node->prev = tail_prev;
    tail_prev->next = new_node;

    new_node->next = tail;
    tail->prev = new_node;

    size++;
    return true;
  }

  bool deleteFront() {
    if (size == 0)
      return false;

    DLLNode *head_next = head->next;

    DLLNode *front = head_next->next;
    DLLNode *back = head_next->prev;

    front->prev = back;
    back->next = front;

    size--;
    return true;
  }

  bool deleteLast() {
    if (size == 0)
      return false;

    DLLNode *tail_prev = tail->prev;

    DLLNode *front = tail_prev->next;
    DLLNode *back = tail_prev->prev;

    front->prev = back;
    back->next = front;

    size--;
    return true;
  }

  int getFront() {
    return head->next->data;
  }

  int getRear() {
    return tail->prev->data;
  }

  bool isEmpty() {
    return size == 0;
  }

  bool isFull() {
    return size == capacity;
  }
};

int main(void) {
 MyCircularDeque* obj = new MyCircularDeque(5);
 std::cout << "Circular Deque" << std::endl;
 std::cout << "obj->insertFront(1):     " << obj->insertFront(1) << std::endl; // * return true
 std::cout << "obj->insertLast(2):      " << obj->insertLast(2) << std::endl;  // * return true
 std::cout << "obj->deleteFront():      " << obj->deleteFront() << std::endl;  // * return true
 std::cout << "obj->deleteLast():       " << obj->deleteLast() << std::endl;    // * return true
 std::cout << "obj->getFront():         " << obj->getFront() << std::endl;        // * return -1
 std::cout << "obj->getRear():          " << obj->getRear() << std::endl;          // * return -1
 std::cout << "obj->isEmpty():          " << obj->isEmpty() << std::endl;          // * return true
 std::cout << "obj->isFull():           " << obj->isFull() << std::endl;             // * return false

 return 0;
}

// * Run the code
// * g++ --std=c++20 29-design-circular-dequeue.cpp -o output && ./output