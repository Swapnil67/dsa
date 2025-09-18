/**
 * * Leetcode - 83
 * * Remove Duplicates from Sorted List
 * * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
 * * Return the linked list sorted as well.

 * * Example 1
 * * Input  : head = [1,1,2]
 * * Output : [1,2]

 * * Example 2
 * * Input  : head = [1,1,2,3,3]
 * * Output : [1,2,3]

 * * Example 3
 * * Input  : head = [1,1,1]
 * * Output : [1]

 * * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ListNode* deleteDuplicates(ListNode* head) {
  if (!head)
    return head;

  ListNode* temp = head;
  while (temp) {
    while (temp->next && temp->data == temp->next->data) {
      temp->next = temp->next->next;
    }
    temp = temp->next;
  }
  return head;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 1, 2};

  // * testcase 2
  // std::vector<int> arr = {1, 1, 1};
  
  // * testcase 3
  std::vector<int> arr = {1, 1, 2, 3, 3};

  ListNode* head = arrayToLL(arr);
  printLL(head);

  head = deleteDuplicates(head);
  printLL(head);
}

// * Run the code
// * g++ --std=c++20 14-remove-duplicates-from-ll.cpp -o output && ./output