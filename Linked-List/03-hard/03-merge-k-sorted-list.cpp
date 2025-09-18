/*
 * Leetcode - 23
 * Merge k Sorted Lists
 * 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.

 * Example 1
 * Input  : lists = [[1,4,5],[1,3,4],[2,6]]
 * Output : 1->1->2->3->4->4->5->6

 * Example 2
 * Input  : lists = []
 * Output : []

 * https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

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

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY  O(n * k) + O(mlogm) 
// * SPACE COMPLEXITY O(n * k)
ListNode *bruteForce(std::vector<ListNode *> &lists) {
  if (lists.size() == 0)
    return nullptr;

  // * O(n*k)
  // * 1. Convert the list of list to array
  std::vector<int> temp;
  for (ListNode* &head: lists) {
    while (head) {
      temp.push_back(head->data);
      head = head->next;
    }
  }

  // * let n * k = m
  // * O(mlogm)
  // * 2. Sort the generated array
  std::sort(temp.begin(), temp.end());

  // * 3. convert the sorted array again to linked list & return
  return arrayToLL(temp);
}

ListNode* merge(ListNode *head1, ListNode *head2) {
  ListNode* temp1 = head1;
  ListNode* temp2 = head2;

  ListNode *dummy = new ListNode(-1);
  ListNode *mover = dummy;

  while (temp1 && temp2) {
    if (temp1->data < temp2->data) {
      mover->next = temp1;
      mover = temp1;
      temp1 = temp1->next;
    } else {
      mover->next = temp2;
      mover = temp2;
      temp2 = temp2->next;
    }
  }

  while (temp1) {
    mover->next = temp1;
    mover = temp1;
    temp1 = temp1->next;
  }

  while (temp2) {
    mover->next = temp2;
    mover = temp2;
    temp2 = temp2->next;
  }

  return dummy->next;
}

// * ------------------ Better Approach ---------------------
// * Using merge sort
// * TIME COMPLEXITY  O(K * n^2) ~ O(n^3)
// * SPACE COMPLEXITY O(1)
ListNode *betterApproach(std::vector<ListNode *> &lists) {
  int n = lists.size();
  if (n == 0)
    return nullptr;

  // * take first list from array
  ListNode* head = lists[0];

  // * start the loop from 2nd index
  for (int i = 1; i < n; ++i) {
    ListNode *head2 = lists[i];
    head = merge(head, head2);
  }

  return head;
}

// * ------------------ Optimal Approach ---------------------
// * Using min-heap
// * TIME COMPLEXITY  O(klogk) + O(n * k * logk)
// * SPACE COMPLEXITY O(k)
ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  int n = lists.size();
  if (n == 0)
    return nullptr;

  typedef std::pair<int, ListNode *> P;
  std::priority_queue<P, std::vector<P>, std::greater<P>> min_heap;
  
  // * O(klogk)
  // * Fill all the heads of list in min_heap
  for (ListNode *&head : lists) {
    if (head)
      min_heap.push({head->data, head});
  }

  ListNode *dummy = new ListNode(-1);
  ListNode *mover = dummy;

  // * O(n * k * logk)
  while (!min_heap.empty()) {
    std::pair<int, ListNode *> p = min_heap.top();
    min_heap.pop();
    
    mover->next = p.second;
    mover = mover->next;

    if (p.second->next) {
      min_heap.push({p.second->next->data, p.second->next});
    }
  }

  return dummy->next;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> matrix = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

  std::vector<ListNode *> lists;
  for (auto &vec : matrix) {
    ListNode *head = arrayToLL(vec);
    lists.push_back(head);
  }

  std::cout << "Input Lists: " << std::endl;
  for (auto &ll : lists)
  printLL(ll);
  
  std::cout << "Output Lists: " << std::endl;
  // ListNode *ans = bruteForce(lists);
  // ListNode *ans = betterApproach(lists);
  ListNode *ans = mergeKLists(lists);
  printLL(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-merge-k-sorted-list.cpp -o output && ./output


