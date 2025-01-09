// * Implement Queue via array
// * https://www.naukri.com/code360/problems/implement-queue-using-arrays_8390825

#include<iostream>
#include<vector>

class Queue {
  public: 
    int front, rear, cur_size;
    std::vector<int> arr;
    Queue() {
      this->front = 0;
      this->rear = 0;
      this->cur_size = 0;
      this->arr.resize(100001);
    }

    // * Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e) {
      if(this->rear == 100001) {
        printf("Queue if full\n");
        return;
      } 
      this->arr[rear] = e;
      this->rear++;
      this->cur_size++;
    }

    // * Dequeue (retrieve) the element from the front of the queue.
    int dequeue() {
      if(this->front == this->rear) 
        return -1;
      int x = this->arr[this->front];
      this->front++;
      this->cur_size--;
      return x;
    }

    // * Size of the queue.
    int size() {
      return this->cur_size;
    }

};

int main() {
  Queue *q = new Queue();
  q->enqueue(2);
  q->enqueue(7);
  std::cout << "Front: " << q->dequeue() << std::endl;
  q->enqueue(13);
  std::cout << "Queue Size: " << q->size() << std::endl;
  std::cout << "Front: " << q->dequeue() << std::endl;
  std::cout << "Front: " << q->dequeue() << std::endl;
  std::cout << "Front: " << q->dequeue() << std::endl;
  std::cout << "Queue Size: " << q->size() << std::endl;
  return 0;
}


// * Run the code
// * $CXX --std=c++20 queue-via-array.cpp -o output && ./output