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

// * -------------------------------- Problem Solution --------------------------------

Node* mergeTwoSortedLL(Node* &head1, Node* &head2) {

  if(head1->next == NULL) {
    head1->next = head2;
    return head1;
  }

  Node* curr1 = head1;
  Node* next1 = curr1->next;

  Node* curr2 = head2;
  Node* next2 = curr2->next;

  while(next1 != NULL && curr2 != NULL) {
    if((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
      curr1->next = curr2;
      next2 = curr2->next;
      curr2->next = next1;
      curr1 = curr2;
      curr2 = next2;
    } else {
      // * curr1 & next1 ko aage badhana padega
      curr1 = next1;
      next1 = next1->next;

      if(next1->next == NULL) {
        next1 = curr2;
        return head1;
      }

    }
  }

  return head1;
}

int main() {
  Node* tail1 = NULL;
  Node* head1 = NULL;
  insertAtHead(head1, tail1, 1);
  insertAtTail(head1, tail1, 4);
  insertAfterELement(head1, tail1, 4, 5);
  print(head1);

  Node* tail2 = NULL;
  Node* head2 = NULL;
  insertAtTail(head2, tail2, 2);
  insertAtTail(head2, tail2, 3);
  insertAtTail(head2, tail2, 5);
  print(head2);

  Node* newHead = NULL;
  if(head1->data <= head2->data) {
    newHead = mergeTwoSortedLL(head1, head2);
  } else {
    newHead = mergeTwoSortedLL(head2, head1);
  }
  print(newHead);

  return 0;
}