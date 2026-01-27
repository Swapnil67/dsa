/*
* Leetcode - 700
* Ceil in a Binary Search Tree
* Ceil of an integer is the closest integer greater than or equal to a given number.

*
*                  6
*               /     \  
*             2        13
*           /  \     /   \  
*          1    4   9     15
*                        /
*                       14

* Example 1:
* Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], val = 8
* Output: 9

* Example 2:
* Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], val = 16
* Output: -1

* https://www.naukri.com/code360/problems/ceil-from-bst_920464
* https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
*/

// ! Patym, Flipkart, Samsung

#include <vector>
#include <iostream>

typedef struct TreeNode TreeNode;

struct TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
  }

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

void inorder(TreeNode *root, std::vector<int> &arr) {
  if (!root) return;
  inorder(root->left, arr);
  arr.push_back(root->data);
  inorder(root->right, arr);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Create a sorted array from BST using inorder traversal
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
bool bruteForce(TreeNode *root, int k) {
  std::vector<int> nums;
  inorder(root, nums); // * O(N)

  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int cur_sum = nums[l] + nums[r];
    if (cur_sum == k)
      return true;

    if (cur_sum > k) {
      r--;
    } else {
      l++;
    }
  }
  return false;
}


bool findTarget(TreeNode *root, int k) {
  return true;
}

int main(void) {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(13);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(15);
  
  root->right->right->left = new TreeNode(14);

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-ceil-in-bst.cpp -o output && ./output
