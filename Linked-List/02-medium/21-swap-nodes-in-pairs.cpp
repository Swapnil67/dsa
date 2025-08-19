/*
 * Leetcode - 24
 * Swap Nodes in Pairs
 * 
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values in the list's nodes 
 * (i.e., only nodes themselves may be changed.)

 * * Example 1
 * * Input  : head = [1,2,3,4]
 * * Output : [2,1,4,3]

 * * Example 2
 * * Input  : head = [1,2,3]
 * * Output : [2,1,3]

 * https://leetcode.com/problems/swap-nodes-in-pairs/
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

template <typename T>
void printArr(std::vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  printf("\n");
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
  int n = arr.size();
  if (n == 0)
    return nullptr;
  
  ListNode* head = new ListNode(arr[0]);
  ListNode* mover = head;
  
  for (int i = 1; i < n; ++i) {
    ListNode* newNode = new ListNode(arr[i]);
    mover->next = newNode;
    mover = newNode;
  }

  return head;
}

// * A - head
// * B - head->next
// * C - head->next->next

// * B -> A -> C
ListNode *swapPairs(ListNode *head) {
  // * base case
  if (!head || !head->next)
    return head;

  // * 2nd node in pair
  ListNode* temp = head->next;

  // * Do the same for next pair
  head->next = swapPairs(head->next->next);

  // * Point 2nd node to 1st one
  temp->next = head;
  return temp;  
} 

int main(void) {
  // * testcase 1
  std::vector<int> nums = {1, 2, 3, 4};

  ListNode* head = arrayToLL(nums);
  std::cout << "Linked List Before Swap" << std::endl;
  printLL(head);
  
  head = swapPairs(head);
  std::cout << "Linked List After Swap" << std::endl;
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-swap-nodes-in-pairs.cpp -o output && ./output


