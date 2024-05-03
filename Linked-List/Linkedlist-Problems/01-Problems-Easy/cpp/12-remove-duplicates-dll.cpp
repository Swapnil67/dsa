/**
 * * Remove duplicates from a sorted Doubly Linked List
 * * A doubly-linked list is a data structure that consists of sequentially linked nodes,
 * * and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
 * 
 * * Example 1
 * * Input  : 1 <-> 2 <-> 2 <-> 2 <-> 3
 * * Output : 1 <-> 2 <-> 3

 * * https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283
 * * https://youtu.be/YJKVTnOJXSY?si=AsZoNUoewetsBjr0
*/

#include<map>
#include<iostream>

class Node {
  public: 
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
      this->data = val;
      this->next = NULL;
      this->prev = NULL;
    }

    Node(int val, Node* n, Node* p) {
      this->data = val;
      this->next = n;
      this->prev = p;
    }
};


Node* arrayToDLL(std::vector<int> arr) {
  if(!arr.size()) return NULL;

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

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY  O(N) + 2*O(logN)
// * SPACE COMPLEXITY O(N)
Node* bruteForce(Node* head) {
  if(head == nullptr) return nullptr;
  if(head->next == nullptr) return head;

  Node* temp = head;
  std::map<int, int> nodeMap;

  // * O(N)
  while(temp) {
    // * O(logN)
    if(nodeMap.find(temp->data) != nodeMap.end()) {
      // * Found duplicate
      Node* delNode = temp;
      temp->prev->next = temp->next;
      if(temp->next) {
        temp->next->prev = temp->prev;
      }
      // delete delNode;
    }
    else {
      // * O(logN)
      nodeMap[temp->data] = 1;
    }
    temp = temp->next;
  }

  return head;
}


// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(1)
Node* optimal(Node* head) {
  if(head == nullptr) return nullptr;
  if(head->next == nullptr) return head;

  Node* temp = head;
  while(temp) {
    // * Since DLL is sorted duplicates will only present in next node
    Node* nextNode = temp->next;
    if(nextNode) {
      while(nextNode != NULL && temp->data == nextNode->data) {
        Node* duplicate = nextNode;
        nextNode = nextNode->next;
        std::free(duplicate);
      }
      temp->next = nextNode;
      if(nextNode) {
        nextNode->prev = temp;
      }
    }
    temp = temp->next;
  }

  return head;
}

int main() {
  // std::vector<int> arr = { 1,2,2,2,3 };
  std::vector<int> arr = { 1,2,2,2,3,3 };
  Node* head = arrayToDLL(arr);
  printDLL(head);

  head = removeDuplicated(head);
  printDLL(head);
}

// * Run the code
// * g++ --std=c++17 12-remove-duplicates-dll.cpp -o 12-remove-duplicates-dll && ./12-remove-duplicates-dll