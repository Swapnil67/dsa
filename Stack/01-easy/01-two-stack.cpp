// ? Design a DS, which represents two stacks using only one array common for both stacks.

#include<iostream>
using namespace std;

class TwoStack {
  public:
    int *stack;
    int top1;
    int top2;
    int size;

  TwoStack(int s) {
    this->stack = new int[s];
    this->size = s;
    this->top1 = -1;
    this->top2 = s;
  } 

  // * Push to stack 1 [O(1)]
  void push1(int val) {
    if(top2 - top1 > 1) {
      top1++;
      stack[top1] = val;
    } else {
      cout<<"Stack 1 overflow"<<endl;
      return;
    }
  }

  // * Push to stack 2 [O(1)]
  void push2(int val) {
    if(top2 - top1 > 1) {
      top2--;
      stack[top2] = val;
    } else {
      cout<<"Stack 2 overflow"<<endl;
      return;
    }
  }

  // * Pop from stack 1 [O(1)]
  int pop1() {
    if(top1 >= 0) {
      int popped = stack[top1];
      top1--;
      return popped;
    } else {
      cout<<"Stack 1 underflow"<<endl;
      return -1;
    }
  }

  // * Pop from stack 2 [O(1)]
  int pop2() {
    if(top2 < size) {
      int popped = stack[top2];
      top2++;
      return popped;
    } else {
      cout<<"Stack 2 underflow"<<endl;
      return -1;
    }
  }

  // * Time complexity O(n)
  void printStack1() {
    for(int i=top1; i>=0; i--) {
      cout<<stack[i]<<" ";
    }
    cout<<endl;
  }

  // * Time complexity O(n)
  void printStack2() {
    for(int i=top2; i<size; i++) {
      cout<<stack[i]<<" ";
    }
    cout<<endl;
  }

};

int main() {
  TwoStack* s = new TwoStack(6);
  s->push1(10);
  s->push1(20);
  s->push1(30);

  s->push2(40);
  s->push2(50);
  s->push2(60);

  cout<<"---------- Stack1 ---------- \n";
  s->printStack1();  
  cout<<"---------- Stack2 ---------- \n";
  s->printStack2();  

  cout<<"------------- pop1 ----------------\n";
  int sp1 = s->pop1();
  cout<<"Stack 1 popped value "<<sp1<<endl;
  s->printStack1(); 
  
  cout<<"------------- pop2 ----------------\n";
  int sp2 = s->pop2();
  cout<<"Stack 2 popped value "<<sp2<<endl;
  s->printStack2();  


  return 0;
}
