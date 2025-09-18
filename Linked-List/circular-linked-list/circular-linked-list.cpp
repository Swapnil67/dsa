#include<iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *tail;

  // * Constructor
  Node(int d) {
    this->data = d;
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

void insertAtHead(Node* &tail, int val) {
  Node* new_ele = new Node(val);
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
  Node* new_ele = new Node(val);
  if(tail == NULL) {
    tail = new_ele;
    new_ele->next = new_ele; 
    return;
  }

  new_ele->next = tail->next;
  tail->next = new_ele;
}

void insertAfterELement(Node* &tail, int ele, int val) {
  // * Assuming that the element is present in the list

  // * Empty list
  if(tail == NULL) {
    Node* new_node = new Node(val);
    tail = new_node;
    new_node->next = new_node;
  } else {
    // * Non  Empty list
    Node* new_node = new Node(val);
    Node* cur = tail;
    while(cur->data != ele) {
      cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
  }
}

void deleteAtELement(Node* &tail, int ele) {
  // * Assuming that the element is present in the listm 

  // * Empty list
  if(tail == NULL) {
    cout<<"List is empty please check again"<<endl;
    return;
  } else {
    // * Non Empty list
    Node* prev = tail;
    Node* cur = prev->next;
    while(cur->data != ele) {
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;

    if(cur == prev) {
      // * LL with single node
      tail = NULL;
      return;
    } else if(tail == cur) {
      // * LL with atleast 2 elements
      tail = prev;
    }
    cur->next = NULL;
    delete cur;
  }
}

void deleteAtIndex(Node* &tail, int index) {
  if (tail == NULL && index > 0) {
    cout<<"Linked List index out or range\n";
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

void print(Node* &tail) {
  Node* cur = tail;
  if(tail == NULL) {
    cout<<"Linked List is empty\n";
    return;
  }

  do {
    cout<<cur->data<<" ";
    cur = cur->next;
  } while (cur != tail);
  cout<<endl;
  
}

int main() {
  Node* tail = NULL;
  insertAfterELement(tail, 10, 1);
  print(tail);

  insertAfterELement(tail, 1, 2);
  print(tail);

  insertAfterELement(tail, 2, 3);
  print(tail);

  insertAfterELement(tail, 3, 5);
  print(tail);

  // insertAfterELement(tail, 3, 4);
  // print(tail);

  // deleteAtELement(tail, 5);
  // print(tail);

  return 0;
}