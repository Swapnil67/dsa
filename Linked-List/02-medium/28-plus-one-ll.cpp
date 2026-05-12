/*
 * Add 1 to a Linked List Number
 *
 * Example 1
 * 'num1' : 1 -> 5 -> 2 -> NULL
 * Output: 1 -> 5 -> 3 -> NULL
 *
 * Example 2
 * 'num1' : 1 -> 5 -> 9 -> NULL
 * Output:  1 -> 6 -> 0 -> NULL
 *
 * Example 2
 * 'num1' : 0 -> 1 -> NULL
 * 'num2' : 0 -> NULL
 * Output: 0 -> 1 -> NULL
 *
 * https://leetcode.com/problems/plus-one-linked-list/description/
 * https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557
 * https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
 * 
 */

#include <vector>
#include <iostream>
#include "../common.hpp"

using namespace std;

ListNode *reverse_ll(ListNode *head) {
  ListNode *tail = nullptr;
  ListNode *temp = head;

  while (temp) {
    ListNode *front = temp->next;
    temp->next = tail;
    tail = temp;
    temp = front;
  }

  return tail;
}

// * ------------------ Optimal ---------------------

// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
ListNode* addOne(ListNode* head) {
  if (!head)
    return head;

  ListNode* rev = reverse_ll(head);
  ListNode* temp = rev;
  ListNode* prev = temp;

  int val = temp->data;
  
  temp->data = (val + 1) % 10;
  int carry = (val + 1) / 10;
  temp = temp->next; // * go to next node

  while (carry && temp) { // * if carry 
    int val = temp->data;
    // cout << val << endl;
    temp->data = (val + 1) % 10;
    carry = (val + 1) / 10;
    prev = temp;
    temp = temp->next;
  }

  // * Append the carry to ll
  if (carry > 0) {
    prev->next = new ListNode(carry);
  }

  // * Reverse and return the answer
  return reverse_ll(rev);
}

int main() {
  // * testcase 1
  // vector<int> nums1 = {1, 2, 3};

  // * testcase 2
  // vector<int> nums1 = {9, 9};

  // * testcase 2
  vector<int> nums1 = {9, 9, 9, 9, 9, 9, 9};

  ListNode* n1_head = arrayToLL(nums1);

  cout << "Linked List" << endl;
  printLL(n1_head);

  ListNode* addHead = addOne(n1_head);
  cout<<"------------------- Answer ----------------------"<<endl;
  printLL(addHead);

  return 0;
}

// * Note whenever there is a need for new LL, always create a dummyNode node and return dummyNode->next

// * Run the code
// * g++ --std=c++20 28-plus-one-ll.cpp -o output && ./output

