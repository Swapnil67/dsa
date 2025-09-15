/*
 * Leetcode - 1721
 * Swapping Nodes in a Linked List
 * 
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node from the beginning 
 * and the kth node from the end (the list is 1-indexed).

 * * Example 1
 * * Input  : head = [1,2,3,4,5], k = 2
 * * Output : [1,4,3,2,5]

 * * Example 2
 * * Input  : head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * * Output : [7,9,6,6,8,7,3,0,9,5]

 * https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
*/

#include <stack>
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

int lengthOfLL(ListNode* head) {
  ListNode* temp = head;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  }

  return c;
}

ListNode* bruteForce(ListNode* head, int k) {
  ListNode* first = nullptr;
  int firstVal = -1;
  ListNode* second = nullptr;
  int secondVal = -1;

  // * Get the kth node from begining
  int t = k - 1;
  std::stack<ListNode*> st;
  ListNode* temp = head;
  while (temp) {
    if (t == 0) {
      first = temp;
      firstVal = first->data;
    }
    st.push(temp);
    temp = temp->next;
    t--;
  }

  t = k - 1;
  while (!st.empty()) {
    if (t == 0) {
      second = st.top();
      secondVal = second->data;
    }
    t--;
    st.pop();
  }

  // std::cout << "First: " << first->data << std::endl;
  // std::cout << "Second: " << second->data << std::endl;

  temp = head;
  while (temp) {
    if (temp == first) {
      temp->data = secondVal;
    } else if(temp == second) {
      temp->data = firstVal;
    }
    temp = temp->next;
  }

  return head;
}

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

ListNode* swapNodes(ListNode* head, int k) {
  ListNode *node1 = nullptr;
  ListNode *node2 = nullptr;

  // * 1. Get the length of ll
  int length = lengthOfLL(head);
  if (k > length)
    return head;

  // * 2. Get the kth node from begining & end
  int first_idx = k - 1, last_idx = (length - k - 1) + 1;
  std::stack<ListNode *> st;
  ListNode* temp = head;
  while (temp) {
    if (first_idx == 0) {
      node1 = temp;
    } 
    if (last_idx == 0) {
      node2 = temp;
    }
    temp = temp->next;
    last_idx--;
    first_idx--;
  }

  // * 3. Swap the two numbers
  swap(node1->data, node2->data);

  return head;
}

int main(void) {
  // int k = 2;
  // std::vector<int> nums = {1, 2, 3, 4, 5};

  int k = 5;
  std::vector<int> nums = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
  ListNode* head = arrayToLL(nums);
  std::cout << "Linked List Before Swap" << std::endl;
  printLL(head);
  
  // head = bruteForce(head, k);
  head = swapNodes(head, k);
  std::cout << "Linked List After Swap" << std::endl;
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-swappning-nodes-in-ll.cpp -o output && ./output


