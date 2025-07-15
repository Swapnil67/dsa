/**
 * * Leetcode - 2487
 * * Remove Nodes From Linked List

 * * You are given the head of a linked list.
 * * Remove every node which has a node with a greater value anywhere to the right side of it.
 * * Return the head of the modified linked list.

 * * Example 1
 * * Input  : head = [5, 2, 13, 3, 8]
 * * Output : [13, 8]

 * * Example 2
 * * Input  : head = [1,1,1,1]
 * * Output : [1,1,1,1]

 * * https://leetcode.com/problems/remove-nodes-from-linked-list/description/
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

ListNode* bruteForce(ListNode* head) {
  std::stack<int> st;
  ListNode* temp = head;
  while (temp) {
    while (!st.empty() && st.top() < temp->data) {
      st.pop();
    }
    st.push(temp->data);
    temp = temp->next;
  }

  ListNode *ans = new ListNode(-1);
  ListNode* mover = ans;
  while (!st.empty()) {
    // std::cout << st.top() << std::endl;
    ListNode *node = new ListNode(st.top());
    mover->next = node;
    mover = node;
    st.pop();
  }
  ans = ans->next;

  // * Reverse the ans LL
  ListNode* tail = reverseLL(ans);

  return tail;
}

ListNode* removeNodes(ListNode* head) {
  ListNode *temp = head;

  // * Reverse the temp LL
  ListNode* tail = reverseLL(temp);

  temp = tail;
  while (temp) {
    while (temp->next && temp->data > temp->next->data) {
      temp->next = temp->next->next;
    }
    temp = temp->next;
  }

  // * Reverse the temp LL
  tail = reverseLL(tail);

  return tail;
}


int main(void) {
  std::vector<int> arr = {5, 2, 13, 3, 8};

  ListNode* head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  // ListNode *ans = bruteForce(head);
  ListNode *ans = removeNodes(head);
  printLL(ans);
}


// * Run the code
// * g++ --std=c++20 13-remove-nodes-to-right.cpp -o output && ./output

