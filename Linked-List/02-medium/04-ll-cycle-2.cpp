/*
 * Leetcode - 142
 * Linked List Cycle II
 * 
 * You are given a singly linked list that may or may not contain a cycle. 
 * You are supposed to return the node where the cycle begins, if a cycle exists, else return 'NULL'.
 * 
 * Example 1
 * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 1
 * Output : 1

 * Example 2
 * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
 * Output : 3
 * 
 * Example 3
 * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 * Output : NULL

 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 * https://www.naukri.com/code360/problems/linked-list-cycle-ii_1112628
*/

// ! Microsoft

#include <vector>
#include <iostream>
#include <unordered_map>
#include "../common.hpp"

// * Make Loop in LL
ListNode *makeLoop(ListNode *head) {
  ListNode* temp = head;
  // * Go till temp's tail
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = head->next; // * OR
  // temp->next = head;
  return head;
}

ListNode* findStartOfLoop(ListNode* head, ListNode* fast){
  ListNode* temp = head;
  while (temp != fast) {
    temp = temp->next;
    fast = fast->next;
  }
  return temp;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY O(N) + (2 * O(logN))
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head) {
  if (!head || !head->next)
    return nullptr;

  ListNode* temp = head;
  unordered_map<ListNode *, ListNode *> nodeMap;

  // * O(N)
  while(temp)
  {
    // * O(logN)
    if (nodeMap.count(temp))
      return temp;

    // * O(logN)
    nodeMap[temp] = temp;
    temp = temp->next;
  }
  return nullptr;
}

// * ------------------ Optimal Approach ---------------------
// * Tortise & Hare algorithrm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ListNode* detectCycle(ListNode* head) {
  if (!head || !head->next)
    return nullptr;

  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      break;
  }

  // * If Loop
  if (slow == fast) {
    return findStartOfLoop(head, fast);
  }

  return nullptr;
}

int main() {
  // * testcase 1
  vector<int> arr = {1, 2, 3, 4, 5};

  ListNode* head = arrayToLL(arr);
  printLL(head);

  // * Comment this for normal LL (Linear LL)
  head = makeLoop(head);

  // ListNode *loopStart = bruteForce(head);
  ListNode *loopStart = detectCycle(head);
  if (loopStart == nullptr) {
    cout << "Linear Linked List" << endl;
  } else {
    cout << "Start of Loop " << loopStart->data << endl;
  }
  
  return 0;
}


// * Run the code
// * g++ --std=c++17 04-ll-cycle-2.cpp -o output && ./output