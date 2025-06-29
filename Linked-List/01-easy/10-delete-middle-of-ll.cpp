/**
 * *  Delete Middle Node
 * * Given a singly linked list of 'N' nodes. Your task is to delete the middle node of this list and return the head of the modified list.

 * * Example 1
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * * Output : 1 -> 2 -> 4 -> 5 -> NULL

 * * Example 2
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 * * Output : 1 -> 2 -> 3 -> 5 -> 6 -> NULL 

 * * Example 2
 * * Input  : 1 -> NULL
 * * Output : -1

 * * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1242699086/
 * * https://www.naukri.com/code360/problems/delete-middle-node_763267?leftPanelTabValue=PROBLEM
 * * https://www.youtube.com/watch?v=ePpV-_pfOeI&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=17
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

void printLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

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
// * TIME COMPLEXITY  O(N) + O(N/2)
// * SPACE COMPLEXITY O(1)
Node* bruteForce(Node* head) {
  if(head == nullptr) return nullptr;
  if(head->next == nullptr) return head;

  Node* temp = head;
  // * O(N)
  int ll_count = countLL(head);
  int midIdx = (ll_count/2)+1;
  int c = 1;
  // * O(N/2)
  while(temp) {
    if(c == midIdx-1) {
      Node* delNode = temp->next;
      temp->next = temp->next->next;
      std::free(delNode);
      return head;
    }
    c++;
    temp = temp->next;
  }
}

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY  O(N/2)
// * SPACE COMPLEXITY O(1)
Node* optimal(Node* head) {
  if(head == nullptr) return nullptr;
  if(head->next == nullptr) return head;

  Node* slow = head;
  Node* fast = head;
  
  // * Move the fast pointer once
  fast = fast->next;
  if(fast) {
    fast = fast->next;
  }

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    if(fast) {
      fast = fast->next;
    }
  }

  // * Here slow is at mid-1 index in ll
  Node* freeNode = slow->next;
  slow->next = slow->next->next;
  std::free(freeNode);
  return head;
} 

int main() {
  // * testcase 1
  std::vector<int> arr = { 1,2,3,4,5 };
  // * testcase 2
  // std::vector<int> arr = { 1,2,3,4,5,6 };
  // * testcase 3
  // std::vector<int> arr = { 1,2 };
  
  Node* head = arrayToLL(arr);
  std::cout<<"Before Deleting Middle Node"<<std::endl;
  printLL(head);

  std::cout<<"After Deleting Middle Node"<<std::endl;
  // head = bruteForce(head);
  head = optimal(head);
  printLL(head);
  return 0;
}


// * Run the code
// * g++ --std=c++17 10-delete-middle-of-ll.cpp -o 10-delete-middle-of-ll && ./10-delete-middle-of-ll