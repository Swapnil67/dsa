/*
 * Leetcode - 445
 * Add Two Numbers II
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The most significant digit comes first and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 *
 * Example 1
 * Input:  l1 = [7, 2, 4, 3], l2 = [5, 6, 4]
 * Output: [7, 8, 0, 7]
 *
 * Example 2
 * Input:  l1 = [2, 4, 3], l2 = [5, 6, 4]
 * Output: [8, 0, 7]
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
*/

#include <stack>
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

ListNode* reversell(ListNode* head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode* temp = head;
  ListNode* tail = nullptr;

  while (temp) {
    ListNode *front = temp->next;
    temp->next = tail;
    tail = temp;
    temp = front;
  }

  return tail;
}

ListNode* bruteForce(ListNode* h1, ListNode* h2) {
  ListNode* l1 = reversell(h1);
  ListNode* l2 = reversell(h2);
  // printLL(l1);
  // printLL(l2);
  
  ListNode* ans = nullptr;
  int carry = 0;
  while (l1 || l2) {
    int sum = carry;
    if (l1)
      sum += l1->data;
    if (l2)
      sum += l2->data;

    ListNode *cur = new ListNode(sum % 10);
    carry = sum / 10;
    
    // * Add ll in reverse order here
    cur->next = ans;
    ans = cur;

    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
  }

  return ans;
}


ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
  // * Push the h1 elements to stack (st1)
  std::stack<int> st1;
  ListNode *temp1 = h1;
  while (temp1) {
    st1.push(temp1->data);
    temp1 = temp1->next;
  }
  
  // * Push the h2 elements to stack (st2)
  std::stack<int> st2;
  temp1 = h2;
  while (temp1) {
    st2.push(temp1->data);
    temp1 = temp1->next;
  }

  int sum = 0, carry = 0;
  ListNode* ans = new ListNode(-1);
  while (!st1.empty() || !st2.empty()) {
    sum = carry;

    if (!st1.empty()) {
      sum += st1.top();
      st1.pop();
    }

    if (!st2.empty()) {
      sum += st2.top();
      st2.pop();
    }

    ans->data = (sum % 10);
    carry = sum / 10;

    ListNode *newNode = new ListNode(carry);
    newNode->next = ans;
    ans = newNode;
  }

  return (carry == 0) ? ans->next : ans;
}


int main() {
  // * testcase 1
  // std::vector<int> nums1 = {7, 2, 4, 3};
  // std::vector<int> nums2 = {5, 6, 4};

  // * testcase 2
  // std::vector<int> nums1 = {2, 4, 3};
  // std::vector<int> nums2 = {5, 6, 4};

  // * testcase 3
  std::vector<int> nums1 = {9, 9};
  std::vector<int> nums2 = {9};

  ListNode* n1_head = arrayToLL(nums1);
  ListNode* n2_head = arrayToLL(nums2);

  std::cout << "First Linked List" << std::endl;
  printLL(n1_head);
  std::cout << "Second Linked List" << std::endl;
  printLL(n2_head);

  // ListNode* addHead = bruteForce(n1_head, n2_head);
  ListNode* addHead = addTwoNumbers(n1_head, n2_head);
  std::cout << "-----------------------------------------" << std::endl;
  printLL(addHead);

  return 0;
}

// * Note whenever there is a need for new LL, always create a dummyNode node and return dummyNode->next

// * Run the code
// * g++ --std=c++20 19-add-two-ll-ii.cpp -o output && ./output

