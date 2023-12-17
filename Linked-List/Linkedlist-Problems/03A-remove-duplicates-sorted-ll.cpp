// * Remove duplicates from a sorted linked list.

#include<iostream>
#include<map>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* tail;


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

void insertAtHead(Node* &head, Node* &tail, int val) {
  Node* new_ele = new Node(val);
  if(tail == NULL) {
    head = new_ele;
    tail = new_ele;
  } else {
    new_ele->next = tail->next;
    tail->next = new_ele;
  }
}

void insertAtTail(Node* &head, Node* &tail, int val) {
  Node* new_ele = new Node(val);
  if(head == NULL) {
    head = new_ele;
    tail = new_ele;
    return;
  }

  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_ele;
  tail = new_ele;
}

void insertAfterELement(Node* &head, Node* &tail, int ele, int val) {
  // * Assuming that the element is present in the list

  // * Empty list
  if(head == NULL) {
    Node* new_node = new Node(val);
    head = new_node;
    tail = new_node;
    new_node->next = new_node;
  } else {
    // * Non Empty list
    Node* cur = head;
    while(cur->data != ele) {
      cur = cur->next;
    }
    if(cur->next == NULL) {
      insertAtTail(head, tail, val);
      return;
    }
    Node* new_node = new Node(val);
    // cout<<cur->next<<" "<<cur->data<<endl;
    new_node->next = cur->next;
    cur->next = new_node;
  }
}

void print(Node* &head) {
  Node* cur = head;
  if(head == NULL) {
    cout<<"Linked List is empty\n";
    return;
  }

  while(cur != NULL) {
    cout<<cur->data<<" ";
    cur = cur->next;
  }
  cout<<endl;
}

// * Time Complexity = O(n)
// * Space Complexity = O(1)
void removeDuplicates(Node* &head) {
  if(head == NULL) {
    cout<<"Linked List is empty\n";
    return;
  }
  Node* cur = head;
  while(cur->next != NULL) {
    if(cur->data == cur->next->data) {
      Node* next_node = cur->next->next;
      Node* delete_node = cur->next;
      cur->next = next_node;
    } else {
      cur = cur->next;
    }
  }
}

int main() {
  Node* tail = NULL;
  Node* head = NULL;
  insertAtHead(head, tail, 10);
  insertAtTail(head, tail, 30);
  insertAfterELement(head, tail, 10, 20);
  insertAfterELement(head, tail, 20, 20);
  insertAtTail(head, tail, 40);
  insertAtTail(head, tail, 40);
  print(head);
  removeDuplicates(head);
  print(head);
  return 0;
}