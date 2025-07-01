/**
 * * Leetcode - 876
 * * Middle Of Linked List
 * * Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list.
 * * However, if the list has an even number of nodes, we return the second middle node.
 * 
 * * Example 1
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 'NULL'
 * * Output : 3

 * * Example 2
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 'NULL'
 * * Output : 4

 * * https://leetcode.com/problems/middle-of-the-linked-list/
 * * https://www.naukri.com/code360/problems/middle-of-linked-list_973250
*/

#include <vector>
#include <iostream>

class Node {
  public: 
    int data;
    Node* next;

    Node(int d) {
      this->data = d;
      this->next = nullptr;
    }

    Node(int d, Node* n) {
      this->data = d;
      this->next = n;
    }
};

// * ------------------- Utility Functions ---------------------

// * Convert array to ll
Node* arrayToLL(std::vector<int> arr) {
  if(!arr.size()) return nullptr;

  Node* head = new Node(arr[0]);
  Node* temp = head;

  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}

// * Traverse the LL
void printLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

// * Count the LL
int countLL(Node* head) {
  Node* temp = head;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  } 
  return c;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY O(N + O(N/2))
// * SPACE COMPLEXITY O(1)
Node* bruteForce(Node* head) {
  if(!head) return nullptr;
  if(head && head->next == nullptr) return head;

  // * Count the nodes in ll
  int ll_count = countLL(head);

  // * Middle node index of ll
  int midIdx = (ll_count / 2) + 1;
  Node* temp = head;

  while(temp && midIdx > 0) {
    midIdx--;
    temp = temp->next;
  }
  return temp;
}

// * ------------------ Optimal Approach ---------------------
// * Tortoise & Hare Algorithm
// * TIME COMPLEXITY O(N/2)
// * SPACE COMPLEXITY O(1)
Node* middleNode(Node* head) {
  if(!head) return nullptr;
  if(head && head->next == nullptr) return head;

  Node* slow = head;
  Node* fast = head;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    if(fast == nullptr) return slow;
    fast = fast->next;
  }

  return slow;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {1, 2};
  // * testcase 2
  // std::vector<int> arr = { 1,2,3,4,5 };
  // * testcase 3
  // std::vector<int> arr = { 1,2,3,4,5,6 };
  Node* head = arrayToLL(arr);
  printLL(head);

  // Node* middleNode = bruteForce(head);
  Node* midNode = middleNode(head);
  std::cout << "Middle Node: " << midNode->data << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-middle-of-ll.cpp -o 08-middle-of-ll && ./08-middle-of-ll