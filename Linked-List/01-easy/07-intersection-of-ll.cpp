/**
 * * Leetcode - 160
 * * Intersection of Two Linked Lists
 * * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
 * * If the two linked lists have no intersection at all, return null.
 * 
 * * Example 1
 * * Input  : head1 = 4 -> 1 -> 8 -> 4 -> 5 -> 'NULL', head2 = 5 -> 6 -> 1 -> 8 -> 4 -> 5
 * * Output : Intersected at 8
 * 
 * * Example 1
 * * Input  : head1 = 1 -> 2 -> 3 -> 4 -> 'NULL', head2 = 5 -> 6 -> 7 -> 8
 * * Output : NULL

 * * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * * https://www.naukri.com/code360/problems/-intersection-of-two-linked-lists_63045
*/

#include <map>
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
    temp = temp->next;
  }
  std::cout<<std::endl;
}

// * Count LL
int countLL(Node* head) {
  Node* temp = head;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  }
  return c;
}

Node* appendLLToTail(Node* head1, Node* head2) {
  Node* temp = head1;
  while(temp->next) {
    temp = temp->next;
  }

  temp->next = head2;
  return head1;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY O(N x Ologn)
// * SPACE COMPLEXITY O(N)
Node* bruteForce(Node* head1, Node* head2) {
  std::map<Node*, int> nodeMap;
  Node* temp = head1;
  // * O(N)
  while(temp) {
    nodeMap[temp] = 1;
    temp = temp->next;
  }

  temp = head2;
  while(temp) {
    // * O(Nlogn)
    if(nodeMap.find(temp) != nodeMap.end()) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}

// * ------------------ Optimal Approach ---------------------

Node* forwardHead(Node* head, int a, int b) {
  Node* temp = head;
  for(int i=0; i<a-b; i++) {
    if(temp) {
      temp = temp->next;
    }
  }
  return temp;
}

Node* optimal(Node* head1, Node* head2) {
  int c1 = countLL(head1);
  int c2 = countLL(head2);

  if(c1 > c2) {
    head1 = forwardHead(head1, c1, c2);
  } else if(c2 > c1) {
    head2 = forwardHead(head2, c2, c1);
  }

  Node* temp1 = head1;
  Node* temp2 = head2;
  while(temp1 && temp2) {
    if (temp1 == temp2) {
      return temp1;
    }
    if (temp1)
      temp1 = temp1->next;
    if (temp2)
      temp2 = temp2->next;
  }

  return NULL;
}

int main() {
  std::vector<int> arr1 = {4, 1};
  std::vector<int> arr2 = {5, 6, 1};

  // * testcase 1
  std::vector<int> intersectArr = {8, 4, 5};

  // * testcase 2
  // std::vector<int> intersectArr = {};

  Node* head1 = arrayToLL(arr1);
  Node* head2 = arrayToLL(arr2);
  Node* intersectHead = arrayToLL(intersectArr);

  head1 = appendLLToTail(head1, intersectHead);
  head2 = appendLLToTail(head2, intersectHead);
  std::cout<<"Linked List One"<<std::endl;
  printLL(head1);
  std::cout<<"Linked List Two"<<std::endl;
  printLL(head2);

  // Node* intersectNode = bruteForce(head1, head2);
  Node* intersectNode = optimal(head1, head2);
  if(intersectNode) {
    std::cout << "Intersected at '" << intersectNode->data << "'" << std::endl;
  } else {
    std::cout << "Not Intersecting" << std::endl;
  }

}

// * g++ --std=c++17 07-intersection-of-ll.cpp -o output && ./output