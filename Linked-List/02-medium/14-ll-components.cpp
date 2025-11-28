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

#include <stack>
#include <vector>
#include <iostream>
#include <unordered_set>

struct ListNode {
  public:
    int data;
    ListNode* next;

    ListNode(int val) {
      data = val;
      next = nullptr;
    }
};

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode* arrayToLL(std::vector<int> &arr) {
  ListNode *head = new ListNode(arr[0]);
  ListNode *mover = head;

  int n = arr.size();
  
  for(int i = 1; i < n; ++i) {
    ListNode *node = new ListNode(arr[i]);
    mover->next = node;
    mover = node;
  }

  return head;
}

// * ------------------ Optimal Approach ---------------------
// * Use set data structure
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int numComponents(ListNode *head, std::vector<int> &nums) {
  std::unordered_set<int> st;
  for (auto x : nums) // * O(N)
    st.insert(x);

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
  std::vector<int> arr = {0, 1, 2, 3};
  std::vector<int> nums = {0, 1, 3};

  // * testcase 2
  // std::vector<int> arr = {0, 1, 2, 3, 4};
  // std::vector<int> nums = {0, 3, 1, 4};

  ListNode* head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  int ans = numComponents(head, nums);
  std::cout << "Linked List Components: " << ans << std::endl;
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 14-ll-components.cpp -o output && ./output

