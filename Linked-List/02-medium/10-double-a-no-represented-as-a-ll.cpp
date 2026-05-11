/*
 * Leetcode - 2816
 * Double a Number Represented as a Linked List

 * You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
 * Return the head of the linked list after doubling it.

 * Example 1
 * Input  : head = [1, 8, 9]
 * Output : [3, 7, 8]

 * Example 2
 * Input  : head = [9, 9, 9]
 * Output : [1, 9, 9, 8]

 * https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
*/

#include <vector>
#include <climits>
#include <iostream>
#include "../common.hpp"

ListNode* reverse_ll(ListNode* head) {
  if (!head || !head->next)
    return head;

  ListNode *current = head;
  ListNode *tail = nullptr;

  while (current) {
    // * keep this stored before hand
    ListNode *front = current->next;
    current->next = tail;
    tail = current;
    current = front;
  }

  return tail;
}

ListNode* doubleIt(ListNode* head) {
  if (!head)
    return head;

  // * Reverse initial Linked list
  ListNode* rev_head = reverse_ll(head);
  ListNode* temp = rev_head;

  int carry = 0;
  ListNode* prev = head;
  while (temp) {
    int num = carry + temp->data * 2;
    carry = num / 10;

    temp->data = num % 10;

    prev = temp; // * Use this if we have a carry after traversing the complete ll (Testcase 2)
    temp = temp->next;
  }

  // * Add the extra carry node
  if (carry) {
    prev->next = new ListNode(carry);
    prev = prev->next;
  }

  return reverse_ll(rev_head);
}

int main(void) {
  // * testcase 1
  // vector<int> arr = {1, 8, 9};

  // * testcase 2
  vector<int> arr = {9, 9, 9};

  ListNode *head = arrayToLL(arr);
  cout << "Linked List" << endl;
  printLL(head);

  ListNode* ans = doubleIt(head);
  printLL(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 10-double-a-no-represented-as-a-ll.cpp -o output && ./output

