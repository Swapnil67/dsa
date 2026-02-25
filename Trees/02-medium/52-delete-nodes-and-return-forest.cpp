/*
* Leetcode - 1110
* Delete Nodes And Return Forest

* You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i],
* return true if and only if all the given nodes form exactly one valid binary tree.

* If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

* Note that the nodes have no values and that we only use the node numbers in this problem.

* Example 1:
* Input       : root = [1,2,3,4,5,6,7], to_delete = [3,5]
*
*                      1
*                /          \  
*               2             3
*            /    \         /   \
*           4      5       6     7
*

* Output      : [[1,2,null,4],[6],[7]]

* Example 2:
* Input       : root = [1,2,4,null,3], to_delete = [3]
*                  1        
*                /   \     
*               2     4
*                \    
*                 3
*
* Output      : [[1,2,4]]
* 
* https://leetcode.com/problems/delete-nodes-and-return-forest/description/
*/

// ! Google, Amazon

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "common.hpp"

using namespace std;

TreeNode *dfs(TreeNode *root, vector<TreeNode *> &ans, unordered_set<int> &del_st ) {
  if (!root)
    return root;

  root->left = dfs(root->left, ans, del_st);
  root->right = dfs(root->right, ans, del_st);

  if (del_st.count(root->data)) {
    if (root->left)
      ans.push_back(root->left);
    if (root->right)
      ans.push_back(root->right);
    return nullptr; // * Since this node is in del_st set.
  }

  return root;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * Bottom Up [Post Order Traversal]
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
  vector<TreeNode *> ans;
  if (!root)
    return ans;

  unordered_set<int> del_st(begin(to_delete), end(to_delete));
  dfs(root, ans, del_st);

  // * Insert root if its not present in delete set
  if (!del_st.count(root->data)) {
    ans.push_back(root);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  vector<int> to_delete = {3, 5};
  cout << "Input BT" << endl;
  levelOrderTraversal(root);

  // * testcase 2
  vector<TreeNode *> ans = delNodes(root, to_delete);
  for (auto &tree : ans)
    levelOrderTraversal(tree);

  return 0;
}

// * Run the code
// * g++ --std=c++20 52-delete-nodes-and-return-forest.cpp -o output && ./output

