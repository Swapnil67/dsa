#include <vector>
#include <stack>
#include <stdlib.h>
#include <iostream>

typedef struct Node Node;

class Node {
  public:
    int data;
    Node *next;

    Node(int val) {
      data = val;
      next = nullptr;
    }

    Node(int val, Node *node) {
      data = val;
      next = node;
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

// Node *reverseLL(Node *temp, Node *prev) {
// TODO
// }

int main() {
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o practice && ./practice

