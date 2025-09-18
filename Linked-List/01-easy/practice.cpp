#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>

typedef struct Node Node;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
      data = val;
      next = nullptr;
    }

    Node(int val, Node *node) {
      data = val;
      next = node;
    }

    Node(int val, Node *nextNode, Node* prevNode) {
      data = val;
      next = nextNode;
      prev = prevNode;
    }
};

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printLL(Node *ll) {
  Node *temp = ll;
  while (temp) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

Node *arrayToLL(std::vector<int> &arr) {
  if (!arr.size())
    return nullptr;

  // * create the head node
  Node *head = new Node(arr[0]);
  
  // * create the tail node
  Node *tail = head;
  
  int n = arr.size();
  for(int i = 1; i < n; ++i) {
    Node *node = new Node(arr[i]);
    tail->next = node;
    
    tail = node;
  }

  return head;
}

Node *arrayToDLL(std::vector<int> &arr) {
  // * create the head node
  Node *head = new Node(arr[0]);
  
  // * create the tail node
  Node *tail = head;
  
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    Node *node = new Node(arr[i], nullptr, tail);
    tail->next = node;
    tail = node;
  }

  return head;
}

int getLLSize(Node* head) {
  int cnt = 0;
  while (head) {
    cnt++;
    head = head->next;
  }
  return cnt;
}

// * 01 - Reverse Doubly Linked List
// Node *reverseDLL(Node *head) {
// TODO
// }

// * 02 - Segregate Even And Odd Nodes In a Linked List
// Node *reArrangeEvenOddNodes(Node *head) {
// TODO
// }

// * 03 - Sort linked list of 0s 1s 2s
// Node *optimalSolution(Node *head) {
// TODO
// }

// * 04 - Reverse Linked List
// Node *reverseLLOptimal(Node *head) {
// TODO
// }

// * 05 - Check If Linked List Is Palindrome
// bool isPalindrome(Node *head) {
// TODO
// }
  
// * 06 - Add 1 to LL
// Node *addOne(Node *head) {
// TODO
// }

// * 07 - Intersection of Two Linked Lists
// Node *getIntersectionNode(Node *head1, Node *head2) {
// TODO
// }

// * 08 - Middle Of Linked List
// Node *middleNode(Node *head) {
// TODO
// }

// * 09A - Linked List Cycle
// bool hasCycle(Node *head) {
// TODO
// }

// * 09B - Find length of Loop
// Node *lengthOfCycle(Node *head) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

