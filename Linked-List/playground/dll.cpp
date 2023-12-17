#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;
  
  Node(int d) {
    this->data = d;
    this->next = NULL;
    this->prev = NULL;
  }
};

void print(Node* &head) {
  Node* temp = head;

  if(head == NULL) {
    cout<<"Linked list is empty\n";
    return;
  }

  while(temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int length(Node* &head) {
  Node* temp = head;

  if(head == NULL) {
    return 0;
  }
  int c = 0;
  while(temp != NULL) {
    temp = temp->next;
    c++;
  }
  return c;
}

void insertAtHead(Node* &head, int val) {
  Node* new_node = new Node(val);
  if(head == NULL) {
    head = new_node;
    return;
  }

  new_node->next = head;
  head->prev = new_node;
  head = new_node;
}

void insertAtTail(Node* &head, int val) {
  Node* new_node = new Node(val);
  if(head == NULL) {
    insertAtHead(head, val);
    return;
  }

  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  new_node->prev = temp;
  temp->next = new_node;
}

void insertAtPosition(Node* &head, int pos, int val) {

  if(pos < 0) {
    cout<<"Invalid index for insertion\n";
    return;
  }
  
  if(pos == 0) {
    insertAtHead(head, val);
    return;
  } 

  int len = length(head);
  // cout<<"Current Length "<<len<<endl;;
  if(pos > (len+1)) {
    cout<<"Linked list has only "<<len<<" elements"<<endl;
    return;
  } else if(len == pos) {
    insertAtTail(head, val);
    return;
  }

  int c = 0;
  Node* temp = head;
  while(c<pos) {
    temp = temp->next;
    c++;
  }

  Node* new_node = new Node(val);
  new_node->next = temp;
  new_node->prev = temp->prev;
  temp->prev->next = new_node;
  temp->prev = new_node;
  return;
}

void deleteAtPosition(Node* &head, int pos) {
  Node* temp = head;

  if(pos < 0) {
    cout<<"Invalid index for deletion\n";
    return;
  } else if(pos == 0) {
    if(head == NULL) {
      cout<<"Linked list is empty for deletion\n";
      return;
    }
    temp->next->prev = NULL;
    head = head->next;
    temp->next = NULL;
    return;
  }

  int len = length(head);
  if(pos > len) {
    cout<<"Deletion index does not exists"<<endl;
    return;
  }
  
  int c = 0;
  while(c<pos) {
    c++;
    temp = temp->next;
  }

  temp->next->prev = temp->prev;
  temp->prev->next = temp->next;

  return;
}


int main() {
  Node* head = NULL;

  cout<<"------------------------------ InsertAtHead ---------------------------------\n";
  insertAtHead(head,  9);
  insertAtHead(head,  8);
  print(head);
  cout<<"------------------------------ InsertAtTail ---------------------------------\n";
  insertAtTail( head, 11);
  insertAtTail( head, 12);
  print(head);
  cout<<"------------------------------ insertAtPosition ---------------------------------\n";
  insertAtPosition(head, 2, 7);
  insertAtPosition(head, 0, 101);
  insertAtPosition(head, 6, 100);
  print(head);
  cout<<"------------------------------ deleteAtPosition ---------------------------------\n";
  deleteAtPosition(head, 0); 
  deleteAtPosition(head, 3);
  print(head);
  return 0;
}