/*
 * Leetcode - 237
 * Delete Node in a Linked List
 * 
 * 
 * 
 * https://leetcode.com/problems/delete-node-in-a-linked-list/ 
*/

#include <vector>
#include <iostream>
#include "../common.hpp"

// * Copy the next node to given node and then we can delete the next node easily.
// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
void deleteNode(ListNode *node) {
  node->data = node->next->data; // * copying the next node value
  node->next = node->next->next;   // * deleting the next node
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
