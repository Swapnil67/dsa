/**
 * * Leetcode - 141
 * * Linked List Cycle
 * 
 * * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * * There is a cycle in a linked list if there is some node in the list that can be reached again by 
 * * continuously following the next pointer. Internally, pos is used to denote the index of the node that
 * * tail's next pointer is connected to. Note that pos is not passed as a parameter.

 * * Return true if there is a cycle in the linked list. Otherwise, return false.

 * * Example 1
 * * Input  : head = [3,2,0,-4], pos = 1
 * * Output : true

 * * Example 2
 * * Input  : head = [1,2], pos = 0
 * * Output : true
 * 
 * * Example 3
 * * Input  : head = [1], pos = -1
 * * Output : false

 * * https://leetcode.com/problems/linked-list-cycle/
*/

#include <vector>
#include <iostream>

typedef struct ListNode ListNode;

class ListNode {
  public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int val) {
      data = val;
      next = nullptr;
    }

    ListNode(int val, ListNode *node) {
      data = val;
      next = node;
    }

    ListNode(int val, ListNode *nextNode, ListNode* prevNode) {
      data = val;
      next = nextNode;
      prev = prevNode;
    }
};

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode *arrayToLL(std::vector<int> &arr) {
  if (!arr.size())
    return nullptr;

  // * create the head node
  ListNode *head = new ListNode(arr[0]);
  
  // * create the tail node
  ListNode *tail = head;
  
  int n = arr.size();
  for(int i = 1; i < n; ++i) {
    ListNode *node = new ListNode(arr[i]);
    tail->next = node;
    
    tail = node;
  }

  return head;
}

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool hasCycle(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }
  return false;
}

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 15-ll-cycle.cpp -o output && ./output