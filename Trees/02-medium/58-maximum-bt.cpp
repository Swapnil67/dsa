/*
 * Leetcode - 654
 * Maximum Binary Tree 
 * 
 * You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively 
 * from nums using the following algorithm:
 * 
 * - Create a root node whose value is the maximum value in nums.
 * - Recursively build the left subtree on the subarray prefix to the left of the maximum value.
 * - Recursively build the right subtree on the subarray suffix to the right of the maximum value.
 * 
 * Example 1    :
 * Input        : nums = [3,2,1,6,0,5]
 * Output       : [6,3,5,null,2,0,null,null,1]
 * 
 * Example 2    :
 * Input        : nums = [3,2,1]
 * Output       : [3,null,2,null,1]
 * 
 * https://leetcode.com/problems/maximum-binary-tree/
*/

#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

int get_max_idx(vector<int> &nums, int l, int r) {
  int max_idx = l;
  for (int i = l; i < r; i++) {
    if (nums[i] > nums[max_idx]) {
      max_idx = i;
    }
  }
  return max_idx;
}

TreeNode *build(vector<int> &nums, int l, int r) {
  if (l == r)
    return nullptr;

  // * Get Max value b/w [l - r]
  int max_i = get_max_idx(nums, l, r);
  TreeNode *root = new TreeNode(nums[max_i]);

  root->left = build(nums, l, max_i);
  root->right = build(nums, max_i + 1, r);
  
  return root;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
  return build(nums, 0, nums.size());
}

int main(void) {
  // * testcase 1
  vector<int> nums = {3, 2, 1, 6, 0, 5};

  // * testcase 2
  // vector<int> nums = {3, 2, 1};

  std::cout << "Input vector: ";
  printArr(nums);

  TreeNode* root = constructMaximumBinaryTree(nums);

  std::cout << "Maximum Binary Tree" << std::endl;
  levelOrderTraversal(root);
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 58-maximum-bt.cpp -o output && ./output
