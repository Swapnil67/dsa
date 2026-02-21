/*
* Leetcode - 129
* Sum Root to Leaf Numbers

* You are given the root of a binary tree containing digits from 0 to 9 only.
* Each root-to-leaf path in the tree represents a number.
* - For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

* Return the total sum of all root-to-leaf numbers. 
* Test cases are generated so that the answer will fit in a 32-bit integer.

* A leaf node is a node with no children.

* Example 1:
* Input: 
*                  1        
*               /     \     
*             2        3

* Input       : root = [1,2,3]
* Output      : 25
* Explanation : The root-to-leaf path 1->2 represents the number 12.
*               The root-to-leaf path 1->3 represents the number 13.
*               Therefore, sum = 12 + 13 = 25.


* https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
* https://www.naukri.com/code360/problems/sum-root-to-leaf_1095657
* https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1
*/

#include <queue>
#include <vector>
#include <iostream>

#include "common.hpp"

using namespace std;

void dfs(TreeNode* root, int &sum, string &cur) {
  if (!root)
    return;

  cur.push_back(root->data + '0');
  dfs(root->left, sum, cur);
  dfs(root->right, sum, cur);

  // * At leaf node
  if (!root->left && !root->right) {
    // cout << cur << endl;
    sum += stoi(cur);
    return;
  }

  cur.pop_back();
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int sumNumbers(TreeNode* root) {
  int sum = 0;
  if (!root)
    return sum;

  string cur = "";
  dfs(root, sum , cur);
  return sum;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  int ans = sumNumbers(root);
  cout << "Sum Root to Leaf Numbers: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 33-sum-root-to-Leaf-no.cpp -o output && ./output

