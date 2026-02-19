/*
  * Leetcode - 1448
  * Count Good Nodes in Binary Tree
  * 
  *                   3
  *               /       \  
  *             1          4
  *           /  \       /  \  
  *          3   x      1   5

  * Input: root = [3,1,4,3,null,1,5]
  * Output: 4
  * Explanation: 
  *     Root Node (3) is always a good node.
  *     Node 4 -> (3,4) is the maximum value in the path starting from the root.
  *     Node 5 -> (3,4,5) is the maximum value in the path
  *     Node 3 -> (3,1,3) is the maximum value in the path.

  * https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
  * https://www.naukri.com/code360/problems/good-nodes_3169337
*/

#include <iostream>
using namespace std;

typedef struct TreeNode TreeNode;

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

void dfs(TreeNode* root, int &ans, int cur_max) {
  if (!root) // * Base case
    return;

  if (root->data >= cur_max)
    ans++;

  // * Update the max_val in current path
  cur_max = max(cur_max, root->data);
  dfs(root->left, ans, cur_max);
  dfs(root->right, ans, cur_max);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * DFS Approach
// * Pre order traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) [recursion stack space]
int goodNodes(TreeNode* root) {
  int ans = 0;
  dfs(root, ans, root->data);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  
  root->left->left = new TreeNode(3);
  
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(5);

  int ans = goodNodes(root);
  cout << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 17-count-good-nodes.cpp -o output && ./output

