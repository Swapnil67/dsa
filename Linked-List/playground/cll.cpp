#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* tail;

  Node() {
    this->data = NULL;
    this->next = NULL;
  }

};

void print(Node* &tail) {
  Node* temp = tail;
  if(temp == NULL) {
    cout<<"Linked List is empty\n";
    return;
  }
  do {
    temp = temp->next;
    cout<<temp->data<<" ";
  } while(temp != tail);
  cout<<endl;
}

void insertAtHead(Node* &tail, int val) {
  Node* new_ele = new Node();
  new_ele->data = val;

  if(tail == NULL) {
    tail = new_ele;
    new_ele->next = new_ele;
    return;
  } else {
    new_ele->next = tail->next;
    tail->next = new_ele;
    return;
  }
}

void insertAtTail(Node* &tail, int val) {
  Node* new_ele = new Node();
  new_ele->data = val;
  if(tail == NULL) {
    tail = new_ele;
    new_ele->next = new_ele; 
    return;
  }

  new_ele->next = tail->next;
  tail->next = new_ele;
}

void deletionAtIndex(Node* &tail, int index) {
  if (tail == NULL && index > 0) {
    cout<<"Linked List index out or range\n";
    return;
  }

  if(tail == tail->next) {
    cout<<"Linked List with single element\n";
    tail = NULL;
    return;
  }

  Node* temp = tail;
  int c = 0;
  do {
    temp = temp->next;
    c++;
  } while(c < index && temp != tail);

  // cout<<temp->data<<" "<<temp->next<<" "<<temp->next->data<<endl;

  if(temp->next == tail) {
    tail = temp;
  }

  temp->next = temp->next->next;

  // cout<<temp->data<<" "<<temp->next<<" "<<temp->next->data<<endl;
}

int main() {
  Node* tail = NULL;
  // print(tail);

  // insertAtHead(tail, 5);
  // insertAtHead(tail, 4);
  // insertAtHead(tail, 3);
  // insertAtHead(tail, 2);
  insertAtHead(tail, 1);

  print(tail);

  deletionAtIndex(tail, 4);

  print(tail);


  return 0;
}