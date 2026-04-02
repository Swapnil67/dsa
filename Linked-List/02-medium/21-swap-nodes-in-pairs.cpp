/*
 * Leetcode - 24
 * Swap Nodes in Pairs
 * 
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values in the list's nodes 
 * (i.e., only nodes themselves may be changed.)

 * * Example 1
 * * Input  : head = [1,2,3,4]
 * * Output : [2,1,4,3]

 * * Example 2
 * * Input  : head = [1,2,3]
 * * Output : [2,1,3]

 * https://leetcode.com/problems/swap-nodes-in-pairs/
*/

#include <vector>
#include <iostream>
#include "../common.hpp"

using namespace std;

// * A - head
// * B - head->next
// * C - head->next->next

// * A -> B -> C     (Before Swap)
// * B -> A -> C     (After Swap)
ListNode *swapPairs(ListNode *head) {
  // * base case
  if (!head || !head->next)
    return head;

  // * Save 'B' for future
  ListNode* temp = head->next;

  // * A -> C
  head->next = swapPairs(head->next->next);

  // * B -> A
  temp->next = head;

  // * return B
  return temp;  
} 

int main(void) {
  // * testcase 1
  vector<int> nums = {1, 2, 3, 4};

  // * testcase 2
  // vector<int> nums = {1};

  ListNode* head = arrayToLL(nums);
  cout << "Linked List Before Swap" << endl;
  printLL(head);
  
  head = swapPairs(head);
  cout << "Linked List After Swap" << endl;
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-swap-nodes-in-pairs.cpp -o output && ./output


/*
temp = 2
*/