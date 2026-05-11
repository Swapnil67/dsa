/*
 * Leetcode - 817
 * Linked List Components

 * You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of
 * the linked list values.
 * 
 * Return the number of connected components in nums where two values are connected if they appear consecutively
 * in the linked list.
 * 
 * Example 1:
 * Input        : head = [0,1,2,3], nums = [0,1,3]
 * Output       : 2
 * Explanation  : 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
 * 
 * Example 1:
 * Input        : head = [0,1,2,3,4], nums = [0,3,1,4]
 * Output       : 2
 * Explanation  : 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.

 * https://leetcode.com/problems/linked-list-components/description/
*/

// ! Google

#include <vector>
#include <iostream>
#include <unordered_set>
#include "../common.hpp"

// * ------------------ Optimal Approach ---------------------
// * Use set data structure
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int numComponents(ListNode *head, vector<int> &nums) {
  // * Push the nums to set
  unordered_set<int> st(begin(nums), end(nums)); // * O(N)

  int components = 0;
  bool streak = false;
  ListNode *temp = head;
  while (temp) { // * O(N)
    int val = temp->data;

    if (st.count(val) && !streak) { // * start a new streak
      streak = true;
      components += 1;
    }
    else if (!st.count(val) && streak) { // * End the current streak
      streak = false;
    }
    temp = temp->next;
  }

  return components;
}

int main(void) {
  // * testcase 1
  vector<int> arr = {0, 1, 2, 3};
  vector<int> nums = {0, 1, 3};

  // * testcase 2
  // vector<int> arr = {0, 1, 2, 3, 4};
  // vector<int> nums = {0, 3, 1, 4};

  ListNode* head = arrayToLL(arr);
  cout << "Linked List" << endl;
  printLL(head);

  int ans = numComponents(head, nums);
  cout << "Linked List Components: " << ans << endl;
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 14-ll-components.cpp -o output && ./output

