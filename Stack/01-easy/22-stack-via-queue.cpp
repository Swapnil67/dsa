/*
* Leetcode - 225 
* Design Stack Data Structure using Queue Data Structure
* 
* https://leetcode.com/problems/implement-stack-using-queues
*/

// ! Google

#include<iostream>
#include<queue>

class MyStack {
  public:
    std::queue<int> q;

    void push(int x) {
      this->q.push(x);
    }

    int pop() {
      if(q.empty()) {
        printf("Stack is empty\n");
        return -1;
      }

      int popped_ele = this->q.back();

      std::queue<int> helper_q;
      while(!q.empty()) {
        if(q.front() != popped_ele) {
          helper_q.push(q.front());
        }
        q.pop();
      }
      this->q = helper_q;
      return popped_ele;
    }

    int top() {
      if(q.empty()) {
        printf("Stack is empty\n");
        return -1;
      }
      return this->q.back();
    }

    bool empty() {
      return this->q.empty();
    }
};

int main() {
  MyStack *st = new MyStack();
  st->push(1);
  std::cout << "Top: " << st->top() << std::endl;
  std::cout << "Is empty: " << st->empty() << std::endl;
  st->pop();
  st->push(2);
  std::cout << "Top: " << st->top() << std::endl;
  st->pop();
  st->push(3);
  std::cout << "Top: " << st->top() << std::endl;
  st->pop();
  std::cout << "Is empty: " << st->empty() << std::endl;
  return 0;
}

// * Run the code
// * $CXX --std=c++20 stack-via-queue.cpp -o output && ./output