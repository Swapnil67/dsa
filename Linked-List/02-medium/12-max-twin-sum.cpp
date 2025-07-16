/**
 * * Leetcode - 2130
 * * Maximum Twin Sum of a Linked List
 * * In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is 
 * * known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
 * 
 * * Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 * * Example 1
 * * Input  : head = [5,4,2,1]
 * * Output : 6

 * * Example 2
 * * Input  : head = [4,2,2,3]
 * * Output : 7

 * * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
*/

#include <stack>
#include <vector>
#include <iostream>

typedef struct ListNode ListNode;

class ListNode {
  public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int val) {
      data = val;
      next = nullptr;
    }

    ListNode(int val, ListNode *node) {
      data = val;
      next = node;
    }

    ListNode(int val, ListNode *nextNode, ListNode* prevNode) {
      data = val;
      next = nextNode;
      prev = prevNode;
    }
};

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode *arrayToLL(std::vector<int> &arr)
{
  if (!arr.size())
    return nullptr;

  // * create the head node
  ListNode *head = new ListNode(arr[0]);
  
  // * create the tail node
  ListNode *tail = head;
  
  int n = arr.size();
  for(int i = 1; i < n; ++i) {
    ListNode *node = new ListNode(arr[i]);
    tail->next = node;
    tail = node;
  }
  return head;
}

ListNode* reverseLL(ListNode* head) {
  ListNode* tail = nullptr;  
  ListNode* cur = head;
  while (cur) {
    ListNode* front = cur->next;
    cur->next = tail;
    tail = cur;
    cur = front;
  }
  return tail;
}

// * Using Vector
int bruteForce(ListNode *head) {
  ListNode* temp = head;
  std::vector<int> vec;
  while (temp) {
    vec.push_back(temp->data);
    temp = temp->next;
  } 
  // printArr(vec);

  int i = 0, j = vec.size() - 1;
  int curSum = 0, maxSum = 0;
  while (i < j) {
    curSum = vec[i] + vec[j];
    maxSum = std::max(maxSum, curSum);
    i++, j--;
  }
  return maxSum;
}

// * Using Stack
int pairSumStack(ListNode *head) {
  ListNode* temp = head;
  std::stack<int> st;
  while (temp) {
    st.push(temp->data);
    temp = temp->next;
  } 
  
  int count = 0,  N = st.size();
  temp = head;
  int maxSum = 0;
  while (count <= N / 2) {
    maxSum = std::max(maxSum, temp->data + st.top());
    st.pop();
    count++;
    temp = temp->next;
  }

  return maxSum;
}

// * By reversing LL from the mid
int pairSum(ListNode *head) {
  // * Go to the mid of LL
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode* temp = head;
  ListNode* mid = reverseLL(slow);

  int curSum = 0, maxSum = 0;
  while (mid && temp != mid) {
    // std::cout << temp->data + mid->data << std::endl;
    maxSum = std::max(maxSum, temp->data + mid->data);
    temp = temp->next;
    mid = mid->next;
  }
  return maxSum;
}

int main(void) {
  // std::vector<int> nums = {5, 4, 2, 1};
  // std::vector<int> nums = {4, 2, 2, 3};
  std::vector<int> nums = {47, 22, 81, 46, 94, 95, 90, 22, 55, 91, 6, 83, 49, 65, 10, 32, 41, 26, 83, 99, 14, 85, 42, 99, 89, 69, 30, 92, 32, 74, 9, 81, 5, 9};
  ListNode* head = arrayToLL(nums);
  printLL(head);

  // int ans = bruteForce(head);
  // int ans = pairSumStack(head);
  int ans = pairSum(head);
  std::cout << "Maximum Twin Sum of a Linked List " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-max-twin-sum.cpp -o output && ./output

