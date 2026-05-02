/*
 * Leetcode - 2
 * Add Two Numbers
 * 
 * You are given two non-negative numbers 'num1' and 'num2' represented in the form of linked lists.
 *
 * Example 1
 * 'num1' : 1 -> 2 -> 3 -> NULL
 * 'num2' : 4 -> 5 -> 6 -> NULL
 * Output: 5 -> 7 -> 9 -> NULL
 *
 * Example 2
 * 'num1' : 0 -> 1 -> NULL
 * 'num2' : 0 -> NULL
 * Output: 0 -> 1 -> NULL
 *
 * https://leetcode.com/problems/add-two-numbers/
 * https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

// ! Amazon, Google, Meta, Microsoft, Adobe, Uber, ByteDance

#include <vector>
#include <iostream>
#include "../common.hpp"

// * ------------------ APPROACH 2: Brute Force ---------------------
// * TIME COMPLEXITY O(max(h1, h1))
// * SPACE COMPLEXITY O(max(h1, h1))
ListNode* bruteForce(ListNode* head) {
  if (!head)
    return head;

  // * Step 1. Create a vector from given LL
  ListNode* temp = head;
  vector<int> arr;
  while (temp) {
    arr.push_back(temp->data);
    temp = temp->next;
  }

  // * Step 2. Separate even & odd indices nodes from arr
  vector<int> even_arr, odd_arr;
  for (int i = 1; i <= arr.size(); ++i) {
    if (i % 2 == 0)
      even_arr.push_back(arr[i - 1]);
    else
      odd_arr.push_back(arr[i - 1]);
  }
  for (auto &x : even_arr) {
    odd_arr.push_back(x);
  }

  // * Step 3. Make a LL from array
  ListNode* ans = new ListNode(-1);
  ListNode* mover = ans;
  for (int i = 0; i < odd_arr.size(); ++i) {
    ListNode *node = new ListNode(odd_arr[i]);
    mover->next = node;
    mover = node;
  }
  return ans->next;
}

// * ------------------ APPROACH 1: Optimal ---------------------
// * TIME COMPLEXITY O(max(h1, h1))
// * SPACE COMPLEXITY O(max(h1, h1))
ListNode* addTwoLL(ListNode* h1, ListNode* h2) {
  ListNode* ans = new ListNode(0);
  ListNode* mover = ans;
  int carry = 0;
  while (h1 != NULL || h2 != NULL) {
    int sum = carry;

    if (h1) {
      sum = sum + h1->data;
      h1 = h1->next;
    }

    if (h2) {
      sum = sum + h2->data;
      h2 = h2->next;
    }

    ListNode *node = new ListNode(sum % 10);
    carry = sum / 10;
    mover->next = node;
    mover = node;
  }

  // * check if carry set
  if(carry > 0) {
    ListNode* carryNode = new ListNode(carry);
    mover->next = carryNode;
  }

  return ans->next;
}

int main() {
  // * testcase 1
  vector<int> nums1 = { 1, 2, 3 };
  vector<int> nums2 = { 4, 5, 9 };

  // * testcase 2
  // vector<int> nums1 = { 0, 1 };
  // vector<int> nums2 = { 0 };

  // * testcase 2
  // vector<int> nums1 = {9, 9, 9, 9, 9, 9, 9};
  // vector<int> nums2 = {9, 9, 9, 9};

  ListNode* n1_head = arrayToLL(nums1);
  ListNode* n2_head = arrayToLL(nums2);

  cout<<"First Linked List"<<endl;
  printLL(n1_head);
  cout<<"Second Linked List"<<endl;
  printLL(n2_head);

  ListNode* addHead = addTwoLL(n1_head, n2_head);
  cout<<"-----------------------------------------"<<endl;
  // cout<<"Sum of two Linked List"<<endl;
  printLL(addHead);

  return 0;
}

// * Note whenever there is a need for new LL, always create a dummyNode node and return dummyNode->next

// * Run the code
// * g++ --std=c++20 01-add-two-ll.cpp -o output && ./output

