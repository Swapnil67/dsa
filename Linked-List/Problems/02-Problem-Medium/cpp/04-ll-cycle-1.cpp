/**
 * * Cycle Detection in a Singly Linked List
 * * You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.
 * 
 * * Example 1
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 1
 * * Output : true

 * * Example 2
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 'NULL'
 * * Output : false

 * * https://leetcode.com/problems/linked-list-cycle/
 * * https://www.naukri.com/code360/problems/cycle-detection-in-a-singly-linked-list_628974
 * * https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
 * * https://www.youtube.com/watch?v=wiOo4DC5GGA&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=15
*/

#include<map>
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
// * Array to LL
Node* arrayToLL(std::vector<int> arr) {
  if(!arr.size()) return NULL;

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

// * Make Loop in LL
Node* makeLoop(Node* head) {
  Node* temp = head;
  // * Go till temp's tail
  while(temp->next) {
    temp = temp->next;
  }
  temp->next = head;
  return head;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY O(N) + 2*O(logN)
// * SPACE COMPLEXITY O(N)
bool bruteForce(Node* head) {
  if(head == nullptr || head->next == nullptr) return false;
  Node* temp = head;
  std::map<Node*, int> nodeMap;
  // * O(N)
  while(temp) {
    // * O(logN)
    if(nodeMap.find(temp) != nodeMap.end()) return true;
    // * O(logN)
    nodeMap[temp] = 1;
    temp = temp->next;
  }
  return false;
}

// * ------------------ Optimal Approach ---------------------
// * Tortise & Hare algorithrm
// * TIME COMPLEXITY O(N/2)
// * SPACE COMPLEXITY O(1)
bool optimal(Node* head) {
  Node* slow = head;
  Node* fast = head;
  if(head == nullptr || head->next == nullptr) return false;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    if(fast) {
      fast = fast->next;
    }
    if(slow == fast) return true;
  }
  return false;  
}


int main() {
  // * testcase
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToLL(arr);

  // * Comment this for normal LL (Linear LL)
  // head = makeLoop(head);

  // bool isLoop = bruteForce(head);
  bool isLoop = optimal(head);
  std::cout<<"Loop In LL: "<<isLoop<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-ll-cycle-1.cpp -o 04-ll-cycle-1 && ./04-ll-cycle-1