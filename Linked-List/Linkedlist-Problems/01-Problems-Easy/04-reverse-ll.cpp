/*
 * Reverse Linked List

 * You are given a Singly Linked List of integers. You need to reverse the Linked List by changing the links between nodes.

 * You are given the 'head' of a singly linked list. Your task is to group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered list’s head.
 * The first node is considered odd, and the second node is even, and so on.

 * Example 1
 * Input  : 1 -> 2 -> 3 -> 4 -> 'NULL'
 * Output : 4 -> 3 -> 2 -> 1 -> 'NULL'
 * 

 * https://www.naukri.com/code360/problems/reverse-linked-list_920513
 * https://leetcode.com/problems/reverse-linked-list/submissions/1234160860/
 * https://www.youtube.com/watch?v=D2vI2DNJGd8&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=10
 
*/

#include<stack>
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

// * ------------------ BRUTE FORCE ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
Node* reverseLLBruteForce(Node* head) {
  if(head == nullptr || head->next == nullptr) 
    return head;

  std::stack<int> st;

  Node* temp = head;
  while(temp) {
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head;

  while(temp) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* reverseLLOptimal(Node* head) {
  if(head == nullptr || head->next == nullptr) 
    return head;

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
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* reverseLLOptimalRecursive(Node* temp, Node* prev) {
  if(temp == nullptr) {
    return prev;
  }

  Node* front = temp->next;
  temp->next = prev;
  prev = temp;
  temp = front;

  return reverseLLOptimalRecursive(temp, prev);
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToLL(arr);
  std::cout << std::endl << " ---------- Linked List Before Reversing -----------  " << std::endl;
  printLL(head);

  std::cout << std::endl << " ---------- Linked List After Reversing -----------  " << std::endl;
  // head = reverseLLBruteForce(head);
  // head = reverseLLOptimal(head);
  head = reverseLLOptimalRecursive(head, nullptr);
  printLL(head);
  
  return 0;
}

// * g++ --std=c++17 04-reverse-ll.cpp -o 04-reverse-ll && ./04-reverse-ll