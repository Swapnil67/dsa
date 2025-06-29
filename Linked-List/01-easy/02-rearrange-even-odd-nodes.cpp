/*
 * Segregate Even And Odd Nodes In a Linked List

 * You are given the head node of a singly linked list 'head'. Your task is to modify the linked list 
 * in such a way that all the even valued nodes appear before the all odd valued node and order of nodes
 * remain the same.
 
 * * Example 1
 * * head :  6 -> 5 -> 3 -> 4 -> 7 -> 1 -> 2 
 * * Output:  6 -> 4 -> 2 -> 5 -> 3 -> 7 -> 1 
 * 
 
 * * Example 1
 * * head : 2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7
 * * Output: 2 -> 6 -> 4 -> 1 -> 3 -> 5 -> 7
 * 
*/

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

// * Re Arrange Even and Odd Nodes
Node* reArrangeEvenOddNodes(Node* head) {
  std::vector<int> arr;
  Node* temp = head;

  // * Insert Even Nodes in arr
  while (temp) {
    if (temp->data % 2 == 0 && temp->data >= 0) {
      arr.push_back(temp->data);
    }
    temp = temp->next;
  }


  // * Insert Odd Nodes in arr
  temp = head;
  while (temp) {
    if (temp->data % 2 != 0 && temp->data >= 0) {
      arr.push_back(temp->data);
    }
    temp = temp->next;
  }

  // * Traverse the LL and replace the data values with array data values
  int j = 0; temp = head;
  while (temp) {
    if (arr[j] >= 0) {
      temp->data = arr[j];
    }
    j++;
    temp = temp->next;
  }

  // * For debugging
  // for (int i = 0; i < arr.size(); i++) {
  //   std::cout << arr[i] << " ";
  // }
  // std::cout << std::endl;

  return head;
} 

int main() {
  // * testcase 1
  // std::vector<int> arr = {6, 5, 3, 4, 7, 1, 2};

  // * testcase 2
  // std::vector<int> arr = {1, 2, 3, 4, 5, -1};

  // * testcase 3
  std::vector<int> arr = {4, 11, 5, 11, 0, 6, 1, 6, 6, 5, 17, 14, 19, 19, 12, 9, 9, -1};

  // * Create a Linked List
  Node* head = arrayToLL(arr);
  std::cout << "------------ Before Rearranging Linked List ------------" << std::endl;
  printLL(head);

  // * Rearrange even and odd numbers
  std::cout << "------------ After Rearranging Linked List ------------" << std::endl;
  head = reArrangeEvenOddNodes(head);
  // printLL(head);

  return 0;
}

// * g++ -std=c++17 02-rearrange-even-odd-nodes.cpp -o 02-rearrange-even-odd-nodes