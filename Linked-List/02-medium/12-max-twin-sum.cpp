/*
 * Leetcode - 2130
 * Maximum Twin Sum of a Linked List
 * 
 * In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is 
 * known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
 * 
 * Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 * Example 1
 * Input  : head = [5, 4, 2, 1]
 * Output : 6

 * Example 2
 * Input  : head = [4, 2, 2, 3]
 * Output : 7

 * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
*/

#include <stack>
#include <vector>
#include <iostream>
#include "../common.hpp"

ListNode* reverseLL(ListNode* head) {
  ListNode* tail = nullptr;  
  ListNode* cur = head;
  while (cur) {
    ListNode* front = cur->next;
    cur->next = tail;
    tail = cur;
    cur = front;
  }
  return tail;
}

// * Using Vector
int bruteForce(ListNode *head) {
  ListNode* temp = head;
  vector<int> vec;
  while (temp) {
    vec.push_back(temp->data);
    temp = temp->next;
  } 
  // printArr(vec);

  int i = 0, j = vec.size() - 1;
  int curSum = 0, maxSum = 0;
  while (i < j) {
    curSum = vec[i] + vec[j];
    maxSum = max(maxSum, curSum);
    i++, j--;
  }
  return maxSum;
}

// * Using Stack
int pairSumStack(ListNode *head) {
  ListNode* temp = head;
  stack<int> st;
  while (temp) {
    st.push(temp->data);
    temp = temp->next;
  } 
  
  temp = head;
  int max_sum = 0;
  int count = 0,  N = st.size();
  while (count <= N / 2) {
    max_sum = max(max_sum, temp->data + st.top());
    st.pop();
    count++;
    temp = temp->next;
  }

  return max_sum;
}

// * By reversing LL from the mid
int pairSum(ListNode *head) {
  // * Go to the mid of LL
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode *cur = head;
  ListNode *mid = reverseLL(slow);

  int max_sum = 0;
  while (mid) {
    // cout << cur->data + mid->data << endl;
    max_sum = max(max_sum, cur->data + mid->data);
    cur = cur->next;
    mid = mid->next;
  }
  return max_sum;
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {5, 4, 2, 1};

  // * testcase 2
  vector<int> nums = {4, 2, 2, 3};

  // * testcase 3
  // vector<int> nums = {47, 22, 81, 46, 94, 95, 90, 22, 55, 91, 6, 83, 49, 65, 10, 32, 41, 26, 83, 99, 14, 85, 42, 99, 89, 69, 30, 92, 32, 74, 9, 81, 5, 9};
  
  ListNode* head = arrayToLL(nums);
  printLL(head);

  // int ans = bruteForce(head);
  // int ans = pairSumStack(head);
  int ans = pairSum(head);
  cout << "Maximum Twin Sum of a Linked List " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-max-twin-sum.cpp -o output && ./output

