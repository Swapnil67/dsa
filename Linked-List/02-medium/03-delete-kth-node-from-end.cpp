/*
 * Leetcode - 19
 * Remove Nth Node From End of List
 * 
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Example 1
 * Input  : head = [1,2,3,4,5], n = 2
 * Output : [1,2,3,5]
 * 
 * Example 2
 * Input  : head = [1], n = 1
 * Output : []
 * 
 * Example 3
 * Input  : head = [1,2], n = 1
 * Output : [1]
 * 
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * https://www.naukri.com/code360/problems/delete-kth-node-from-end_799912
*/

// ! Microsoft, Amazon, Meta, Oracle

#include <stack>
#include <vector>
#include <iostream>
#include "../common.hpp"

int count_ll(ListNode *head) {
  ListNode *temp = head;
  int i = 0;
  while (temp) {
    i += 1;
    temp = temp->next;
  }
  return i;
}

ListNode* reverseLL(ListNode* node) {
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

// * ------------------ APPROACH 1: Brute Force ---------------------
// * Using Stack
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head, int n) {
  // * 1. Push all elements to the stack
  stack<int> st;
  ListNode* temp = head;
  while (temp) {
    st.push(temp->data);
    temp = temp->next;
  }

  // * 2. Pop the stack elements and create a new LL from that
  ListNode* new_head = new ListNode(-1);
  ListNode* mover = new_head;

  int i = 1;
  while (!st.empty()) {
    int val = st.top();
    st.pop();

    // * Exclude the nth element fron end
    if (i == n) 
      continue;

    ListNode* node = new ListNode(val);
    mover->next = node;
    mover = node;
    i++;
  }

  // * 3. Reverse the newly created LL && return
  return reverseLL(new_head->next);
}


// * ------------------ APPROACH 2: Optimal Solution ---------------------
// * TIME COMPLEXITY O(N/2) * 2 = O(N)
// * SPACE COMPLEXITY O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (!head)
      return head;

  // * Count LL Nodes
  int cnt = count_ll(head);

  // * Since we are removing from end
  if (cnt == n) { 
    // * Remove Head
    ListNode *new_head = head->next;
    delete head;
    return new_head;
  }

  ListNode* temp = head;

  // * Traverse to the node just before the one to delete
  int k = (cnt - n) - 1;
  while (k--) {
    temp = temp->next;
  }

  // * Delete the Nth node from the end
  ListNode* delete_node = temp->next;
  temp->next = temp->next->next;
  delete delete_node;

  return head;
}

// * ------------------ APPROACH 2: Optimal Approach ---------------------
// * Using Slow & fast pointers
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *slowp = head;
  ListNode *fastp = head;

  // * Move fast pointer 'n' steps
  for (int i = 0; i < n; ++i) {
    fastp = fastp->next;
  }

  // * Remove the head pointer
  if (!fastp)
    return head->next;
    
  // * Move both pointers 1 step
  while (fastp->next) {
    slowp = slowp->next;
    fastp = fastp->next;
  }

  ListNode* del_node = slowp->next;
  slowp->next = slowp->next->next;
  delete del_node;
  return head;
}


int main(void) {
  // int n = 2;
  // vector<int> arr = {1, 2, 3, 4, 5};

  // int n = 1;
  // vector<int> arr = {1};

  int n = 1;
  vector<int> arr = {1, 2};

  ListNode* head = arrayToLL(arr);
  cout << "Linked List" << endl;
  printLL(head);

  // ListNode *ans = bruteForce(head, n);
  ListNode *ans = removeNthFromEnd(head, n);
  printLL(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 14-remove-nth-node-from-end.cpp -o output && ./output

