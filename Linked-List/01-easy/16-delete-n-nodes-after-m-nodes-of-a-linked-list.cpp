/*
 * Leetcode - ?
 * Delete N Nodes After M Nodes of a Linked List
 * 
 * You are given the head of a linked list and two integers m and n.

 * Traverse the linked list and remove some nodes in the following way:
 * - Start with the head as the current node.
 * - Keep the first m nodes starting with the current node.
 * - Remove the next n nodes
 * - Keep repeating steps 2 and 3 until you reach the end of the list.
 * 
 * Return the head of the modified list after removing the mentioned nodes.

 * Example 1
 * Input  : head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
 * Output : [1,2,6,7,11,12]

 * Example 2
 * Input  : head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
 * Output : [1,5,9]

 * https://neetcode.io/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/question
 * https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/
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
ListNode *deleteNodes(ListNode *head, int m, int n) {
  if (!head)
    return head;

  ListNode *cur = head;
  ListNode *last = head;

  while (cur) {
    int m_count = m, n_count = n;
    while (cur && m_count) {
      last = cur;
      cur = cur->next;
      m_count--;
    }
    while (cur && n_count) {
      cur = cur->next;
      n_count--;
    }
    last->next = cur;
  }

  return head;
} 

int main() {
  // * testcase 1
  // int m = 2, n = 3;
  // std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  
  // * testcase 2
  int m = 1, n = 3;
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  ListNode *head = arrayToLL(arr);
  printLL(head);

  ListNode* ans = deleteNodes(head, m, n);
  printLL(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 16-delete-n-nodes-after-m-nodes-of-a-linked-list.cpp -o output && ./output