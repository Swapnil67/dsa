// * Implement Queue via array
// * https://www.naukri.com/code360/problems/implement-queue-using-arrays_8390825

#include<iostream>
#include<vector>

class Queue {
  private: 
    int max_size;
  public: 
    int front, rear, cur_size;
    std::vector<int> arr;
    Queue() {
      this->front = -1;
      this->rear = -1;
      this->cur_size = 0; 
      this->max_size = 100001;
      this->arr.resize(this->max_size);
    }

    // * Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e) {
      if(this->cur_size == this->max_size) {
        printf("Queue if full\n");
        return;
      } 
      else if(this->cur_size == 0) {
        // * first push
        this->front = 0;
        this->rear = 0;
      } else {
        // * if rear reaches this->max_size
        // * then this->rear % this->max_size = 0
        // * i.e. start from zero again
        this->rear = (this->rear + 1) % this->max_size;
      }
      this->arr[rear] = e;
      this->cur_size += 1;
    }

    // * Dequeue (retrieve) the element from the front of the queue.
    int dequeue() {
      if(this->cur_size == 0) {
        printf("\nQueue is empty\n");
        return -1;
      }
      // std::cout << this->front << " " << this->rear << std::endl;
      int x = this->arr[this->front];
      if (this->cur_size == 1) {
        // * Only one element in queue
        // * Destorying the queue
        this->front = -1;
        this->rear = -1;
      }
      else {
        this->front = (this->front + 1) % this->max_size;
      }
      this->cur_size -= 1;
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