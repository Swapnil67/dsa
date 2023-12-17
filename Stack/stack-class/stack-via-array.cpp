// ? Design Stack Data Structure using Array Data Structure

#include<iostream>
using namespace std;

class Stack {
  public:
    int *stack;
    int top;
    int size;

    Stack(int size) {
      this->size = size;
      stack = new int[size];
      this->top = -1;
    }

    // * Time complexity O(1)
    void push(int val) {
      // cout<<"Top "<<top<<endl;
      if(top == size-1) {
        cout<<"Stack overflow"<<endl;
        return;
      }
      top++;
      stack[top] = val;
    }

    // * Time complexity O(1)
    void pop() {
      if(top == -1) {
        cout<<"Stack is empty"<<endl;
      }
      top--;
    }

    // * Time complexity O(1)
    int peek() {
      if(top >= 0) {
        return stack[top];
      } else {
        cout<<"Stack is empty"<<endl;
        return -1;
      }
    }

    // * Time complexity O(1)
    bool empty() {
      if(top == -1)
        return true;
      else 
        return false;
    }

    // * Time complexity O(n)
    void print() {
      for(int i=top; i>=0; i--) {
        cout<<stack[i]<<" ";
      }
      cout<<endl;
    }

};

int main() {
  Stack* s = new Stack(5);
  s->push(10);
  s->push(20);
  s->push(30);
  s->push(40);
  s->push(50);
  // s->push(60); // * Stack Overflow

  cout<<"Current Stack\n";
  s->print();  

  cout<<"-------------------------------"<<endl;

  cout<<"Current Top: "<<s->peek()<<endl;
  s->pop();
  cout<<"Current Top: "<<s->peek()<<endl;
  cout<<"Is Empty: "<<s->empty()<<endl;
  s->pop();
  s->pop();
  s->pop();
  s->pop();
  if(s->empty()) {
    cout<<"Stack is empty"<<endl;
  }
  return 0;
}