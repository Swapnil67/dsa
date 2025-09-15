/*
 * Leetcode - 92
 * Reverse Linked List II
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.

 * * Example 1
 * * Input  : head = [1,2,3,4,5], left = 2, right = 4
 * * Output : [1,4,3,2,5]

 * * Example 2
 * * Input  : head = [5], left = 1, right = 1
 * * Output : [5]

 * https://leetcode.com/problems/reverse-linked-list-ii/description/
*/

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

ListNode* arrayToLL(std::vector<int> &arr) {
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

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (!head || !head->next)
    return head;

  if (left == right)
    return head;

  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
    
  ListNode* cur = head;
  ListNode* leftPrev = dummy;

  // * 1. Get to the left node position
  int l = left;
  while (l - 1) {
    leftPrev = cur;
    cur = cur->next;
    l--;
  }

  // * Now cur = "left", leftPrev = "node before left"
  // * 2. Reverse from left to right
  ListNode* tail = nullptr;
  int n = right - left + 1;
  while (n) {
    ListNode* front = cur->next;
    cur->next = tail;
    tail = cur;
    cur = front;
    n -= 1;
  }
  // std::cout << leftPrev->data << std::endl;
  // std::cout << cur->data << std::endl;

  // * 3. Update the pointers
  if (leftPrev) {
    leftPrev->next->next = cur;
    leftPrev->next = tail;
  }

  return dummy->next;
}

int main(void) {
  // * testcase 1
  int left = 2, right = 4;
  std::vector<int> nums = {1, 2, 3, 4, 5};

  // * testcase 2
  // int left = 1, right = 2;
  // std::vector<int> nums = {3, 5};
  
  ListNode* head = arrayToLL(nums);
  std::cout << "Linked List Before Reverse" << std::endl;
  printLL(head);
  
  head = reverseBetween(head, left, right);
  std::cout << "Linked List After Reverse" << std::endl;
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-reverse-ll-ii.cpp -o output && ./output


