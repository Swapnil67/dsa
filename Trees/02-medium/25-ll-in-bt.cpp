/*
* Leetcode - 1367
* Linked List in Binary Tree

* Given a binary tree root and a linked list with head as the first node. 

* Return True if all the elements in the linked list starting from the head correspond to some downward
* path connected in the binary tree otherwise return False.

* In this context downward path means a path that starts at some node and goes downwards.

* Example 1:
* Input: 
*                   1        
*               /      \     
*              4       4
*              \      /    
*               2    2    
*             /     / \  
*            1     6   8
*                     / \  
*                    1   3  

* Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
* Output: true

* https://leetcode.com/problems/linked-list-in-binary-tree/description/
*/

#include <vector>
#include <iostream>

typedef struct TreeNode TreeNode;

struct ListNode {
public:
  int data;
  ListNode* next;

  ListNode(int val) {
    data = val;
    next = nullptr;
  }
};

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
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

bool check(ListNode* head, TreeNode* root) {
  if (!head) // * traversed whole ll
    return true;

  if (!root) // * traversed whole bt
    return false;

  if (root->data != head->data) {
    return false;
  }

  return check(head->next, root->left) || check(head->next, root->right);
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * Recursion Leap of faith
// * 'n' = bt nodes & 'm' = ll nodes
// * TIME COMPLEXITY O(n * m)
// * SPACE COMPLEXITY O(n + m)
bool isSubPath(ListNode* head, TreeNode* root) {
  if (!root)
    return false;

  return check(head, root) ||
         isSubPath(head, root->left) ||
         isSubPath(head, root->right);
}

int main(void) {
  // * testcase 1
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(4);
  root->right = new TreeNode(4);
  
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(1);
  
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(6);
  root->right->left->right = new TreeNode(8);
  
  root->right->left->right->left = new TreeNode(1);
  root->right->left->right->right = new TreeNode(3);

  std::vector<int> arr = {4, 2, 8};
  ListNode *head = arrayToLL(arr);
  printLL(head);

  bool ans = isSubPath(head, root);
  std::cout << "Linked List in Binary Tree: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 25-ll-in-bt.cpp -o output && ./output

