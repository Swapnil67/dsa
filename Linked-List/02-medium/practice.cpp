
#include <stack>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

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

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

ListNode* arrayToLL(std::vector<int> &arr) {
  int n = arr.size();

  ListNode *head = new ListNode(arr[0]);
  ListNode* mover = head;
  for (int i = 1; i < n; ++i) {
    ListNode *newNode = new ListNode(arr[i], nullptr);
    mover->next = newNode;
    mover = newNode;
  }
  return head;
}

int lengthOfLL(ListNode *node) {
  ListNode* temp = node;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  }
  return c;
}

template <typename T>
void printLL(T* head) {
  T *temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

template <typename T>
class DLListNode {
public:
  T data;
  DLListNode* next;
  DLListNode* prev;

  DLListNode(T d) {
    this->data = d;
    this->next = NULL;
    this->prev = NULL;
  }

  DLListNode(T d, DLListNode *n, DLListNode *p) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }
};

template <typename T>
DLListNode<T> *arrayToDLL(std::vector<T> &arr) {
  int n = arr.size();
  if (!n)
    return nullptr;

  DLListNode<T>* head = new DLListNode<T>(arr[0]);
  DLListNode<T>* mover = head;

  for (int i = 1; i < n; ++i) {
    DLListNode<T> *new_node = new DLListNode<T>(arr[i], nullptr, mover);
    mover->next = new_node;
    mover = new_node;
  }

  return head;
}

template <typename T>
void printDLL(DLListNode<T> *head) {
  DLListNode<T> *temp = head;
  while (temp)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
// * --------------------------------------------------------------------------------

// * 01 - Add Two Numbers
// ListNode *addTwoLL(ListNode *head1, ListNode *head2) {
// TODO
// }

// * 02 - Rearrange Odd and Even Places (Indexes)
// ListNode* reArrangeEvenOddOptimal(ListNode* head) {
// TODO
// }

// * 03 - Remove Nth Node From End of List
// ListNode* removeNthFromEnd(ListNode* head, int n) {
// TODO
// }

// * 04 - Cycle Detection in a Singly Linked List
// ListNode* detectCycle(ListNode* head) {
// TODO
// }

// * 05 - Delete the Middle ListNode of a Linked List
// ListNode* deleteMiddle(ListNode* head) {
// TODO
// }

// * 06 - Delete all occurrences of a given key in a doubly linked list
// DLListNode<int> *deleteOccurences(DLListNode<int> *head, int k) {
// TODO
// }

// * 07 - Merge In Between Linked Lists
// ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
// TODO 
// }

// * 08 - Merge Nodes in Between Zeros
// ListNode *mergeNodes(ListNode *head) {
// TODO
// }

// * 09 - Find the Minimum and Maximum Number of Nodes Between Critical Points
// std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
// TODO
// }

// * 10 - Double a Number Represented as a Linked List
// ListNode* doubleIt(ListNode* head) {
// TODO
// }

// * 11 - Reorder List
// void reorderList(ListNode* head) {
// TODO
// }

// * 12 - Maximum Twin Sum of a Linked List
// int pairSum(ListNode *head) {
// TODO
// }

// * 13 - Remove Nodes From Linked List
// ListNode *removeNodes(ListNode *head) {
// TODO
// }

// * 14 - Linked List Components
// int numComponents(ListNode *head, std::vector<int> &nums) {
// TODO
// }

// * 15 - Delete Nodes From Linked List Present in Array
// ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
// TODO
// }

// * 16 - Swapping Nodes in a Linked List
// ListNode *swapNodes(ListNode *head, int k) {
// TODO
// }

// * 17 - Reverse Linked List II
// ListNode *reverseBetween(ListNode *head, int left, int right) {
// TODO
// }

// * 18 - Design Browser History
// TODO (Do this on leetcode)

// * 19 - Add Two Numbers II
// ListNode *addTwoNumbers(ListNode *nums1, ListNode *nums2) {
// TODO
// }

// * 20 - LRU Cache
// TODO (Do this on leetcode)

// * 21 - Swap Nodes in Pairs
// ListNode *swapPairs(ListNode *head) {
// TODO
// }

// * 22 - Sort List
// ListNode *sortList(ListNode *head) {
// TODO 
// }

// * 23 - Partition List
// ListNode *partition(ListNode *head, int x) {
// TODO
// }

// * 24 - Rotate List
// ListNode *rotateRight(ListNode *head, int k) {
// TODO
// }

// * 25 - Design Circular Queue
// TODO (Do this on leetcode)

// * 26 - Insertion Sort List
// ListNode* insertionSortList(ListNode* head) {
// TODO
// }

// * 27 - Split Linked List in Parts
// std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
// TODO
// }

// * 28 - Add 1 to a Linked List Number
// ListNode* addOne(ListNode* head) {
// TODO
// }

// * 29 - Design Circular Deque
// TODO (Do this on leetcode)

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

