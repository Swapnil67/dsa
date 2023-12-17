#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev; 

  // * Constructor
  Node(int d) {
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
  }

  // * Destructor
  ~Node() {
    int val = this->data;
    if(next != NULL) {
      delete next;
      next = NULL;
    }
    cout<<"Memory free for node with data "<<val<<endl;
  }

};

// * Traversal of LL
void print(Node* &head) {
  Node* temp = head;
  while(temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

// * Length of LL
int getLength(Node* &head) {
  Node* temp = head;
  int l = 0;
  while(temp != NULL) {
    l++;
    temp = temp->next;
  }
  return l;
}

// * Insert at head
void insertAtHead(Node* &head, Node* &tail, int d) {
  // * Empty Linked List
  if(head == NULL) {
    Node* new_node = new Node(d);
    head = new_node;
    tail = new_node;
  } else {
    Node* new_node = new Node(d);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
} 

// * Insert at tail
void InsertAtTail(Node* &tail, Node* &head, int d) {
  // * Empty Linked List
  if(tail == NULL) {
    Node* new_node = new Node(d);
    tail = new_node;
    head = new_node;
  } else {
    Node* new_node = new Node(d);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

}

// * Insert at index
void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {

  if(pos < 0) {
    cout<<"Invalid index for insertion\n";
    return;
  }
  
  // * If pos is 0, Insert at head
  if(pos == 0) {
    insertAtHead(head, tail, d);
    return;
  }

  int c = 0;
  Node* temp = head;

  while(c<pos-1) {
    c++;
    temp = temp->next;
  }

  // * Pointing at last node
  if(temp->next == NULL) {
    InsertAtTail(tail, head, d);
    return;
  }

  // * Insert in middle
  Node* new_node = new Node(d);
  new_node->next = temp->next;
  temp->next->prev = new_node;
  temp->next = new_node;
  new_node->prev = temp;

}

// * Delete at index
void deleteAtPosition(Node* &head, Node* &tail, int pos) {

  Node* temp = head;

  // * If pos is 0, delete at head
  if(pos == 0) {
    if(head != NULL) {
      temp->next->prev = NULL;
      head = head->next;
      temp->next = NULL;
      delete temp;
    } else {
      cout<<"Linked List is empty";
    }
    return;
  }

  int c = 0;
  while(c<pos) {
    c++;
    temp = temp->next;
  }

  // * Delete in middle
  temp->next->prev = temp->prev;
  temp->prev->next = temp->next;
  return;
}

int main() {
  // Node* node1 = new Node(10);
  Node* head = NULL;
  Node* tail = NULL;
  cout<<"------------------------------ InsertAtHead ---------------------------------\n";
  insertAtHead(head, tail, 9);
  insertAtHead(head, tail, 8);
  print(head);
  cout<<"------------------------------ InsertAtTail ---------------------------------\n";
  InsertAtTail(tail, head, 11);
  InsertAtTail(tail, head, 12);
  print(head);
  cout<<"------------------------------ insertAtPosition ---------------------------------\n";
  insertAtPosition(head, tail, 2, 7);
  insertAtPosition(head, tail, 0, 101);
  insertAtPosition(head, tail, 6, 100);
  print(head);
  cout<<"------------------------------ deleteAtPosition ---------------------------------\n";
  deleteAtPosition(head, tail, 0); 
  deleteAtPosition(head, tail, 3);
  print(head);

  return 0;
}