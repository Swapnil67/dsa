// * Design Stack Data Structure using Queue Data Structure

#include<iostream>
#include<queue>

class MyStack {
  public:
    std::queue<int> q;

    MyStack() {
    }

    void push(int x) {
      this->q.push(x);
    }

    int pop() {
      int popped_ele = this->q.back();
      std::queue<int> helper_q;
      while(!q.empty()) {
        if(q.front() != popped_ele) {
          helper_q.push(q.front());
          q.pop();
        }
      }
      this->q = helper_q;
      return popped_ele;
    }

    int top() {
      return this->q.back();
    }

    bool empty() {
      return q.empty();
    }
};

int main() {
  MyStack *st = new MyStack(4);
  return 0;
}

// * Run the code
// * $CXX --std=c++20 stack-via-queue.cpp -o output && ./output