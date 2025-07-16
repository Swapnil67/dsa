/**
 * * Leetcode - 203
 * * Remove Linked List Elements
 * * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, 
 * * and return the new head.

 * * Example 1
 * * Input  : head = [1,2,6,3,4,5,6], val = 6
 * * Output : [1,2,3,4,5]

 * * Example 2
 * * Input  : head = [7,7,7,7], val = 7
 * * Output : []

 * * https://leetcode.com/problems/remove-linked-list-elements/description/
*/

#include <vector>
#include <iostream>

typedef struct ListNode ListNode;

class ListNode {
  public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int val) {
      data = val;
      next = nullptr;
    }

    ListNode(int val, ListNode *node) {
      data = val;
      next = node;
    }

    ListNode(int val, ListNode *nextNode, ListNode* prevNode) {
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

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode *arrayToLL(std::vector<int> &arr) {
  if (!arr.size())
    return nullptr;

  // * create the head node
  ListNode *head = new ListNode(arr[0]);
  
  // * create the tail node
  ListNode *tail = head;
  
  int n = arr.size();
  for(int i = 1; i < n; ++i) {
    ListNode *node = new ListNode(arr[i]);
    tail->next = node;
    
    tail = node;
  }

  return head;
}

ListNode* removeElements(ListNode* head, int val) {
  ListNode* temp = head;

  // * If list has all same nodes
  while (temp && temp->data == val) {
    temp = temp->next;
  }
  if (!temp)
    return nullptr;

  head = temp;

  while (temp) {
    while (temp->next && temp->next->data == val) {
      temp->next = temp->next->next;
    }
    temp = temp->next;
  }
  return head;
}

int main() {
  int val = 1;
  std::vector<int> arr = {1, 2};

  // int val = 6;
  // std::vector<int> arr = {1, 2, 6, 3, 4, 5, 6};
  
  // int val = 7;
  // std::vector<int> arr = {7, 7, 7, 7};
  
  ListNode* head = arrayToLL(arr);
  printLL(head);

  head = removeElements(head, val);
  printLL(head);
}

// * Run the code
// * g++ --std=c++20 13-remove-ll-elements.cpp -o output && ./output