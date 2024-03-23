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
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<"\n";
}

// * Insert At head
Node* insertAtHead(Node* head, int val) {
  Node* newHead = new Node(val);
  newHead->next = head;
  return newHead;
}

// * Insert At Kth element
Node* insertAtK(Node* head, int pos, int val) {
  if(head == NULL) {
    if(pos == 1) {
      return new Node(val);
    }
  }
  int c = 0;
  Node* temp = head;
  while(temp) {
    c++;
    if(c == pos-1) {
      Node* newNode = new Node(val);
      newNode->next = temp->next;
      temp->next = newNode;
    }
    temp = temp->next;
  }
  return head;
}


int main() {
  std::vector<int> arr = { 1, 2, 3, 4, 5, 6 }; 

  Node* head = NULL;

  head = LLFromArray(arr);

  printLL(head);

  int pos;
  std::cout<<"Enter the index for insertion: "<<std::endl;
  std::cin>>pos;
  
  if(pos == 1) {
    // * Insert At Head
    head = insertAtHead(head, 7);
  }
  else {
    // * Insert a kth position
    head = insertAtK(head, pos, 7);
  }

  printLL(head);

  return 0;
}
