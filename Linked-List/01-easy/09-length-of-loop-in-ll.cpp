/**
 * * Find length of Loop
 * * You’re given a linked list. The last node might point to null, or it might point to a node in the list, thus forming a cycle.
 * 
 * * Example 1
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 1
 * * Output : 5

 * * Example 2
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
 * * Output : 4

 * * https://www.naukri.com/code360/problems/find-length-of-loop_8160455
 * * https://www.youtube.com/watch?v=I4g1qbkTPus&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=16
*/

#include <vector>
#include <iostream>
#include <unordered_map>

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

// * Traverse LL
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
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = head->next;
  return head;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY O(N) + 2*O(logN)
// * SPACE COMPLEXITY O(N)
int bruteForce(Node* head) {
  if (head == nullptr || head->next == nullptr)
    return 0;

  Node* temp = head;
  int timer = 0;
  std::unordered_map<Node *, int> nodeMap;
  Node* loopStart = nullptr;
  // * O(N)
  while (temp) {
    // * O(LogN)
    if (nodeMap.count(temp)) {
      loopStart = temp;
      return timer - nodeMap[temp];
    }
    // * O(LogN)
    nodeMap[temp] = timer++;
    temp = temp->next;
  }
  return timer;
}


// * ------------------ Optimal Approach ---------------------
// * Tortise & Hare algorithrm
// * TIME COMPLEXITY O(N/2) + O(N)
// * SPACE COMPLEXITY O(1)
int lengthOfCycle(Node* head) {
  if (head == nullptr || head->next == nullptr)
    return 0;

  Node* slow = head;
  Node* fast = head;

  // * O(N/2)
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    if (fast)
      fast = fast->next;
    
    if (slow == fast)
      break;
  }

  if (slow != fast)
    return 0;

  int c = 0;
  // * O(N)
  while (slow) {
    c++;
    slow = slow->next;
    if (slow == fast)
      return c;
    
  }

  return c;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  Node* head = arrayToLL(arr);

  // * Comment this for normal LL (Linear LL)
  head = makeLoop(head);

  // int loopCount = bruteForce(head);
  int loopCount = lengthOfCycle(head);
  std::cout<<"Length of loop "<<loopCount<<std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++17 09-length-of-loop-in-ll.cpp -o 09-length-of-loop-in-ll && ./09-length-of-loop-in-ll