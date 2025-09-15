/*
 * Leetcode - 86
 * Partition List
 * 
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come
 * before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.

 * * Example 1
 * * Input  : head = [1,4,3,2,5,2], x = 3
 * * Output : [1,2,2,4,3,5]

 * * Example 2
 * * Input  : head = [2,1], x = 2
 * * Output : [1,2]

 * https://leetcode.com/problems/partition-list/
*/

#include <vector>
#include <iostream>

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

ListNode* partition(ListNode* head, int x) {
  if (!head || !head->next)
    return head;

  // * Create a ll for nodes smaller than x
  ListNode *small = new ListNode(-1);
  ListNode *small_mover = small;

  // * Create a ll for nodes greater or equal than x
  ListNode *big = new ListNode(-1);
  ListNode *big_mover = big;

  ListNode *temp = head;
  while (temp) {
    if (temp->data < x) {
      small_mover->next = temp;
      small_mover = temp;
    } else {
      big_mover->next = temp;
      big_mover = temp;
    }
    temp = temp->next;
  }

  small_mover->next = big->next;
  big_mover->next = nullptr;
  
  return small->next;
}

int main(void) {
  // * testcase 1
  // int x = 3;
  // std::vector<int> nums = {1, 4, 3, 2, 5, 2};
  
  // * testcase 2
  int x = 2;
  std::vector<int> nums = {2, 1};

  ListNode *head = arrayToLL(nums);
  std::cout << "Linked List Before Partition" << std::endl;
  printLL(head);

  std::cout << "Linked List After Partition" << std::endl;
  ListNode *ans = partition(head, x);
  printLL(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 23-partition-list.cpp -o output && ./output

