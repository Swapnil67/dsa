/*
 * Leetcode - 725
 * Split Linked List in Parts
 * 
 * Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
 *
 * The length of each part should be as equal as possible: no two parts should have a size differing by more
 * than one. This may lead to some parts being null.
 *
 * The parts should be in the order of occurrence in the input list, and parts occurring earlier should always
 * have a size greater than or equal to parts occurring later.
 * 
 * Return an array of the k parts.

 * Example 1
 * Input  : head = [1,2,3], k = 5
 * Output : [[1],[2],[3],[],[]]

 * Example 2
 * Input  : head = [1,2,3,4,5,6,7,8,9,10], k = 3
 * Output : [[1,2,3,4],[5,6,7],[8,9,10]]

 * https://leetcode.com/problems/split-linked-list-in-parts/description/
*/

#include <vector>
#include <iostream>

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

int lengthOfll(ListNode* head) {
  ListNode* temp = head;
  int c = 0;
  while (temp) {
    c++;
    temp = temp->next;
  }
  return c;
}


// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY  O(K + N)
// * SPACE COMPLEXITY O(1)
std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
  std::vector<ListNode*> ans(k, nullptr); 
  if (!head || k == 0)
    return ans;
    
  // * 1. Find the length of ll
  int total = lengthOfll(head);

  int nodes_per_bucket = total / k;
  int extra_nodes = total % k;
  int cur_nodes = 0;

  ListNode* prev = nullptr;
  ListNode* cur = head;
  

  for (int i = 0; i < k; ++i) {
    ans[i] = cur;

    // * Fill the remaining nodes
    int remaining_nodes = nodes_per_bucket + ((extra_nodes > 0) ? 1 : 0);
    std::cout << remaining_nodes << std::endl;
    for (int j = 0; j < remaining_nodes; ++j) {
      prev = cur;
      cur = cur->next;
    }

    prev->next = nullptr;
    extra_nodes--;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 5;
  // std::vector<int> nums = {1, 2, 3};

  // * testcase 2
  int k = 3;
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ListNode* head = arrayToLL(nums);
  std::cout << "Linked List Before Sorting" << std::endl;
  printLL(head);

  std::vector<ListNode *> ans = splitListToParts(head, k);
  for (auto &ll : ans)
    printLL(ll);
  return 0;
}

// * Run the code
// * g++ --std=c++20 27-split-ll-in-parts.cpp -o output && ./output


