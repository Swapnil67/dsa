/**
 * *  Delete all occurrences of a given key in a doubly linked list
 * * A DLL is a data structure that consists of sequentially linked nodes, and the nodes have reference to both
 * * the previous and the next nodes in the sequence of nodes.
 *
 * * Example 1
 * * Input  : 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 -> NULL, k = 10
 * * Output : 4 <-> 3 <-> 5 <-> 20 -> NULL
 
 *
 * * Example 2
 * * Input  : 10 <-> 10 -> NULL, k = 10
 * * Output : NULL
 
 * * https://www.youtube.com/watch?v=Mh0NH_SD92k&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=20
 * * https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461
*/

#include<iostream>

class Node {
  public: 
    int data;
    Node* next;
    Node* prev;

    Node() {
      this->data = 0;
      this->next = NULL;
      this->prev = NULL;
    }
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node (int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// * ------------------- Utility Functions ---------------------

Node* arrayToDLL(std::vector<int> arr) {
  if(!arr.size()) return nullptr;
  Node* head = new Node(arr[0]);
  Node* back = head;

  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i], nullptr, back);
    back->next = newNode;
    back = newNode;
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

// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(1)
Node* deleteOccurences(Node* head, int k) {

  if(head == nullptr) return nullptr;
  if(head->next == nullptr && head->data == k) return nullptr;

  Node* temp = head;
  while(temp) {
    if(temp->data == k) {
      // * Delete the node

      Node* delNode = temp;
      if(temp == head) {
        // * Check if head
        head = head->next;
      }
      Node* frontNode = temp->next;
      Node* backNode = temp->prev;

      if(frontNode) frontNode->prev = backNode;
      if(backNode) backNode->next = frontNode;

      std::free(delNode);
      temp = frontNode;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

int main() {  
  std::vector<int> arr = { 2, 1, 2, 3, 2, 4, 5, 2 };
  // std::vector<int> arr = { 2, 2, 2, 2 };
  // std::vector<int> arr = { 2 };
  Node* head = arrayToDLL(arr);
  std::cout<<"Before Deleting"<<std::endl;
  printDLL(head);

  std::cout<<"After Deleting"<<std::endl;
  head = deleteOccurences(head, 2);
  printDLL(head);
}


// * Run the code
// * g++ --std=c++17 06-delete-occurence-of-dll.cpp -o 06-delete-occurence-of-dll && ./06-delete-occurence-of-dll