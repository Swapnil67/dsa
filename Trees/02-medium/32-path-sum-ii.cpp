/*
* Leetcode - 113
* Path Sum II

* Given the root of a binary tree and an integer targetSum, 
* return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
* Each path should be returned as a list of the node values, not node references.

* A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

* Example 1:
* Input: 
*                  5        
*               /     \     
*             4        8
*            /        /  \  
*           11       13   4
*         /   \          /  \
*        7    2        5     1

* Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
* Output: [[5,4,11,2],[5,8,4,5]]

* https://leetcode.com/problems/path-sum-ii/
* https://www.naukri.com/code360/problems/finding-paths_1281314
* https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
*/

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

void dfs(
    TreeNode *root,
    int target_sum,
    vector<int> &path,
    vector<vector<int>> &ans)
{
  if (!root)
    return;

  target_sum -= root->data;
  path.push_back(root->data);
  
  // * Found Root to Leaf which matches target sum
  if (target_sum == 0 && !root->left && !root->right) {
    ans.push_back(path);
  }

  dfs(root->left, target_sum, path, ans);
  dfs(root->right, target_sum, path, ans);
  
  target_sum += root->data;
  path.pop_back();
}


// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<vector<int>> pathSum(TreeNode *root, int target_sum) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  vector<int> path;
  int cur_sum = 0;
  dfs(root, target_sum, path, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  int target_sum = 22;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(1);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  vector<vector<int>> ans = pathSum(root, target_sum);
  cout << "Path Sum: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 32-path-sum-ii.cpp -o output && ./output

