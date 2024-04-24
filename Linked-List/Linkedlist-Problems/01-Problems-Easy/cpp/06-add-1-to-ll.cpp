/*
 * Add 1 to LL

 * You are given a Singly Linked List of integers. You have to return true if the linked list is palindrome, else return false.

 * A Linked List is a palindrome if it reads the same from left to right and from right to left.
 * together followed by the nodes with even indices, and return the reordered list’s head.
 * The first node is considered odd, and the second node is even, and so on.

 * Example 1
 * Input  : 1 -> 2 -> 1 -> 'NULL'
 * Output : true

 * Example 2
 * Input  : 1 -> 2 -> 3 -> 'NULL'
 * Output : false
 * 

 * https://leetcode.com/problems/palindrome-linked-list/
 * https://www.naukri.com/code360/problems/check-if-linked-list-is-palindrome_985248
 * https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
 * https://www.youtube.com/watch?v=lRY_G-u_8jk&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=11
 
*/

#include<iostream>

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

// * Convert array to LL
Node* arrayToLL(std::vector<int> arr) {
  if(arr.size() == 0) return nullptr;
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
    temp = temp -> next;
  }
  std::cout<<std::endl;
}

Node* reverseLL(Node* head) {
  Node* temp = head;
  Node* prev = nullptr;

  while(temp) {
    Node* front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }

  return prev;
}

// * ------------------ Recursive Approach ---------------------
// * TIME COMPLEXITY O(3N)
// * SPACE COMPLEXITY O(1)
Node* bruteForce(Node* head) {
  Node* temp = head;

  // * Reverse LL
  Node* prevHead = reverseLL(head);
  temp = prevHead;

  // * Do Addition
  int carry = 1;
  while(temp) {
    temp->data = carry + temp->data;
    if(temp->data < 10) {
      carry = 0;
      break;
    }
    else {
      temp->data = 0;
      carry = 1;
    }
    temp = temp->next;
  }

  // * Reverse LL
  if(carry == 1) {
    Node* newNode = new Node(1);
    temp = reverseLL(prevHead);
    newNode->next = temp;
    return newNode;
  }

  temp = reverseLL(temp);
  return temp;
}


// * ------------------ Optimal (Recursive) Approach ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int helper(Node* head) {
  Node* temp = head;
  if(temp == nullptr) {
    return 1;
  }

  int carry = helper(temp->next);

  // * Backtracking Logic
  temp->data = carry + temp->data;
  if(temp->data < 10) {
    return 0;
  }
  temp->data = 0;
  return 1;
}

Node* optimal(Node* head) {
  int carry = helper(head);
  if(carry == 1) {
    Node* newNode = new Node(1);
    newNode->next = head;
    return newNode;
  }
  return head;
}

int main() {
  // * testcase 1
  std::vector<int> arr = { 9,9,9 };
  // * testcase 2
  // std::vector<int> arr = { 1,5,3,4 };
  Node* head = arrayToLL(arr);
  printLL(head);

  // head = bruteForce(head);
  head = optimal(head);
  printLL(head);
  return 0;
}

// * Run the code
// * g++ --std=c++17 06-add-1-to-ll.cpp -o 06-add-1-to-ll && ./06-add-1-to-ll