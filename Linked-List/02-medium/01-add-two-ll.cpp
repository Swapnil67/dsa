/*
 * Leetcode - 2
 * Add Two Numbers
 * 
 * You are given two non-negative numbers 'num1' and 'num2' represented in the form of linked lists.
 *
 * Example 1
 * 'num1' : 1 -> 2 -> 3 -> NULL
 * 'num2' : 4 -> 5 -> 6 -> NULL
 * Output: 5 -> 7 -> 9 -> NULL
 *
 * Example 2
 * 'num1' : 0 -> 1 -> NULL
 * 'num2' : 0 -> NULL
 * Output: 0 -> 1 -> NULL
 *
 * https://leetcode.com/problems/add-two-numbers/
 * https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

// ! Amazon, Google, Meta, Microsoft, Adobe, Uber, ByteDance

#include <vector>
#include <iostream>

class ListNode {
  public:
  int data;
  ListNode* next;

  ListNode(int d) {
    this->data = d;
    this->next = NULL;
  }

  ListNode(int d, ListNode* n) {
    this->data = d;
    this->next = n;
  }
};

// * ------------------- Utility Functions ---------------------

ListNode* arrayToLL(std::vector<int> arr) {
  if(arr.size() == 0) {
    return NULL;
  }

  ListNode* head = new ListNode(arr[0]);
  ListNode* temp = head;
  for (int i = 1; i < arr.size(); i++) {
    ListNode *newNode = new ListNode(arr[i]);
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

// * ------------------ APPROACH 2: Brute Force ---------------------
// * TIME COMPLEXITY O(max(h1, h1))
// * SPACE COMPLEXITY O(max(h1, h1))
ListNode* bruteForce(ListNode* head) {
  if (!head)
    return head;

  // * Step 1. Create a vector from given LL
  ListNode* temp = head;
  std::vector<int> arr;
  while (temp) {
    arr.push_back(temp->data);
    temp = temp->next;
  }

  // * Step 2. Separate even & odd indices nodes from arr
  std::vector<int> even_arr, odd_arr;
  for (int i = 1; i <= arr.size(); ++i) {
    if (i % 2 == 0)
      even_arr.push_back(arr[i - 1]);
    else
      odd_arr.push_back(arr[i - 1]);
  }
  for (auto &x : even_arr) {
    odd_arr.push_back(x);
  }

  // * Step 3. Make a LL from array
  ListNode* ans = new ListNode(-1);
  ListNode* mover = ans;
  for (int i = 0; i < odd_arr.size(); ++i) {
    ListNode *node = new ListNode(odd_arr[i]);
    mover->next = node;
    mover = node;
  }
  return ans->next;
}

// * ------------------ APPROACH 1: Optimal ---------------------
// * TIME COMPLEXITY O(max(h1, h1))
// * SPACE COMPLEXITY O(max(h1, h1))
ListNode* addTwoLL(ListNode* h1, ListNode* h2) {
  ListNode* sumHead = new ListNode(0);
  ListNode* temp = sumHead;
  int carry = 0;
  while (h1 != NULL || h2 != NULL) {
    int sum = carry;

    if (h1) {
      sum = sum + h1->data;
      h1 = h1->next;
    }

    if (h2) {
      sum = sum + h2->data;
      h2 = h2->next;
    }

    ListNode *node = new ListNode(sum % 10);
    carry = sum / 10;
    temp->next = node;
    temp = node;
  }

  // * check if carry set
  if(carry > 0) {
    ListNode* carryNode = new ListNode(carry);
    temp->next = carryNode;
  }

  return sumHead->next;
}

int main() {
  // * testcase 1
  // std::vector<int> nums1 = { 1, 2, 3 };
  // std::vector<int> nums2 = { 4, 5, 9 };

  // * testcase 2
  // std::vector<int> nums1 = { 0, 1 };
  // std::vector<int> nums2 = { 0 };

  // * testcase 2
  std::vector<int> nums1 = {9, 9, 9, 9, 9, 9, 9};
  std::vector<int> nums2 = {9, 9, 9, 9};

  ListNode* n1_head = arrayToLL(nums1);
  ListNode* n2_head = arrayToLL(nums2);

  std::cout<<"First Linked List"<<std::endl;
  printLL(n1_head);
  std::cout<<"Second Linked List"<<std::endl;
  printLL(n2_head);

  ListNode* addHead = addTwoLL(n1_head, n2_head);
  std::cout<<"-----------------------------------------"<<std::endl;
  // std::cout<<"Sum of two Linked List"<<std::endl;
  printLL(addHead);

  return 0;
}

// * Note whenever there is a need for new LL, always create a dummyNode node and return dummyNode->next

// * Run the code
// * g++ --std=c++20 01-add-two-ll.cpp -o output && ./output

