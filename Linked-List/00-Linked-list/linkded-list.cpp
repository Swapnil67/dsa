#include <iostream>
#include <map>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

  // * constructor
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

  // * Destructor
  ~Node() {
    int value = this->data;
    if(this->next != NULL) {
      delete next;
      next = NULL;
    }
    cout<< "Memory is free for node with data "<<value<<endl;
  }

};

void insertAtHead(Node* &head, int data) {
  // * Create new node
  Node* new_node = new Node(data);
  new_node->next = head;

  // * Point head to new node
  head = new_node;
}

void insertAtTail(Node* &tail, int data) {
  Node* new_node = new Node(data);
  tail->next = new_node;
  tail = new_node;
}

void print(Node* &head) {
  if(head == NULL) {
    cout<<"Linked list is empty\n";
    return;
  }
  Node* temp = head;
  while(temp != NULL) {
    cout<<"Data "<<temp->data<<" | Addr "<<temp<<endl;
    temp = temp->next;
  }
}

void insertAtPosition(Node* &tail, Node* &head, int pos, int data) {
  if(pos == 0) {
    insertAtHead(head, data);
    return;
  }

  Node* new_node = new Node(data);
  Node* temp = head;

  int c = 0;
  while(c < pos) {
    c++;
    temp = temp->next;
  }
  // cout<<c<<" | "<<temp<<endl;;

  // * Inserting at last postion
  if(temp->next == NULL) {
    insertAtTail(tail, data);
    return;
  }

  new_node->next = temp->next;
  temp->next = new_node;
}

void deleteAtPosition(Node* &head, Node* &tail, int pos) {
  if(pos == 0) {
    Node* temp = head;
    head = head->next;
    // * free memory of previous head
    delete temp;
  } else {
    int c = 0;
    Node* prev = NULL;
    Node* curr = head;
    while(c < pos) {
      prev = curr;
      curr = curr->next;
      c++;
    }
    // cout<<"\nprev: "<<prev<<" | prev->next: "<<prev->next<<" | prev->data: "<<prev->data<<endl;
    // cout<<"\ncurr: "<<curr<<" | curr->next: "<<curr->next<<" | curr->next: "<<curr->next<<endl;
    prev->next = curr->next;
    if(curr->next == NULL) {
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

// * Detect Circular Linked List
bool isCircular(Node* &head) {
  if(head == NULL) {
    return true;
  }

  Node* temp = head->next;
  while(temp != NULL && temp != head) {
    temp = temp->next;
  }

  if(temp == head) {
    return true;
  }

  return false;
}

// * Detect Loop in Linked List
bool detectLoop(Node* &head) {
  if(head == NULL) 
    return false;

  map<Node*, bool> visited;

  Node* temp = head;
  while(temp != NULL) {  
    if(visited[temp] == true) {
      return true;
    }
    visited[temp] = true;
    temp = temp->next;
  }

  return false;
}


int main() {
  // * Created a initial node
  Node* node1 = new Node(20);

  // * Point head to new node
  Node* head = node1;
  Node* tail = node1;

  insertAtHead(head, 10);
  insertAtHead(head, 0);

  insertAtTail(tail, 40);

  insertAtPosition(tail, head, 3, 30);
  insertAtPosition(tail, head, 0, 11);
  insertAtPosition(tail, head, 5, 50);
  print(head);

  cout<<" ======================================== \n";

  deleteAtPosition(head, tail, 6);

  print(head);

  if(isCircular(tail)) {
    cout<<"Linked List is circular in nature\n";
  } else {
    cout<<"Linked List is not circular in nature\n";
  }

  if(detectLoop(tail)) {
    cout<<"Loop detected in Linked List\n";
  } else {
    cout<<"Loop not detected in Linked List\n";
  }

  return 0;
}
