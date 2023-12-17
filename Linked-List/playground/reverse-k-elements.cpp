#include<iostream>

using namespace std;

class LinkedList {
  public:
    int data;
    LinkedList* next;
    LinkedList* head;
    LinkedList* tail;

    LinkedList() {
      this->data = NULL;
      this->next = NULL;
    }

    void print() {
      LinkedList* temp = head;
      while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<endl;
    }

    void addAtHead(int val) {
      LinkedList* new_node = new LinkedList;
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
      LinkedList* new_node = new LinkedList;
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
      LinkedList* ptemp2 = head;
      while(ptemp2 != NULL) {
        length++;
        ptemp2 = ptemp2->next;
      }

      if(index > length) {
        return;
      }

      LinkedList* temp = head;

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

      LinkedList* new_node = new LinkedList;
      new_node->data = val;
      new_node->next = temp->next;
      temp->next = new_node;
    }

    LinkedList* reverseKEle(LinkedList* &p, int k) {

      if(p == NULL) {
        return NULL;
      }

      LinkedList* back = NULL;
      LinkedList* curr = p;
      LinkedList* forward = NULL;
      int c = 0;

      // * Step 1: Reverse first k nodes
      while (curr != NULL && c < k) {
        forward = curr->next;
        curr->next = back;
        back = curr;
        curr = forward;
        c++;
      }

      // * Recursion dekh lega aageka
      if(forward != NULL) {
        head->next = reverseKEle(forward, k);
      }

      return back;
    }

};

int main() {
  LinkedList* obj = new LinkedList();
  obj->addAtHead(10);
  obj->addAtTail(30);
  obj->addAtIndex(1,20);
  obj->addAtTail(40);
  cout<<"Before Reversing"<<endl;
  obj->print();

  // * Iterative Reverse
  cout<<"After Reversing"<<endl;
  LinkedList* back = obj->reverseKEle(obj->head, 2);
  obj->head = back;
  obj->print();

  // // * Recursive Reverse
  // cout<<"After Reversing"<<endl;
  // obj->recursiveReverse(obj->head);
  // obj->print();

  return 0;
}