/**
 * * Leetcode - 3217
 * * Delete Nodes From Linked List Present in Array
 * * You are given an array of integers nums and the head of a linked list. 
 * * Return the head of the modified linked list after removing all nodes from the linked list that
 * * have a value that exists in nums.

 * * Example 1
 * * Input  : nums = [1,2,3], head = [1,2,3,4,5]
 * * Output : [4,5]

 * * Example 2
 * * Input  : nums = [1], head = [1,2,1,2,1,2]
 * * Output : [2,2,2]

 * * Example 3
 * * Input  : nums = [1, 7, 6, 2, 4], head = [3, 7, 1, 8, 1]
 * * Output : [3, 8]

 * * https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

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

// * ------------------ Optimal Solution ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(size of nums)
ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
  if (!nums.size())
    return head;

  // * create a map of nums
  std::unordered_map<int, int> cache;
  for (auto &x : nums)
    cache[x]++;

  // * Handle head 
  while (head && cache[head->data]) {
    ListNode* temp = head;
    head = head->next;
    delete temp; // * remove hanging pointer
  }

  ListNode* cur = head;
  while(cur && cur->next) {
    if (cache[cur->next->data]) {
      ListNode* temp = cur->next;
      cur->next = cur->next->next;
      delete temp; // * remove hanging pointer
    } else {
      cur = cur->next;
    }
  }

  return head;
}


int main(void) {
  // std::vector<int> nums = {1, 2, 3};
  // std::vector<int> arr = {1, 2, 3, 4, 5};

  std::vector<int> nums = {1};
  std::vector<int> arr = {1, 2, 1, 2, 1, 2};

  // std::vector<int> nums = {1, 7, 6, 2, 4};
  // std::vector<int> arr = {3, 7, 1, 8, 1};

  printArr(nums);

  ListNode* head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  head = modifiedList(nums, head);
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-del-nodes-from-ll-present-in-arr.cpp -o output && ./output


