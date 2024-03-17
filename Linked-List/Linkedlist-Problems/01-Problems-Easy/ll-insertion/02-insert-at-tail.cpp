#include<iostream>

class Node {
  public: 
    int data;
    Node* next;

  Node(int d) {
    this->data = d;
    this->next = NULL;
  }

};

// * LL From Array
Node* LLFromArray(std::vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

// * Traverse LL
void printLL(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<"\n";
}

Node* insertAtTail(Node* head, int val) {
  Node* newNode = new Node(val);
  if(head == NULL) {
    return newNode;
  }

  if(head->next == NULL) { 
    head->next = newNode;
    return head;
  }

  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}


int main() {
  std::vector<int>arr = { 1,2,3,4,5,6 };
  Node* head = NULL;
  
  // * LL From Array
  head = LLFromArray(arr);

  // * Traverse LL
  std::cout<<"Before Insertion"<<std::endl;
  printLL(head);

  // * Insert at tail
  head = insertAtTail(head, 7);

  // * Traverse LL
  std::cout<<"After Insertion"<<std::endl;
  printLL(head);
  return 0;
}
