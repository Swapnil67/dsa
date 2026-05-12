/*
 * Leetcode - 61
 * Rotate List
 * 
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * Example 1 :
 * Input     : head = [1,2,3,4,5], k = 2
 * Output    : [4,5,1,2,3]
 * 
 * Example 2 :
 * Input     : head = [0,1,2], k = 4
 * Output    : [2,0,1]
 * 
 * https://leetcode.com/problems/rotate-list/description/
 * https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1
 * https://www.naukri.com/code360/problems/rotate-linked-list_920454
 * 
*/

#include <vector>
#include <iostream>
#include "../common.hpp"

using namespace std;

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head, int k) {
  if (!head || !head->next)
    return head;

  // * 1. Get the length of LL
  int n = lengthOfLL(head);

  k = k % n;

  ListNode *temp = new ListNode(-1);
  ListNode *mover = temp;
  
  // * 2. Take nodes fron 'n - k' to 'n' into a new list
  ListNode *temp2 = head;
  int i = 0;
  while (temp2) {
    if (i >= n - k) {
      ListNode *newNode = new ListNode(temp2->data);
      mover->next = newNode;
      mover = newNode;
    }
    i++;
    temp2 = temp2->next;
  }

  // * 3. Take first 'n - k' nodes and append to ans list
  temp2 = head;
  i = 0;
  while (temp2) {
    if (i < n - k) {
      ListNode *newNode = new ListNode(temp2->data);
      mover->next = newNode;
      mover = newNode;
    }
    i++;
    temp2 = temp2->next;
  } 

  return temp->next;
}

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(1)
ListNode* rotateRight(ListNode* head, int k) {
  if (!head || !head->next)
    return head;

  // * 1. Get the length of LL
  int n = lengthOfLL(head);
  k = k % n;

  // * 2. Go to the (n - k)th node in ll
  int i = 1;
  ListNode *temp = head;
  while (i < n - k) {
    i++;
    temp = temp->next;
  }
  cout << temp->data << endl;

  // * 3. Go to the tail of LL
  ListNode *tail = temp;
  while (tail->next) {
    tail = tail->next;
  }

  // * 4. Point tail to head of ll
  tail->next = head;

  // * 5. Save the new head
  ListNode *new_head = temp->next;
  // * make (n - k)th node point to nullptr
  temp->next = nullptr;

  return new_head;
}

int main(void) {
  // * testcase 1
  // int k = 2;
  int k = 3;
  vector<int> nums = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 4;
  // vector<int> nums = {0, 1, 2};

  ListNode* head = arrayToLL(nums);
  cout << "Linked List Before Rotating" << endl;
  printLL(head);

  cout << "Linked List After Rotating " << k << " times." << endl;
  // ListNode* ans = bruteForce(head, k);
  ListNode *ans = rotateRight(head, k);
  printLL(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-rotate-list.cpp -o output && ./output


