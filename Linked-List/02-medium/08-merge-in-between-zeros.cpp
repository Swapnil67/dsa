/**
 * * Leetcode - 2181
 * * Merge Nodes in Between Zeros

 * * You are given the head of a linked list, which contains a series of integers separated by 0's. 
 * * The beginning and end of the linked list will have ListNode.val == 0.

 * * For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value 
 * * is the sum of all the merged nodes. The modified list should not contain any 0's.

 * * Example 1
 * * Input  : head = [0, 3, 1, 0, 4, 5, 2, 0]
 * * Output : [4, 11]

 * * Example 2
 * * Input  : head = [0, 1, 0, 3, 0, 2, 2, 0]
 * * Output : [1, 3, 4]

 * * https://leetcode.com/problems/merge-nodes-in-between-zeros/description/
*/

#include <vector>
#include <iostream>

class ListNode {
  public:
    int data;
    ListNode* next;
    
    ListNode(int val) {
      this->data = val;
      this->next = nullptr;
    }
    
    ListNode(int val, ListNode* node) {
      this->data = val;
      this->next = node;
    }
};

void printLL(ListNode* head) {
  ListNode* temp = head;
  while(temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode* arrayToLL(std::vector<int> &arr) {
  if (!arr.size())
    return nullptr;

  ListNode* head = new ListNode(arr[0]);
  ListNode* mover = head;

  for (int i = 1; i < arr.size(); ++i) {
    ListNode* node = new ListNode(arr[i]);
    mover->next = node;
    mover = node;
  }

  return head;
}

// * ------------------ Brute Force ---------------------
// * Using Extra Linked List
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head) {
  ListNode *ans = nullptr;
  if (!head)
    return ans;

  ans = new ListNode(head->next->data);
  ListNode *mover = ans;
  
  ListNode *temp = head->next->next;
  while (temp) {
    if (temp->data == 0) {
      if (temp->next) { // * To prevent adding the last zero to ans ll
        ListNode *node = new ListNode(0);
        mover->next = node;
        mover = node;
      }
    }

    mover->data += temp->data;
    temp = temp->next;
  }

  return ans;
}

// * ------------------ Optimal Solution ---------------------
// * Using In place method
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ListNode* mergeNodes(ListNode* head) {
  if (!head)
    return head;

  ListNode *temp = head->next;
  while (temp) {
    ListNode *cur = temp;
    while (temp && temp->data != 0) {
      if (temp != cur) { // * Initially both are pointing at same node
        cur->data += temp->data;
      }
      temp = temp->next;
    }
    temp = temp->next;
    cur->next = temp;
  }

  return head->next;
}

int main(void) {
  std::vector<int> arr = {0, 3, 1, 0, 4, 5, 2, 0};
  // std::vector<int> arr = {0, 1, 0, 3, 0, 2, 2, 0};
  // std::vector<int> arr = {0, 24, 14, 0};

  ListNode* head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  // ListNode* ans = bruteForce(head);
  ListNode* ans = mergeNodes(head);
  printLL(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-merge-in-between-zeros.cpp -o output && ./output
