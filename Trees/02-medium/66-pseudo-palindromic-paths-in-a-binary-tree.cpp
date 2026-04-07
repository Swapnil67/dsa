/*
 * Leetcode - 1457
 * Pseudo-Palindromic Paths in a Binary Tree
 * 
 * Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic 
 * if at least one permutation of the node values in the path is a palindrome.
 * 
 * Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
 * 
 * Example 1    :
 * Input        : root = [2,3,1,3,1,null,1]
 *                  2        
 *                /   \     
 *               3     1
 *             /   \    \    
 *            3     1    1
 * 
 * Output       : 2
 * Explanation  : [2, 3, 3] & [2, 1, 1]
 * 
 * Example 2    :
 * Input        : root = [2,1,1,1,3,null,null,null,null,null,1]
 * Output       : 1
 * Explanation  : 
 * 
 * https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree
*/

#include "../common.hpp"

using namespace std;

void dfs(TreeNode *root, int &ans, vector<int> &freq) {
  if (!root)
    return;

  freq[root->data]++;

  if (!root->left && !root->right) {
    int odd_freq = 0;
    for (auto &n : freq) {
      if (n % 2 == 1)
        odd_freq += 1;
    }
    if (odd_freq <= 1)
      ans += 1;
  }

  dfs(root->left, ans, freq);
  dfs(root->right, ans, freq);

  freq[root->data]--;
}

void dfs2(TreeNode *root, int cur_val, int &ans) {
  if (!root)
    return;
  
  cur_val = cur_val ^ (1 << root->data);
  if (!root->left && !root->right && (cur_val & (cur_val - 1)) == 0) {
    ans += 1;
  }

  dfs2(root->left, cur_val, ans);
  dfs2(root->right, cur_val, ans);
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Using a count vector for frequency of each element
// * if In a path we have odd_freq <= 1 then that path is palindrome
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int pseudoPalindromicPaths(TreeNode *root) {
  if (!root)
    return 0;

  int ans = 0;
  vector<int> freq(10, 0);
  dfs(root, ans, freq);
  return ans;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Follow up question (Don't use external vector)
// * We'll use bitmask
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) ~ [Stack Space]
int pseudoPalindromicPaths2(TreeNode *root) {
  if (!root)
    return 0;

  int ans = 0;
  dfs2(root, 0, ans);
  return ans;
}

int main(void) {

  // * testcase 1
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->right = new TreeNode(1);
  
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);

  root->right->right = new TreeNode(1);

  cout << "Input Tree:" << endl;
  levelOrderTraversal(root);

  // int ans = pseudoPalindromicPaths(root);
  int ans = pseudoPalindromicPaths2(root);

  cout << "Ans: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 66-pseudo-palindromic-paths-in-a-binary-tree.cpp -o output && ./output
