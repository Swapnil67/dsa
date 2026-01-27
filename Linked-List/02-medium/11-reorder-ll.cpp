/**
 * * Leetcode - 143
 * * Reorder List

 * * You are given the head of a singly linked-list. The list can be represented as:
 * * L0 -> L1 -> L2 -> L3 -> L4 ->  ... -> Ln-1 -> Ln

 * * Reorder the list to be on the following form:
 * * L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 ->  ... 

 * * You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 * * Example 1
 * * Input  : head = [1,2,3,4]
 * * Output : [1,4,2,3]

 * * Example 2
 * * Input  : head = [1,2,3,4,5]
 * * Output : [1,5,2,4,3]

 * * https://leetcode.com/problems/reorder-list/description/
*/

#include <stack>
#include <vector>
#include <iostream>

class ListNode {
  public:
    int data;
    ListNode* next;
    
    ListNode(int val) {
      this->data = val;
      this->next = nullptr;
    }
    
    ListNode(int val, ListNode* node) {
      this->data = val;
      this->next = node;
    }
};

void printLL(ListNode* head) {
  ListNode* temp = head;
  while(temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode* arrayToLL(std::vector<int> &arr) {
  if (!arr.size())
    return nullptr;

  ListNode* head = new ListNode(arr[0]);
  ListNode* mover = head;

  for (int i = 1; i < arr.size(); ++i) {
    ListNode* node = new ListNode(arr[i]);
    mover->next = node;
    mover = node;
  }

  return head;
}

ListNode* reverse_ll(ListNode* head) {
  ListNode *tail = nullptr;
  ListNode *temp = head;
  
  while (temp) {
    ListNode *front = temp->next;
    temp->next = tail;
    tail = temp;
    temp = front;
  }

  return tail;
}

// * ------------------ APPROACH 1: Optimal Approach ---------------------
// * By reversing from mid to end of ll
// * TIME COMPLEXITY O(N/2)
// * SPACE COMPLEXITY O(1)
void reorderList(ListNode* head) {
  if (!head || !head->next)
    return;

  // * Get to the mid of ll
  ListNode* slow = head; 
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // * now slow will point at the middle node
  ListNode* rev = reverse_ll(slow->next);
  // printLL(rev);

  slow->next = nullptr; // * make two ll here
  // printLL(head);
  
  ListNode* cur = head;
  while (rev) {
    // * point cur to the rev
    ListNode *cur_next = cur->next;
    cur->next = rev;
    
    // * point rev to the cur->next
    ListNode *rev_next = rev->next;
    rev->next = cur_next;

    cur = cur_next; // * move cur
    rev = rev_next; // * move rev
  }
}


// * ------------------ APPROACH 2: Optimal Approach ---------------------
// * Using stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
void reorderList2(ListNode* head) {
  if (!head || !head->next)
    return;

  // * Push all the nodes to stack
  std::stack<ListNode *> st;
  ListNode* curr = head;
  while (curr) {
    st.push(curr);
    curr = curr->next;
  }

  curr = head;
  size_t k = st.size() / 2;
  while (k--) {
    ListNode* top_node = st.top();
    st.pop();

    ListNode *front_node = curr->next;
    curr->next = top_node;
    top_node->next = front_node;
    curr = front_node;
  }
  curr->next = nullptr;
}

int main(void) {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4};

  // * testcase 2
  std::vector<int> arr = {1, 2, 3, 4, 5};

  ListNode *head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  reorderList(head);
  // reorderList2(head);
  
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-reorder-ll.cpp -o output && ./output

