/*
 * Sort linked list of 0s 1s 2s

 * Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2.
 * You need to sort the linked list in non-decreasing order and the return the head of the sorted list. 
 * 
 * Example 1
 * Input: 1 -> 0 -> 2 -> 1 -> 2. 
 * Output: 0 -> 1 -> 1 -> 2 -> 2.
 *
 * 
 * https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTabValue=PROBLEM 
*/

#include<iostream>

class Node {
  public:
    int data;
    Node* next;

    Node(int d) {
      this->data = d;
    }

    Node(int d, Node* n) {
      this->data = d;
      this->next = n;
    }
};

// * ------------------- Utility Functions ---------------------

Node* arrayToLL(std::vector<int> arr) {
  if(arr.size() == 0) {
    return nullptr;
  }

  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}

void printLL(Node* head) {
  Node* temp = head;
  while(temp) { 
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

// * Sort linked list of 0s 1s 2s

// * ------------------ Brute Force ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
Node* bruteForce(Node* head) {
  Node* temp = head;
  int zeroCount = 0, oneCount = 0, twoCount = 0;
  
  // * Count the 0s, 1s and 2s O(N)
  while(temp) {
    int d = temp->data;
    if(d == 0) zeroCount++;
    else if(d == 1) oneCount++;
    else if(d == 2) twoCount++;
    temp = temp->next;
  }

  temp = head;
  for(int i=0; i<zeroCount; i++) { // * O(zeroCount)
    temp->data = 0;
    temp = temp->next;
  }
  for(int i=0; i<oneCount; i++) { // * O(oneCount)
    temp->data = 1;
    temp = temp->next;
  }
  for(int i=0; i<twoCount; i++) { // * O(twoCount)
    temp->data = 2;
    temp = temp->next;
  }
  return head;
}

// * ------------------ Optimal Solution ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* optimalSolution(Node* head) {

  if(head == NULL || head->next == NULL) return head;

  Node* zeroHead = new Node(-1);
  Node* zero = zeroHead;

  Node* oneHead = new Node(-1);
  Node* one = oneHead;

  Node* twoHead = new Node(-1);
  Node* two = twoHead;

  Node* temp = head;
  while(temp) {
    if(temp->data == 0) {
      zero->next = temp;
      zero = temp;
    }
    else if(temp->data == 1) {
      one->next = temp;
      one = temp;
    }
    else if(temp->data == 2) {
      two->next = temp;
      two = temp;
    }

    temp = temp->next;
  }

  zero->next = oneHead->next ? oneHead->next : twoHead->next;
  one->next = twoHead->next;
  two->next = nullptr;

  return zeroHead->next;
}

int main() {
  // * testcase 1
  std::vector<int> arr = { 1,0,2,2,1,1,0,1,0 };

  // * Create a Linked List
  Node* head = arrayToLL(arr);
  std::cout<<"------------ Before Sorting Linked List ------------"<<std::endl;
  printLL(head);

  std::cout<<"------------ After Sorting Linked List ------------"<<std::endl;
  // head = bruteForce(head);
  head = optimalSolution(head);
  printLL(head);

  return 0;
}

// * g++ -std=c++17 03-sort-0s-1s-2s.cpp -o 03-sort-0s-1s-2s