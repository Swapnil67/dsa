/*
* Leetcode - 108
* Convert Sorted Array to Binary Search Tree

* Given an integer array nums where the elements are sorted in ascending order, 
* convert it to a height-balanced binary search tree.

*                  0
*               /     \  
*            -10       5
*           /  \     /   \  
*          x   -3   x     9

* Example 1:
* Input: nums = [-10,-3,0,5,9]
* Output: [0,-10,5,null,-3,null,9]

* https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
* https://www.naukri.com/code360/problems/convert-sorted-array-to-bst_1264995
* https://www.geeksforgeeks.org/problems/array-to-bst4443/1
*/

#include <queue>
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
};

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

void levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> ans;
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> level;
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      std::cout << node->data << " ";
    }
  }

}

TreeNode *helper(std::vector<int> &nums, int l, int r) {
  if (l > r)
    return nullptr;

  // * get the mid 
  int m = (l + r) / 2;

  TreeNode* root = new TreeNode(nums[m]);
  root->left = helper(nums, l, m - 1);     // * elements on left of mid
  root->right = helper(nums, m + 1, r);     // * elements on right of mid

  return root;
}

TreeNode *sortedArrayToBST(std::vector<int> &nums) {
  return helper(nums, 0, nums.size() - 1);
}

int main(void) {
  std::vector<int> arr = {-10, -3, 0, 5, 9};
  std::cout << "Input Sorted array" << std::endl;
  printArr(arr);

  TreeNode* root = sortedArrayToBST(arr);
  levelOrder(root);

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-convert-sorted-arr-to-bst.cpp -o output && ./output
