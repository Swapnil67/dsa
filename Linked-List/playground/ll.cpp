#include <iostream>
using namespace std;

class Node {
  public: 
    int data;
    Node* next;

    Node() {
      this->data = NULL;
      this->next = NULL;
    }
};

void printLL(Node* &head) {
  Node* temp = head;

  if(temp == NULL) {
    cout<<"Linked List is empty"<<endl;;
    return;
  }

  while(temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;

}

void insertAtHead(Node* &head, Node* &tail, int val) {
  Node* new_node = new Node();
  new_node->data = val;

  if(head == NULL) {
    head = new_node;
    tail = new_node;
    return;
  }

  new_node->next = head;
  head = new_node;
  return;
}

void insertAtTail(Node* &head, Node* &tail, int val) {
  Node* new_node = new Node();
  new_node->data = val;

  if(tail == NULL) {
    head = new_node;
    tail = new_node;
    return;
  }

  tail->next = new_node;
  tail = new_node;
  return;
}

void insertAPosition(Node* &head, Node* &tail, int pos, int val) {

  if(pos == 0) {
    insertAtHead(head, tail, val);
    return;
  }

  Node* temp = head;

  int c = 0;
  while(c < pos-1) {
    temp = temp->next;
    c++;
  }

  if(temp->next == NULL) {
    insertAtTail(head, tail, val);
    return;
  }

  Node* new_node = new Node();
  new_node->data = val;

  new_node->next = temp->next;
  temp->next = new_node;

  return;
}

// TODO
void deleteAtPosition(Node* &head, Node* &tail, int pos, int val) {

  if(pos == 0) {
    head = head->next;
    return;
  }

  Node* temp = head;

  int c = 0;
  while(c < pos-1) {
    temp = temp->next;
    c++;
  }

  if(temp->next == NULL) {
    insertAtTail(head, tail, val);
    return;
  }

  Node* new_node = new Node();
  new_node->data = val;

  new_node->next = temp->next;
  temp->next = new_node;

  return;
}


int main() {
  Node* head = NULL;
  Node* tail = NULL;
  cout<<"head "<<head<<endl;
  printLL(head);
  insertAtHead(head, tail, 1);
  printLL(head);
  insertAtTail(head, tail, 2);
  insertAtTail(head, tail, 3);
  printLL(head);
  insertAtHead(head, tail, 0);
  printLL(head);
  insertAPosition(head, tail, 0, -1);
  printLL(head);
  insertAPosition(head, tail, 3, 10);
  insertAPosition(head, tail, 6, 20);
  printLL(head);


  return 0;
}