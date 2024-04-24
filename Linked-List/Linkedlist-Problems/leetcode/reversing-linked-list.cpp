#include<iostream>

using namespace std;

class MyLinkedList {
  public:
    int data;
    MyLinkedList* next;
    MyLinkedList* head;
    MyLinkedList* tail;

    MyLinkedList() {
      this->data = NULL;
      this->next = NULL;
    }

    void print() {
      MyLinkedList* temp = head;
      while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<endl;
    }

    void addAtHead(int val) {
      MyLinkedList* new_node = new MyLinkedList;
      new_node->data = val;
      if(head == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->next = head;
        head = new_node;
      }
    } 
    
    void addAtTail(int val) {
      MyLinkedList* new_node = new MyLinkedList;
      new_node->data = val;

      if(tail == NULL) {
        tail = new_node; 
        head = new_node; 
      } else {
        tail->next = new_node;
        tail = new_node;
      }
    }
    
    void addAtIndex(int index, int val) {
      int length = 0;
      MyLinkedList* ptemp2 = head;
      while(ptemp2 != NULL) {
        length++;
        ptemp2 = ptemp2->next;
      }

      if(index > length) {
        return;
      }

      MyLinkedList* temp = head;

      if(index == 0 || temp == NULL) {
        this->addAtHead(val);
        return;
      }

      int c = 1;
      while(c<index) {
        c++;
        temp = temp->next;
      }

      if(temp->next == NULL) {
        this->addAtTail(val);
        return;
      }

      MyLinkedList* new_node = new MyLinkedList;
      new_node->data = val;
      new_node->next = temp->next;
      temp->next = new_node;
    }

    void reverse() {
      MyLinkedList* back = NULL;
      MyLinkedList* curr = head;
      MyLinkedList* forward = NULL;

      if(head == NULL) {
        cout<<"Linked list is empty"<<endl;
        return;
      }

      if(head->next == NULL) {
        cout<<"Linked list has single node"<<endl;
        return;
      }

      while(curr != NULL) {
        forward = curr->next;
        curr->next = back;
        back = curr;
        curr = forward;
      }

      head = back;
    }

    void recursiveReverse(MyLinkedList* &p) {
      MyLinkedList* q;
      // cout<<p<<" | "<<p->data<<endl;
      if(p->next == NULL) {
        head = p;
        return;
      }
      recursiveReverse(p->next);
      q = p->next;
      q->next = p;
      p->next = NULL;
    }

};

int main() {
  MyLinkedList* obj = new MyLinkedList();
  obj->addAtHead(10);
  obj->addAtTail(30);
  obj->addAtIndex(1,20);
  cout<<"Before Reversing"<<endl;
  obj->print();

  // * Iterative Reverse
  cout<<"After Reversing"<<endl;
  obj->reverse();
  obj->print();

  // * Recursive Reverse
  cout<<"Recursive Reverse"<<endl;
  MyLinkedList* curr = obj->head;
  obj->recursiveReverse(curr);
  obj->print();

  return 0;
}