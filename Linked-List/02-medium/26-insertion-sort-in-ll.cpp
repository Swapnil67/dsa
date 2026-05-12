/*
 * Leetcode - 147
 * Insertion Sort List
 * 
 * Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
 * 
 * 1. Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
 * 2. At each iteration, insertion sort removes one element from the input data, 
 *    finds the location it belongs within the sorted list and inserts it there.
 * 3. It repeats until no input elements remain.

 * Example 1
 * Input  : head = [4,2,1,3]
 * Output : [1,2,3,4]

 * https://leetcode.com/problems/insertion-sort-list/description/
 * https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1
*/

// ! Amazon, Google, Meta, Microsoft

#include <vector>
#include <climits>
#include <iostream>
#include "../common.hpp"

using namespace std;

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY  O(N^2)
// * SPACE COMPLEXITY O(1)
ListNode* insertionSortList(ListNode* head) {
  if (!head || !head->next)
    return head;

  ListNode *dummy = new ListNode(INT_MIN);
  dummy->next = head;

  ListNode* prev = dummy;
  ListNode* cur = dummy->next;
  while (cur) {
    // * cur node is greater than prev (Already Sorted)
    if (cur->data > prev->data) {
      prev = cur;
      cur = cur->next;
      continue;
    }

    // * save the `nextNode` for next iteration
    ListNode* next_node = cur->next;
    prev->next = next_node;

    // * From the start of list find the new Insert position for 'temp' node
    ListNode *temp2 = dummy;
    while (temp2->next->data < cur->data) {
      temp2 = temp2->next;
    }
    cur->next = temp2->next;
    temp2->next = cur;

    cur = next_node;
  }

  return dummy->next;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {4, 2, 1, 3};

  ListNode* head = arrayToLL(nums);
  cout << "Linked List Before Sorting" << endl;
  printLL(head);

  cout << "Linked List After Sorting" << endl;
  ListNode *ans = insertionSortList(head);
  printLL(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-insertion-sort-in-ll.cpp -o output && ./output


