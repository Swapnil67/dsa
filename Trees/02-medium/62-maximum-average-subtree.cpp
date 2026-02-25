/*
 * Leetcode - PAID
 * Maximum Average Subtree
 * 
 * Given the root of a binary tree, return the maximum average value of a subtree of that tree. 
 * Answers within 10⁻⁵ of the actual answer will be accepted.
 * 
 * A subtree of a tree is any node of that tree plus all its descendants.
 * 
 * The average value of a tree is the sum of its values, divided by the number of nodes.
 * 
 * Example 1    :
 * Input        : root = [5,6,1]
 * Output       : 6.000
 * 
 * Example 2    :
 * Input        : root = [0,null,1]
 * Output       : 1.0
 * 
 * https://neetcode.io/problems/maximum-average-subtree/question
*/

// ! Amazon

#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

pair<int, int> dfs(double &ans, TreeNode* root) {
  if (!root)
    return {0, 0};

  // * postorder traversal, solve for both child nodes first.
  auto [left_cnt, left_sum] = dfs(ans, root->left);
  auto [right_cnt, right_sum] = dfs(ans, root->right);

  // * Find current avg
  double cur_sum = (double)(root->data + left_sum + right_sum);
  double cur_cnt = (double)(1.0 + left_cnt + right_cnt);
  // std::cout << cur_cnt << " " << cur_sum << std::endl;

  ans = max(ans, (double)(cur_sum / cur_cnt));
  return {cur_cnt, cur_sum};
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * Recursion + Memoization
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) 
double maximumAverageSubtree(TreeNode* root) {
  double ans = 0;
  dfs(ans, root);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(6);
  root->right = new TreeNode(1);

  double ans = maximumAverageSubtree(root);
  std::cout << "Maximum Average Subtree: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 62-maximum-average-subtree.cpp -o output && ./output
