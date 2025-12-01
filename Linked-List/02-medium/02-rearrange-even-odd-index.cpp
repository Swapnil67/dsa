/*
 * Leetcode - 328
 * Rearrange Odd and Even Places (Indexes)

 * You are given the 'head' of a singly linked list. Your task is to group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered list’s head.
 * The first node is considered odd, and the second node is even, and so on.

 * Example 1:
 * head :  1 -> 3 -> 5 -> 7
 * Output: 1 -> 5 -> 3 -> 7
 * 
 
 * Example 2:
 * head : 2 -> 4 -> 6 -> 8 -> 10
 * Output: 2 -> 6 -> 10 -> 4 -> 8
 * 
 * 
 * https://leetcode.com/problems/odd-even-linked-list/description/
*/

#include <vector>
#include <iostream>

class ListNode {
  public:
    int data;
    ListNode* next;

    ListNode(int d) {
      this->data = d;
      this->next = nullptr;
    }

    ListNode(int d, ListNode* n) {
      this->data = d;
      this->next = n;
    }

};

// * ------------------- Utility Functions ---------------------

// * Convert array to LL
ListNode* arrayToLL(std::vector<int> arr) {
  if(arr.size() == 0) return nullptr;
  ListNode* head = new ListNode(arr[0]);
  ListNode* temp = head;
  for(int i=1; i<arr.size(); i++) {
    ListNode* newNode = new ListNode(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}

// * Traverse the LL
void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

// * Re Arrange Even and Odd Indices

// * ------------------ Brute Force ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
ListNode* bruteForce(ListNode* head) {
  std::vector<int> arr;
  ListNode* temp = head;

  // * Insert Odd index in arr O(N/2)
  while (temp) {
    arr.push_back(temp->data);
    if(temp->next == nullptr) {
      break;
    }
    temp = temp->next->next;
  }

  // * Insert Even index in arr O(N/2)
  temp = head->next;
  while(temp) {
    arr.push_back(temp->data);
    if(temp->next == nullptr) {
      break;
    }
    temp = temp->next->next;
  }

  // * Traverse the LL and replace the data values with array data values O(N)
  int j = 0; temp = head;
  while(temp) {
    temp->data = arr[j++];
    temp = temp->next;
  }

  // * For debugging
  // for (int i = 0; i < arr.size(); i++) {
  //   std::cout << arr[i] << " ";
  // }
  // std::cout << std::endl;

  return head;
}

ListNode* betterApproach(ListNode* head) {
  ListNode *odd_list = new ListNode(-1);
  ListNode *odd_mover = odd_list;
  ListNode *even_list = new ListNode(-1);
  ListNode *even_mover = even_list;
  
  ListNode *temp = head;
  int i = 0;
  while (temp) {
    ListNode *new_node = new ListNode(temp->data);
    if (i % 2 == 0) {
      even_mover->next = new_node;
      even_mover = new_node;
    } else {
      odd_mover->next = new_node;
      odd_mover = new_node;
    }
    temp = temp->next;
    i++;
  }

  even_mover->next = odd_list->next;
  return even_list->next;
}


// * ------------------ Optimal Solution ---------------------
// * TIME COMPLEXITY O(N/2) * 2 = O(N)
// * SPACE COMPLEXITY O(1)
ListNode* oddEvenList(ListNode* head) {
  if (!head || !head->next)
    return head;
  
  ListNode* odd = head;
  ListNode* even = head->next;
  ListNode* even_head = head->next;

  while(even != NULL && even->next != NULL) {
    odd->next = odd->next->next;
    even->next = even->next->next;

    odd = odd->next;
    even = even->next;
  }  
  odd->next = even_head;
  return head;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};

  // * testcase 2
  // std::vector<int> arr = {2, 4, 6, 8, 10};

  // * Create a Linked List
  ListNode* head = arrayToLL(arr);
  std::cout<<"------------ Before Rearranging Linked List ------------"<<std::endl;
  printLL(head);

  // * Rearrange even and odd numbers
  std::cout<<"------------ After Rearranging Linked List ------------"<<std::endl;
  // head = bruteForce(head);
  // head = betterApproach(head);
  head = oddEvenList(head);
  printLL(head);
  return 0;
}

// * g++ -std=c++17 02-rearrange-even-odd-index.cpp -o output && ./output