/*
 * Rearrange Odd and Even Places

 * You are given the 'head' of a singly linked list. Your task is to group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered list’s head.
 * The first node is considered odd, and the second node is even, and so on.

 * * Example 1
 * * head :  1 -> 3 -> 5 -> 7
 * * Output: 1 -> 5 -> 3 -> 7
 * 
 
 * * Example 1
 * * head : 2 -> 4 -> 6 -> 8 -> 10
 * * Output: 2 -> 6 -> 10 -> 4 -> 8
 * 
 
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

// * Re Arrange Even and Odd Indices
Node* reArrangeEvenOdd(Node* head) {
  std::vector<int> arr;
  Node* temp = head;

  // * Insert Odd index in arr
  while(temp) {
    arr.push_back(temp->data);
    if(temp->next == nullptr) {
      break;
    }
    temp = temp->next->next;
  }

  // * Insert Even index in arr
  temp = head->next;
  while(temp) {
    arr.push_back(temp->data);
    if(temp->next == nullptr) {
      break;
    }
    temp = temp->next->next;
  }

  // * Traverse the LL and replace the data values with array data values
  int j = 0; temp = head;
  while(temp) {
    temp->data = arr[j++];
    temp = temp->next;
  }

  // * For debugging
  // for(int i=0; i<arr.size(); i++) {
  //   std::cout<<arr[i]<<" ";
  // }
  // std::cout<<std::endl;

  return head;
} 

int main() {
  // * testcase 1
  // std::vector<int> arr = { 1,2,3,4,5,6 };
  // * testcase 2
  std::vector<int> arr = { 2,4,6,8,10 };

  // * Create a Linked List
  Node* head = arrayToLL(arr);
  std::cout<<"------------ Before Rearranging Linked List ------------"<<std::endl;
  printLL(head);

  // * Rearrange even and odd numbers
  std::cout<<"------------ After Rearranging Linked List ------------"<<std::endl;
  head = reArrangeEvenOdd(head);
  printLL(head);
  return 0;
}

// * g++ -std=c++17 02-rearrange-even-odd-index.cpp -o 02-rearrange-even-index-odd