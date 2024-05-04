/**
 * * Reverse Doubly Linked List
 * * https://takeuforward.org/data-structure/reverse-a-doubly-linked-list/
*/

#include<stack>
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
  if(arr.size() == 0) return nullptr;
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

// * ------------------ BRUTE FORCE ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
Node* reverseDLLBruteForce(Node* head) {
  // * if head is empty or there is only one element
  // * we can directly just return the head
  if(head==NULL || head->next == NULL){
      return head;
  }
    
  std::stack<int> st;
  Node* temp = head;
  while(temp != nullptr) {
    st.push(temp->data);
    temp = temp->next;
  }

  // * Reinitialise temp to head
  temp = head;
  while(temp != nullptr) {
    // * Replace the value pointed via temp with
    // * the value from the top of the stack
    temp->data = st.top();
    // * Pop the value from the stack
    st.pop();
    // * Traverse further
    temp = temp->next;
  }

  return head;

}


// * ------------------ Optimal FORCE ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* reverseDLLOptimal(Node* head) {
  // * if head is empty or there is only one element
  // * we can directly just return the head
  if(head==NULL || head->next == NULL){
      return head;
  }

  Node* current = head;
  Node* last = NULL;

  while(current != NULL) {
    last = current->prev;
    current->prev = current->next;
    current->next = last;
    current = current->prev;
  }

  return last->prev;
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToDLL(arr);
  std::cout << std::endl << "Doubly Linked List Initially:  " << std::endl;
  printDLL(head);

  std::cout << std::endl << "Doubly Linked List After Reversing " << std::endl;
  // head = reverseDLLBruteForce(head);
  head = reverseDLLOptimal(head);
  printDLL(head);
}

// * g++ --std=c++17 01-reverse-dll.cpp -o 01-reverse-dll && ./01-reverse-dll