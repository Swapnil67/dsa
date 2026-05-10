/*
 * Leetcode - PAID
 * Closest Binary Search Tree Value II
 * 
 * Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that 
 * are closest to the target. You may return the answer in any order.
 * 
 * You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 * 
 * Example 1    :
 * Input        : root = [4,2,5,1,3], target = 3.714286, k = 2
 * Output       : [4,3]
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : root = [1], target = 0.000000, k = 1
 * Output       : [1]
 * Explanation  : 
 * 
 * https://neetcode.io/problems/closest-binary-search-tree-value-ii/question
*/

#include "../common.hpp"

// ! Amazon, Google, LinkedIn

typedef pair<double, int> P;

void inorder_dfs(TreeNode *root, double &target, int k,
                 priority_queue<P, vector<P>, greater<>> &max_h)
{
  if (!root)
    return;

  inorder_dfs(root->left, target, k, max_h);

  max_h.push({abs((double)root->data - target), root->data}); // * push to min heap
  if (max_h.size() > k)
    max_h.pop();

  inorder_dfs(root->right, target, k, max_h); 
}

void dfs(TreeNode* node, double& target, int& k, deque<int>& dq) {
  if (!node) return;

  dfs(node->left, target, k, dq);

  dq.push_back(node->data);
  if (dq.size() > k) {
    if (abs(target - dq.front()) <= abs(target - dq.back())) {
      dq.pop_back();
      return;
    } else {
      dq.pop_front();
    }
  }

  dfs(node->right, target, k, dq);
}

// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(n)
vector<int> bruteForce(TreeNode *root, double target, int k) {
  vector<int> ans;
  if (!root)
    return ans;

  priority_queue<P, vector<P>, greater<>> max_h;
  inorder_dfs(root, target, k, max_h);

  // * Top 'k' closest nodes
  while (k-- && !max_h.empty()) {
    ans.push_back(max_h.top().second);
    max_h.pop();
  }

  return ans;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(h + k)
vector<int> closestKValues(TreeNode *root, double target, int k) {
  if (!root)
    return {};

  deque<int> dq;
  dfs(root, target, k, dq);
  return vector<int>(begin(dq), end(dq));
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(1);
  int k = 2;
  double target = 3.714286;

  cout << "target: " << target << endl;
  cout << "k: " << k << endl;

  vector<int> ans = bruteForce(root, target, k);
  // vector<int> ans = closestKValues(root, target, k);
  cout << "Closest K Values: ";
  printArr(ans);

  // cout << "Closest node: " << ans << endl;

  return 0;
}