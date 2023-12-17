#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* head;
    Node* tail;

    Node() {
      this->data = NULL;
      this->next = NULL;
    }

    void print() {
      Node* temp = head;
      while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<endl;
    }

    void addAtHead(int val) {
      Node* new_node = new Node;
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
      Node* new_node = new Node;
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
      Node* ptemp2 = head;
      while(ptemp2 != NULL) {
        length++;
        ptemp2 = ptemp2->next;
      }

      if(index > length) {
        return;
      }

      Node* temp = head;

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

      Node* new_node = new Node;
      new_node->data = val;
      new_node->next = temp->next;
      temp->next = new_node;
    }

    int length() {
      Node* temp = head;
      int length = 0;
      while(temp != NULL) {
        temp = temp->next;
        length++;
      }
      return length;
    }

    void middleNode(int length) {
      int mid = length/2, c = 0;
      Node* temp = head;
      while(c<mid) {
        c++;
        temp = temp->next;
      } 
      cout<<"Middle Node: "<<temp->data<<endl;
    }

    int middleNodeOptimized() {
      Node* temp = head;
      if(temp == NULL && temp->next == NULL) {
        return head->data;
      }

      Node* slow = head;
      Node* fast = head->next;
      while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
          fast = fast->next;
        }
        slow = slow->next;
      } 
      return slow->data;
    }

};

int main() {
  Node* obj = new Node();
  obj->addAtHead(10);
  obj->addAtTail(30);
  obj->addAtIndex(1,20);
  obj->addAtIndex(1,15);
  obj->addAtTail(40);
  obj->addAtTail(50);
  obj->print();

  // * Get the middle node
  int length = obj->length();
  cout<<"Length of Linked list: "<<length<<endl;

  // * Get the middle node
  obj->middleNode(length);

  cout<<"------------------- Optimized -------------------"<<endl;

  // * Optimized Solution for middle node
  int mid = obj->middleNodeOptimized();
  cout<<"Middle Node:: "<<mid<<endl;


  return 0;
}