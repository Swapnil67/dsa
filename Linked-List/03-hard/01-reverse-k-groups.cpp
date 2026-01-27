/**
 * * Leetcode - 25
 * * Reverse List In K Groups
 * * You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
 * * Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k',
 * * then the last group of nodes should remain unchanged.


 * * the previous and the next nodes in the sequence of nodes.
 *
 * * Example 1
 * * Input  : 1->2->3->4->5-> NULL, k = 3
 * * Output : 3->2->1->4->5->NULL
 * 
 * * Example 2
 * * Input  : 1->2->3->4-> NULL, k = 2
 * * Output : 2->1->4->3->NULL
 
 * * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 * * https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644
*/

// ! Microsoft

#include <vector>
#include <iostream>

class ListNode {
  public: 
    int data;
    ListNode* next;
    ListNode* prev;

    ListNode() {
      this->data = 0;
      this->next = NULL;
    }
    ListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
    ListNode (int data, ListNode *next) {
        this->data = data;
        this->next = next;
    }
};

// * ------------------- Utility Functions ---------------------

ListNode* arrayToLL(std::vector<int> arr) {
  if(!arr.size())
    return nullptr;

  ListNode *head = new ListNode(arr[0]);
  ListNode *temp = head;

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


ListNode* getKthNode(ListNode* head, int k) {
  k -= 1;
  ListNode* temp = head;
  while(temp != nullptr && k > 0) {
    temp = temp->next;
    k--;
  }
  return temp;
}

ListNode *reverse_ll(ListNode *head) {
  if (!head || !head->next)
    return head;

  ListNode *temp = head;
  ListNode *tail = nullptr;
  while (temp) {
    ListNode *front = temp->next;
    temp->next = tail;
    tail = temp;
    temp = front;
  }

  return tail;
}

// * ------------------ Optimal Approach ---------------------
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
ListNode* kReverse(ListNode* head, int k) {
  // * Initialize a pointer to track the
  // * last node of the previous group
  ListNode *dummy = new ListNode(-1);
  ListNode *prev_head = dummy;

  ListNode *temp = head;

  while (temp) {
    ListNode *cur = temp;

    // * go to (k - 1)th node
    for (int i = 0; i < k - 1; ++i) {
      if (cur)
        cur = cur->next;
    }

    if (cur) {
      // * save the head of next k-group
      ListNode *next_head = cur->next;

      // * Reverse the current group
      cur->next = nullptr;
      ListNode *rev_cur = reverse_ll(temp);
      printLL(rev_cur);
      std::cout << prev_head->data << std::endl;

      // * Point the prev_head -> next_k_group
      prev_head->next = rev_cur;
      prev_head = temp;

      // * start with next k-group
      temp = next_head;
    } else {
      // * here we have nodes less than k-groups so we append all remaining nodes
      prev_head->next = temp;
      break;
    }
  }

  return dummy->next;
}

int main() {  
  // * testcase 1
  int k = 2;
  std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ListNode* head = arrayToLL(arr);
  std::cout<<"Before Reversing"<<std::endl;
  printLL(head);

  std::cout<<"After Reversing"<<std::endl;
  head = kReverse(head, k);
  printLL(head);

  return 0;
}


// * Run the code
// * g++ --std=c++17 01-reverse-k-groups.cpp -o output && ./output