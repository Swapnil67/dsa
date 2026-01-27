/**
 * * Leetcode - 2095
 * * Delete the Middle ListNode of a Linked List
 * * Given a singly linked list of 'N' nodes. Your task is to delete the middle node of this list and return the head of the modified list.

 * * Example 1
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * * Output : 1 -> 2 -> 4 -> 5 -> NULL

 * * Example 2
 * * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 * * Output : 1 -> 2 -> 3 -> 5 -> 6 -> NULL 

 * * Example 2
 * * Input  : 1 -> NULL
 * * Output : -1

 * * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 * * https://www.naukri.com/code360/problems/delete-middle-node_763267?leftPanelTabValue=PROBLEM
*/

// ! Microsoft

#include <vector>
#include <iostream>

class ListNode {
  public:
    int data;
    ListNode* next;
  
  ListNode(int d) {
    this->data = d;
    this->next = nullptr;
  }

  ListNode(int d, ListNode* n) {
    this->data = d;
    this->next = n;
  }
};

// * ------------------- Utility Functions ---------------------

ListNode* arrayToLL(std::vector<int> arr) {
  if(!arr.size()) return nullptr;

  ListNode* head = new ListNode(arr[0]);
  ListNode* temp = head;

  for(int i=1; i<arr.size(); i++) {
    ListNode* newNode = new ListNode(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }

  return head;
}

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

int countLL(ListNode* head) {
  ListNode* temp = head;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  }
  return c;
}

// * ------------------ Brute Force Approach ---------------------
// * Count the no. of nodes & go to n/2
// * TIME COMPLEXITY  O(N) + O(N/2)
// * SPACE COMPLEXITY O(1)
ListNode* bruteForce(ListNode* head) {
  if (!head || !head->next)
    return nullptr;

  ListNode* temp = head;
  // * O(N)
  int c = countLL(head);
  
  // * O(N/2)
  ListNode *temp = head;
  int mid_idx = (c / 2) - 1;
  while (mid_idx != 0) {
    temp = temp->next;
    mid_idx -= 1;
  }

  ListNode *del_node = temp->next;
  temp->next = temp->next->next;
  delete del_node;
  return head;
}

// * ------------------ Optimal Approach ---------------------
// * Tortise & Hare algorithrm
// * TIME COMPLEXITY  O(N/2)
// * SPACE COMPLEXITY O(1)
ListNode* deleteMiddle(ListNode* head) {
  if (!head || !head->next)
    return head;

  ListNode* slow = head;
  ListNode* fast = head;
  
  // * Move the fast pointer once
  fast = fast->next;
  if (fast) {
    fast = fast->next;
  }

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // * Here slow is at mid - 1 index in ll
  ListNode* del_node = slow->next;
  slow->next = slow->next->next;
  std::free(del_node);

  return head;
} 

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // std::vector<int> arr = {1, 2, 3, 4, 5, 6};

  // * testcase 3
  std::vector<int> arr = {1, 2};

  ListNode *head = arrayToLL(arr);
  std::cout << "Before Deleting Middle ListNode" << std::endl;
  printLL(head);

  std::cout << "After Deleting Middle ListNode" << std::endl;
  // head = bruteForce(head);
  head = deleteMiddle(head);
  printLL(head);

  return 0;
}


// * Run the code
// * g++ --std=c++17 05-delete-middle-of-ll.cpp -o output && ./output