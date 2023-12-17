// ? Design Stack Data Structure using Linked List Data Structure

#include<iostream>
using namespace std;

class Stack {
  public:
    int data;
    Stack* head;
    Stack* next;

  Stack(int val) {
    this->data = val;
    this->head = NULL;
  }

  // * Push to stack [O(1)]
  void push(int val) {
    Stack* node = new Stack(val);
    node->next = head;
    head = node;
  }

  // * pop from stack [O(1)]
  int pop() {
    if(head == NULL) {
      return -1;
    }
    int popped = head->data;
    head = head->next;
    return popped;
  }

  // * Return top of stack [O(1)]
  int peek() {
    if(head == NULL) {
      return -1;
    }
    return head->data;
  }

  // * Print stack [O(n)]
  void printStack() {
    Stack* temp = head;
    while(temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }

};

int main() {
  Stack* s = new Stack(10);
  s->push(10);
  s->push(20);
  s->push(30);

  cout<<"---------- Stack ---------- \n";
  s->printStack();

  cout<<"--------------------------- \n";
  cout<<"Current Top: "<<s->peek()<<endl;

  int p1 = s->pop();
  cout<<"Stack popped value "<<p1<<endl;
  int p2 = s->pop();
  cout<<"Stack popped value "<<p2<<endl;

  cout<<"Current Top: "<<s->peek()<<endl;

  return 0;
}

/*
* Note:
* There will be no stack overflow condition in stack data structure
* when implemented using linked list approach
*/