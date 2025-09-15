/*
 * Leetcode - 148
 * Sort List
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

 * https://leetcode.com/problems/sort-list/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

  for(int i = 1; i < n; ++i) {
    ListNode *newNode = new ListNode(arr[i]);
    mover->next = newNode;
    mover = newNode;
  }

  return head;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY  O(N) + O(NlogN) + O(N)
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head) {
  if (!head || !head->next)
    return head;

  // * 1. Create the array of LL nodes
  std::vector<int> arr;
  ListNode* temp = head;
  while(temp) {
    arr.push_back(temp->data);
    temp = temp->next;
  }

  // * 2. Sort the array
  std::sort(arr.begin(), arr.end());

  // * 3. Update the existing LL with sorted values
  int i = 0;
  temp = head;
  while (temp) {
    temp->data = arr[i++];
    temp = temp->next;
  }

  return head;
}

ListNode* findMiddle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head->next;  // * This is small change from tortise and hare algo

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

ListNode* mergeSort(ListNode* head1, ListNode* head2) {
  ListNode *dummy = new ListNode(-1);
  ListNode *mover = dummy;
  
  while (head1 && head2) {
    if (head1->data < head2->data) {
      mover->next = head1;
      mover = head1;
      head1 = head1->next;
    } else {
      mover->next = head2;
      mover = head2;
      head2 = head2->next;
    }
  }

  while (head1) {
    mover->next = head1;
    mover = head1;
    head1 = head1->next;
  }

  while (head2) {
    mover->next = head2;
    mover = head2;
    head2 = head2->next;
  }

  // printLL(dummy);
  return dummy->next;
}

// * ------------------ Optimal Approach ---------------------
// * Merge Sort
// * TIME COMPLEXITY  O(NlogN)
// *  - O(logn) for recursion
// *  - O(n) for merging
// * SPACE COMPLEXITY O(N)
ListNode* sortList(ListNode* head) {
  if (!head || !head->next)
    return head;

  // * divide the ll in half
  ListNode *mid = findMiddle(head);
  ListNode *rightHead = mid->next;
  mid->next = nullptr;
  ListNode *leftHead = head;

  // std::cout << leftHead->data << " " << rightHead->data << std::endl;

  // * recursively divide in half
  leftHead = sortList(leftHead);
  rightHead = sortList(rightHead);

  // * merge 2 ll 
  return mergeSort(leftHead, rightHead);
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {4, 2, 1, 3};

  ListNode* head = arrayToLL(nums);
  std::cout << "Linked List Before Sorting" << std::endl;
  printLL(head);

  std::cout << "Linked List After Sorting" << std::endl;
  ListNode* ans = sortList(head);
  printLL(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-sort-ll.cpp -o output && ./output


