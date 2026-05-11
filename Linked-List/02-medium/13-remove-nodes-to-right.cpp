/*
 * Leetcode - 2487
 * Remove Nodes From Linked List

 * You are given the head of a linked list.
 * Remove every node which has a node with a greater value anywhere to the right side of it.
 * Return the head of the modified linked list.

 * Example 1
 * Input  : head = [5, 2, 13, 3, 8]
 * Output : [13, 8]

 * Example 2
 * Input  : head = [1, 1, 1, 1]
 * Output : [1, 1, 1, 1]

 * https://leetcode.com/problems/remove-nodes-from-linked-list/description/
*/

// ! Amazon, Google, Meta, Microsoft

#include <stack>
#include <vector>
#include <iostream>

#include "../common.hpp"

ListNode* reverse_ll(ListNode* node) {
  // * Reverse the node LL
  ListNode* tail = nullptr;
  while (node) {
    ListNode* front = node->next;
    node->next = tail;
    tail = node;
    node = front;
  }
  return tail;
}

// * ------------------ Brute Force Approach ---------------------
// * Monotonic stack
// * TIME COMPLEXITY O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head) {
  // * Push on to stack in monotonic decreasing way
  stack<int> st;
  ListNode* temp = head;
  while (temp) { // * O(N)
    while (!st.empty() && st.top() < temp->data) {
      st.pop();
    }
    st.push(temp->data);
    temp = temp->next;
  }

  // * Create a ll from stack elements
  ListNode *ans = new ListNode(-1);
  ListNode* mover = ans;
  while (!st.empty()) { // * O(N)
    // cout << st.top() << endl;
    ListNode *node = new ListNode(st.top());
    mover->next = node;
    mover = node;
    st.pop();
  }
  ans = ans->next;

  // * Reverse the ans LL
  ListNode* tail = reverse_ll(ans);

  return tail;
}

// * ------------------ Optimal Approach ---------------------
// * Reverse LL
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ListNode* removeNodes(ListNode* head) {
  ListNode *temp = head;

  // * Reverse the temp LL
  ListNode* tail = reverse_ll(temp);
  temp = tail;
  while (temp) {
    while (temp->next && temp->data > temp->next->data) {
      temp->next = temp->next->next;
    }
    temp = temp->next;
  }

  // * Reverse the temp LL
  return reverse_ll(tail);
}


int main(void) {
  // * testcase 1
  // vector<int> arr = {5, 2, 13, 3, 8};

  // * testcase 2
  vector<int> arr = {1, 1, 1, 1};

  ListNode* head = arrayToLL(arr);
  cout << "Linked List" << endl;
  printLL(head);

  // ListNode *ans = bruteForce(head);
  ListNode *ans = removeNodes(head);
  cout << "After Removing Nodes" << endl;
  printLL(ans);
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 13-remove-nodes-to-right.cpp -o output && ./output

