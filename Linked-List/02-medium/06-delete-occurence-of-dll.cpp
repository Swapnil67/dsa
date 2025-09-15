/**
 * * Delete all occurrences of a given key in a doubly linked list
 * * A DLL is a data structure that consists of sequentially linked nodes, and the nodes have reference to both
 * * the previous and the next nodes in the sequence of nodes.
 *
 * * Example 1
 * * Input  : 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 -> NULL, k = 10
 * * Output : 4 <-> 3 <-> 5 <-> 20 -> NULL
 
 *
 * * Example 2
 * * Input  : 10 <-> 10 -> NULL, k = 10
 * * Output : NULL
 
 * * https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461
*/

#include <vector>
#include <iostream>

class DLListNode {
  public: 
    int data;
    DLListNode* next;
    DLListNode* prev;

    DLListNode() {
      this->data = 0;
      this->next = NULL;
      this->prev = NULL;
    }
    DLListNode(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    DLListNode (int data, DLListNode *next, DLListNode *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// * ------------------- Utility Functions ---------------------

DLListNode* arrayToDLL(std::vector<int> arr) {
  if(!arr.size()) return nullptr;
  DLListNode* head = new DLListNode(arr[0]);
  DLListNode* back = head;

  for(int i=1; i<arr.size(); i++) {
    DLListNode* newNode = new DLListNode(arr[i], nullptr, back);
    back->next = newNode;
    back = newNode;
  }
  return head;
}

void printDLL(DLListNode* head) {
  DLListNode* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(1)
DLListNode* deleteOccurences(DLListNode* head, int k) {
  if (!head)
    return nullptr;

  // * only one node
  if (!head->next && head->data == k)
    return nullptr;

  // * If head node is 'k' then pre-remove it
  while (head && head->data == k) {
    head = head->next;
  }

  DLListNode* temp = head;
  while (temp) {
    if (temp->data == k) {
      // * Delete the node

      DLListNode* delNode = temp;
      if (temp == head) {
        // * Check if head
        head = head->next;
      }
      DLListNode* front = temp->next;
      DLListNode* back = temp->prev;

      if (front)
        front->prev = back;
      if (back)
        back->next = front;

      std::free(delNode);
      temp = front;
    }
    else
    {
      temp = temp->next;
    }
  }
  return head;
}

int main() {
  // std::vector<int> arr = {2, 1, 2, 3, 2, 4, 5, 2};
  std::vector<int> arr = {2, 2, 2, 2};
  // std::vector<int> arr = { 2 };
  DLListNode* head = arrayToDLL(arr);
  std::cout << "Before Deleting" << std::endl;
  printDLL(head);

  std::cout << "After Deleting" << std::endl;
  head = deleteOccurences(head, 2);
  printDLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++17 06-delete-occurence-of-dll.cpp -o output && ./output