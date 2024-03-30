
/**
 * * Insert a node at head
 * 
 * * Example 1:
 * * Input: DLL = [1,2,3,4,5], val = 0
 * * Output: [0,1,2,3,4,5]
*/

#include<iostream>

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    // * Constructor
    Node(int d, Node* n, Node* p) {
      this->data = d;
      this->next = n;
      this->prev = p;
    }

    // * Constructor
    Node(int d) {
      this->data = d;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

// * ------------------- Utility Functions ---------------------

Node* arrayToDLL(std::vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* prev = head;
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i], nullptr, prev);
    prev->next = newNode;
    prev = newNode;
  }
  return head;
}

void printDLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

Node* insertAtHead(Node* head, int val) {
  Node* newHead = new Node(val, head, nullptr);
  head->prev = newHead;
  return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
  if(head->next == nullptr) {
    return insertAtHead(head, val);
  }

  Node* tail = head;
  while(tail->next != nullptr) {
    tail = tail->next;
  }
  Node* back = tail->prev;
  Node* newNode = new Node(val, tail, back);
  back->next = newNode;
  tail->prev = newNode;
  return head;
}

int main() {
  // * test case 1
  // std::vector<int> arr = { 1 };
  // int insert = 0;
  //
  // * test case 2
  std::vector<int> arr = { 1,2,3,5 };
  int insert = 4;

  Node* head = arrayToDLL(arr);

  std::cout<<"------ Before Insertion ------"<<std::endl;
  printDLL(head);

  std::cout<<"------ After Insertion ------"<<std::endl;
  head = insertBeforeTail(head, insert);
  printDLL(head);

}
