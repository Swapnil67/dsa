/*
 * Leetcode - 622 
 * Design Circular Queue
 * Design your implementation of the circular queue. The circular queue is a linear data structure in which 
 * the operations are performed based on FIFO (First In First Out) principle, and the last position is 
 * connected back to the first position to make a circle. It is also called "Ring Buffer".
 * 
 * One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
 * In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space
 * in front of the queue. But using the circular queue, we can use the space to store new values.
 * 
 * https://leetcode.com/problems/design-circular-queue/description/
*/

#include <vector>
#include <iostream>

class MyCircularQueue {
  struct DLLNode {
    int data;
    DLLNode* next; 
    DLLNode* prev; 

    DLLNode(int val) {
      data = val;
      next = nullptr;
      prev = nullptr;
    }
  };

  int queue_size;
  int queue_capacity;
  DLLNode *head, *tail;

public:
  MyCircularQueue(int k) {
    queue_size = 0;
    queue_capacity = k;

    head = new DLLNode(-1);
    tail = new DLLNode(-1);
    head->next = tail;
    tail->prev = head;
  }

  // * Insert element at the end of DLL
  bool enQueue(int value) {
    if (queue_size == queue_capacity)
      return false;

    DLLNode* tailBack = tail->prev;

    DLLNode *newNode = new DLLNode(value);
    tailBack->next = newNode;
    newNode->prev = tailBack;
    
    newNode->next = tail;
    tail->prev = newNode;

    queue_size++;
    return true;
  }
  
  bool deQueue() {
    if (queue_size == 0)
      return false;

    DLLNode* removeNode = head->next;

    DLLNode *back = removeNode->prev;
    DLLNode *front = removeNode->next;

    back->next = front;
    front->prev = back;

    queue_size--;
    return true;
  }
  
  int Front() {
    if (queue_size == 0)
      return -1;

    return head->next->data;
  }
  
  int Rear() {
    if (queue_size == 0)
      return -1;

    return tail->prev->data; 
  }
  
  bool isEmpty() {
    return queue_size == 0;        
  }
  
  bool isFull() {
    return queue_size == queue_capacity;
  }
};

int main(void) {
  // MyCircularQueue *myCircularQueue = new MyCircularQueue(3);
  // myCircularQueue->enQueue(1);                         // return True
  // myCircularQueue->enQueue(2);                         // return True
  // myCircularQueue->enQueue(3);                         // return True
  // myCircularQueue->enQueue(4);                         // return False
  // int ans = myCircularQueue->Rear();                   // return 3
  // std::cout << "Rear value : " << ans << std::endl;
  // bool isFull = myCircularQueue->isFull();             // return True
  // std::cout << "Is Full " << isFull << std::endl;
  // myCircularQueue->deQueue();                          // return True
  // myCircularQueue->enQueue(4);                         // return True
  // ans = myCircularQueue->Rear();                       // return 4
  // std::cout << "Rear value : " << ans << std::endl;
  
  MyCircularQueue *myCircularQueue = new MyCircularQueue(3);
  myCircularQueue->enQueue(1);                      // return True
  int ans = myCircularQueue->Rear();                // return 3
  std::cout << "Rear value : " << ans << std::endl;
  bool isFull = myCircularQueue->isFull();          // return True
  std::cout << "Is Full " << isFull << std::endl;
  myCircularQueue->deQueue();                       // return True
  myCircularQueue->enQueue(4);                      // return True
  ans = myCircularQueue->Rear();                // return 4
  std::cout << "Rear value : " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 25-design-circular-queue.cpp -o output && ./output
