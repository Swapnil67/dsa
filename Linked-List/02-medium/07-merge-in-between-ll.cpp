/**
 * * Leetcode - 1669
 * * Merge In Between Linked Lists

 * * You are given two linked lists: list1 and list2 of sizes n and m respectively.
 * * Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
 * * The blue edges and nodes in the following figure indicate the result:

 * * Example 1
 * * Input  : list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
 * * Output : [10,1,13,1000000,1000001,1000002,5]

 * * Example 2
 * * Input  : list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
 * * Output : [0,1,1000000,1000001,1000002,1000003,1000004,6]

 * * https://leetcode.com/problems/merge-in-between-linked-lists/description/
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

ListNode* arrToLL(std::vector<int> &arr) {
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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

  ListNode* nodeBegin = list1;
  ListNode* temp = list1;

  // * Get the 'a - 1' node in nodeBegin & temp to 'b'
  for(int i = 0; i < b; ++i) {
    if (i == a - 1)
      nodeBegin = temp;
    temp = temp->next;
  }

  // std::cout << nodeBegin->data << " " << temp->data << std::endl;

  // * Go to the tail of list2
  ListNode *tail2 = list2;
  while (tail2->next) {
    tail2 = tail2->next;
  }

  nodeBegin->next = list2;
  tail2->next = temp->next;

  return list1; 
}


int main(void) {
  // * testcase 1
  int a = 3, b = 4;
  std::vector<int> list1 = {10, 1, 13, 6, 9, 5};
  std::vector<int> list2 = {1000000, 1000001, 1000002};

  // * testcase 2
  // int a = 2, b = 5;
  // std::vector<int> list1 = {0, 1, 2, 3, 4, 5, 6};
  // std::vector<int> list2 = {1000000, 1000001, 1000002, 1000003, 1000004};

  ListNode* head1 = arrToLL(list1);
  ListNode* head2 = arrToLL(list2);

  std::cout << "Linked List 1" << std::endl;
  printLL(head1);
  std::cout << "Linked List 2" << std::endl;
  printLL(head2);

  head1 = mergeInBetween(head1, a, b, head2);
  printLL(head1);

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-merge-in-between-ll.cpp -o output && ./output
