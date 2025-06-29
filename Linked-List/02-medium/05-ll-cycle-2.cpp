/**
 * * Cycle Detection in a Singly Linked List
 * * You are given a singly linked list that may or may not contain a cycle. 
 * * You are supposed to return the node where the cycle begins, if a cycle exists, else return 'NULL'.
 * 
 * * Example 1
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 1
 * * Output : 1

 * * Example 2
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
 * * Output : 3
 * 
 * * Example 3
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 * * Output : NULL

 * * https://leetcode.com/problems/linked-list-cycle-ii/description/
 * * https://www.naukri.com/code360/problems/linked-list-cycle-ii_1112628
 * * https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
 * * https://www.youtube.com/watch?v=2Kd0KKmmHFc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=18
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
Node* arrayToLL(std::vector<int>arr) {
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

// * Make Loop in LL
Node* makeLoop(Node* head) {
  Node* temp = head;
  // * Go till temp's tail
  while(temp->next) {
    temp = temp->next;
  }
  temp->next = head->next; // * OR
  // temp->next = head;
  return head;
}
 
// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY O(N) + 2*O(logN)
// * SPACE COMPLEXITY O(N)
Node* bruteForce(Node* head) {
  if(head == nullptr || head->next == nullptr) return nullptr;

  Node* temp = head;
  std::map<Node*, int> nodeMap;
  // * O(N)
  while(temp) {
    // * O(logN)
    if(nodeMap.find(temp) != nodeMap.end()) return temp;
    // * O(logN)
    nodeMap[temp] = 1;
    temp = temp->next;
  }
  return nullptr;
}


// * ------------------ Optimal Approach ---------------------
// * Tortise & Hare algorithrm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* findStartOfLoop(Node* head, Node* collisionNode){
  Node* temp = head;
  while(temp != collisionNode) {
    temp = temp->next;
    collisionNode = collisionNode->next;
  }
  return temp;
}

Node* optimal(Node* head) {
  if(head == nullptr || head->next == nullptr) return nullptr;
  Node* slow = head;
  Node* fast = head;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    if(fast) {
      fast = fast->next;
    }
    if(slow == fast) {
      break;
    };
  }

  // * If Loop
  if(slow == fast) {
    return findStartOfLoop(head, fast);
  }

  return nullptr;
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToLL(arr);
  // printLL(head);

  // * Comment this for normal LL (Linear LL)
  head = makeLoop(head);

  // Node *loopStart = bruteForce(head);
  Node *loopStart = optimal(head);
  if (loopStart == nullptr) {
    std::cout << "Linear Linked List" << std::endl;
  }
  else {
    std::cout << "Start of Loop " << loopStart->data<<std::endl;
  }
  return 0;
}


// * Run the code
// * g++ --std=c++17 05-ll-cycle-2.cpp -o 05-ll-cycle-2 && ./05-ll-cycle-2