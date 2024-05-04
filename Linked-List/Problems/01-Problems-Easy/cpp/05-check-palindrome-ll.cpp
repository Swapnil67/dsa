/*
 * Check If Linked List Is Palindrome

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
#include<stack>

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

// * Reverse the LL
Node* reverse(Node* head) {
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

// * ------------------ BRUTE FORCE ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
bool bruteForce(Node* head) {
  if(head == nullptr || head->next == nullptr) 
    return true;

  std::stack<int> st;

  // * Fill the stack with LL data [O(N)]
  Node* temp = head;
  while(temp) {
    st.push(temp->data);
    temp = temp->next;
  }

  // * Compare the stack with original LL [O(N)]
  temp = head;
  while(temp) {  
    if(st.top() != temp->data) {
      return false;
    }
    st.pop();
    temp = temp->next;
  }

  return true;
}


// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
bool optimalApproach (Node* head) {
  if(head == nullptr || head->next == nullptr) 
    return true;

  // * Find the middle of LL
  Node* slow = head; 
  Node* fast = head;

  // * Tortoise & Hare Algo [O(N/2)]
  while(fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;  // * Moves by 1 steps
    fast = fast->next->next; // * Moves by 2 steps
  }

  Node* firstHead = head;
  // * Reverse the 2nd half of LL [O(N/2)]
  Node* secondHead = reverse(slow->next);


  // * Start comparing the two ll [O(N/2)]
  while(secondHead != nullptr) {
    std::cout<<firstHead->data<<" "<<secondHead->data<<std::endl;
    if(firstHead->data != secondHead->data) {

      // * Get LL back to original state [O(N/2)]
      reverse(secondHead); 
      return false;
    }

    firstHead = firstHead->next;
    secondHead = secondHead->next;
  }

  // * Get LL back to original state [O(N/2)]
  reverse(secondHead);
  return true;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = { 1,2,3,4 };
  // * testcase 2
  // std::vector<int> arr = { 1,2,1 };
  // * testcase 3
  // std::vector<int> arr = { 1,2,2,1 };
  Node* head = arrayToLL(arr);
  std::cout << " ---------- Linked List -----------  " << std::endl;
  printLL(head);

  // bool isPalindrome = bruteForce(head);
  bool isPalindrome = optimalApproach(head);
  std::cout<<"Is Palindrome: "<<isPalindrome<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 05-check-palindrome-ll.cpp -o 05-check-palindrome-ll && ./05-check-palindrome-ll