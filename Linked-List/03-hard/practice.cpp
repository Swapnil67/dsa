
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

struct ListNode {
public:
  int data;
  ListNode *next;

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

ListNode *arrayToLL(std::vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return nullptr;

  ListNode* head = new ListNode(nums[0]);
  ListNode* mover = head;

  for (int i = 1; i < n; ++i) {
    ListNode* newNode = new ListNode(nums[i]);
    mover->next = newNode;
    mover = newNode;
  }

  return head;
}

// * 01 - Reverse List In K Groups
// ListNode *kReverse(ListNode *head, int k) {
// TODO
// }

// * 02 - LFU Cache
// class LFUCache {
// public:
//     LFUCache(int capacity) {
//     }
//     int get(int key) {
//     }
//     void put(int key, int value) {
//     }
// };

// * 03 - Merge k Sorted Lists
// ListNode *mergeKLists(std::vector<ListNode *> &lists) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output