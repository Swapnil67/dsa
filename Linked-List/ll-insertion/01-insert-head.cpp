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

// * LL from Array
Node* LLFromArray(std::vector<int>arr) {
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
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<"\n";
}

Node* insertAtHead(Node* head, int val) {
  Node* newHead = new Node(val);
  newHead->next = head;
  return newHead;
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5,7 };
  Node* head = NULL;

  // * Create a LL from vector
  head = LLFromArray(arr);

  std::cout<<"Before Insertion"<<std::endl;
  // * Traverse LL
  printLL(head);

  // * Insert at head
  head = insertAtHead(head, 0);
  
  // * Traverse LL
  std::cout<<"After Insertion"<<std::endl;
  printLL(head);

  return 0;
}
