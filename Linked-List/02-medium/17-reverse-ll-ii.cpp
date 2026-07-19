/*
 * Leetcode - 92
 * Reverse Linked List II
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.

 * Example 1
 * Input  : head = [1,2,3,4,5], left = 2, right = 4
 * Output : [1,4,3,2,5]

 * Example 2
 * Input  : head = [5], left = 1, right = 1
 * Output : [5]

 * https://leetcode.com/problems/reverse-linked-list-ii/description/
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Apple, Adobe

#include <vector>
#include <iostream>
#include "../common.hpp"

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (!head || !head->next || left == right)
    return head;

  // * Important step (Add a extra node at start)
  ListNode *dummy = new ListNode(-1);
  dummy->next = head;

  ListNode *cur = head;
  ListNode *left_prev = dummy;

  // * 1. Get to the left node position
  int l = left;
  while (l - 1) {
    left_prev = cur;
    cur = cur->next;
    l--;
  }

  // * Now cur = "left", left_prev = "node before left"
  // * 2. Reverse from left to right
  ListNode* tail = nullptr;
  int k = (right - left + 1);
  while (k--) {
    ListNode *front = cur->next;
    cur->next = tail;
    tail = cur;
    cur = front;
  }
  // cout << left_prev->data << endl;
  // cout << cur->data << endl;

  // * 'cur' is at right + 1 postion
  // * 'tail' is at right postion

  // * 3. Update the pointers
  if (left_prev) {
    left_prev->next->next = cur;
    left_prev->next = tail;
  }

  return dummy->next;
}

int main(void) {
  // * testcase 1
  // int left = 2, right = 4;
  // vector<int> nums = {1, 2, 3, 4, 5};

  // * testcase 2
  int left = 1, right = 2;
  vector<int> nums = {3, 5};
  
  ListNode* head = arrayToLL(nums);
  cout << "Linked List Before Reverse" << endl;
  printLL(head);
  
  head = reverseBetween(head, left, right);
  cout << "Linked List After Reverse" << endl;
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-reverse-ll-ii.cpp -o output && ./output


