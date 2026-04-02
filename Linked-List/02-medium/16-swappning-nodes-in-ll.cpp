/*
 * Leetcode - 1721
 * Swapping Nodes in a Linked List
 * 
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node from the beginning 
 * and the kth node from the end (the list is 1-indexed).

 * * Example 1
 * * Input  : head = [1,2,3,4,5], k = 2
 * * Output : [1,4,3,2,5]

 * * Example 2
 * * Input  : head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * * Output : [7,9,6,6,8,7,3,0,9,5]

 * https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
*/

#include <stack>
#include <vector>
#include <iostream>
#include "../common.hpp"

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

// * ------------------ Optimal Solution ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
ListNode* bruteForce(ListNode* head, int k) {
  // * Get the kth node from begining
  int t = k - 1;
  int first_val = -1;
  ListNode *first = nullptr;
  std::stack<ListNode *> st;
  ListNode *temp = head;
  while (temp) {
    if (t == 0) {
      first = temp;
      first_val = first->data;
    }
    st.push(temp);
    temp = temp->next;
    t--;
  }

  // * Get the kth node from end
  t = k - 1;
  int second_val = -1;
  ListNode *second = nullptr;
  while (!st.empty()) {
    if (t == 0) {
      second = st.top();
      second_val = second->data;
    }
    t--;
    st.pop();
  }

  // std::cout << "First: " << first->data << std::endl;
  // std::cout << "Second: " << second->data << std::endl;

  // * Loop over the ll and change the values of kth nodes from start & end.
  temp = head;
  while (temp) {
    if (temp == first) {
      temp->data = second_val;
    } else if(temp == second) {
      temp->data = first_val;
    }
    temp = temp->next;
  }

  return head;
}

// * ------------------ Optimal Solution ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
ListNode* swapNodes(ListNode* head, int k) {
  if (!head)
    return head;

  // * 1. Get the length of ll
  int length = countLL(head);
  if (k > length)
    return head;

  ListNode *node1 = nullptr;
  ListNode *node2 = nullptr;

  // * 2. Get the kth node from begining & end
  int i = 1;
  ListNode* temp = head;
  while (temp) {
    if (i == k) {
      node1 = temp;
    } 
    else if (i == (length - k + 1)) {
      node2 = temp;
    }
    i++;
    temp = temp->next;
  }

  // * 3. Swap the two numbers
  swap(node1->data, node2->data);

  return head;
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // std::vector<int> nums = {1, 2, 3, 4, 5};
  
  // * testcase 2
  int k = 5;
  std::vector<int> nums = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};

  ListNode* head = arrayToLL(nums);
  std::cout << "Linked List Before Swap" << std::endl;
  printLL(head);
  
  // head = bruteForce(head, k);
  head = swapNodes(head, k);
  std::cout << "Linked List After Swap" << std::endl;
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-swappning-nodes-in-ll.cpp -o output && ./output


