/*
 * Leetcode - ?
 * Insert into a Sorted Circular Linked List
 * 
 * Solve this on neetcode
 * 
 * https://neetcode.io/problems/insert-into-a-sorted-circular-linked-list/
*/

// ! Amazon, Google, Meta

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
      val = _val;
      next = NULL;
    }

    Node(int _val, Node *_next) {
      val = _val;
      next = _next;
    }
};


// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* node_insert(Node* head, int insertVal) {
  if (!head) {
    Node* new_head = new Node(insertVal);
    new_head->next = new_head; // * make it circular
    return new_head;
  }

  Node* prev = head;
  Node* cur = head->next;
  while (true) { // * test_happy_path
    if (insertVal >= prev->val && insertVal <= cur->val) {
      break;
    }
    else if ( // * test_out_of_range
      (prev->val > cur->val) &&
      (insertVal >= prev->val || insertVal <= cur->val)) 
    {
      break;
    }
    prev = cur;
    cur = cur->next;

    if (prev == head)
      break;
  }

  prev->next = new Node(insertVal, cur);
  return head;
}

void test_happy_path(Node* head) {
  assert(5 == head->val);
  assert(10 == head->next->val);
  assert(10 == head->next->next->val);
  assert(15 == head->next->next->next->val);
  assert(19 == head->next->next->next->next->val);
  assert(20 == head->next->next->next->next->next->val);
  assert(5 == head->next->next->next->next->next->next->val);
}

void test_out_of_range(Node* head) {
  assert(1900 == head->val);
  assert(1950 == head->next->val);
  assert(420 == head->next->next->val);
  assert(666 == head->next->next->next->val);
}

void test_null_head() {
  Node* head = node_insert(nullptr, 9000);
  assert(9000 == head->val);
}

void test_duplicates(Node* head) {
  assert(7 == head->val);
  assert(1 == head->next->val);
  assert(7 == head->next->next->val);
  assert(7 == head->next->next->next->val);
  assert(7 == head->next->next->next->next->val);
}

int main(void) {
  // * testcase 1
  // * [5, 10, 10, 15, 20]
  Node *head = new Node(5);
  head->next = new Node(10, new Node(10, new Node(15, new Node(20, head))));
  node_insert(head, 19);
  test_happy_path(head);

  // * testcase 2
  // *   |----------|
  // *   V          |(h)
  // * [1900, 420, 666]
  head = new Node(1900);
  head->next = new Node(420, new Node(666, head));
  node_insert(head, 1950);
  test_out_of_range(head);
  
  // * testcase 3
  // * []
  test_null_head();
  
  // * testcase 4
  // *  |-----|
  // *  V     |(h)
  // * [7, 7, 7]
  head = new Node(7);
  head->next = new Node(7, new Node(7, head));
  node_insert(head, 1);
  test_duplicates(head);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 31-insert-into-a-sorted-circular-ll.cpp -o output && ./output
