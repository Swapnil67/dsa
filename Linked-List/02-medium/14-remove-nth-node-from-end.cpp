/**
 * * Leetcode - 19
 * * Remove Nth Node From End of List
 * 
 * * Given the head of a linked list, remove the nth node from the end of the list and return its head.

 * * Example 1
 * * Input  : head = [1,2,3,4,5], n = 2
 * * Output : [1,2,3,5]

 * * Example 2
 * * Input  : head = [1], n = 1
 * * Output : []

 * * Example 3
 * * Input  : head = [1,2], n = 1
 * * Output : [1]

 * * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/

#include <stack>
#include <vector>
#include <iostream>

// struct ListNode ListNode;

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
  std::stack<int> st;
  ListNode* temp = head;
  while (temp) {
    st.push(temp->data);
    temp = temp->next;
  }

  // * 2. Pop the stack elements and create a new LL from that
  ListNode* newHead = new ListNode(-1);
  ListNode* mover = newHead;
  int i = 0;
  while (!st.empty()) {
    i++;
    int val = st.top();
    st.pop();
    // * Exclude the nth element fron end
    if (i == n) 
      continue;
    ListNode* node = new ListNode(val);
    mover->next = node;
    mover = node;
  }

  // * 3. Reverse the newly created LL && return
  return reverseLL(newHead->next);
}

// * ------------------ APPROACH 2: Optimal Approach ---------------------
// * Using Slow & fast pointers
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *slowp = head;
  ListNode *fastp = head;

  for (int i = 0; i < n; ++i) {
    fastp = fastp->next;
  }

  if (!fastp)
    return head->next;
    
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
  // std::vector<int> arr = {1, 2, 3, 4, 5};

  // int n = 1;
  // std::vector<int> arr = {1};

  int n = 1;
  std::vector<int> arr = {1, 2};

  ListNode* head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  // ListNode *ans = bruteForce(head, n);
  ListNode *ans = removeNthFromEnd(head, n);
  printLL(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 14-remove-nth-node-from-end.cpp -o output && ./output

