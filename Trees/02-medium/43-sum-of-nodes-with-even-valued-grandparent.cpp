/*
* Leetcode - 1315
* Sum of Nodes with Even-Valued Grandparent

* Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. 
* If there are no nodes with an even-valued grandparent, return 0.

* A grandparent of a node is the parent of its parent if it exists.

* Example 1:
*                   "6"        
*               /       \     
*             7           "8"
*           /  \        /   \ 
*         '2'   '7'   '1'     '3'
*        /    /   \           \        
*       9    7     4          '5'

* Input       : root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
* Output      : 18
* Explanation : The red nodes (single quotes) are the nodes with even-value grandparent 
*               while the blue nodes (double quotes) are the even-value grandparents.

* https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
*/

// ! Amazon

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "common.hpp"

using namespace std;

void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_mp) {
  if (!root) return;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      TreeNode* node = q.front();
      q.pop();

      if (node->left) {
        parent_mp[node->left] = node;
        q.push(node->left);
      }

      if (node->right) {
        parent_mp[node->right] = node;
        q.push(node->right);
      }
    }
  }
}

void dfs(TreeNode *cur, TreeNode *p, TreeNode *gp, int &sum) {
  if (!cur)
    return;

  if (gp && (gp->data % 2 == 0))
    sum += cur->data;

  dfs(cur->left, cur, p, sum);
  dfs(cur->right, cur, p, sum);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Create the parent_mp + BFS
// * TIME COMPLEXITY O(N + N) = O(2N)
// * SPACE COMPLEXITY O(N) 
int bruteForce(TreeNode* root) {
  // * 1. mark parents
  unordered_map<TreeNode*, TreeNode*> parent_mp;
  mark_parents(root, parent_mp);

  // * 2. BFS
  int ans = 0;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();

    TreeNode* node = q.front();
    q.pop();

    if (parent_mp[node]) { // * check if parent exists
      auto parent = parent_mp[node];
      if (parent_mp[parent]) { // * check if grand parent exists
        auto grand_parent = parent_mp[parent];
        if (!(grand_parent->data % 2)) {
          ans += node->data;
        }
      }
    }

    if (node->left) {
      q.push(node->left);
    }

    if (node->right) {
      q.push(node->right);
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * Create the parent_mp on the go + BFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) 
int sumEvenGrandparent(TreeNode* root) {
  // * 1. mark parents
  unordered_map<TreeNode*, TreeNode*> parent_mp;

  // * 2. BFS
  int ans = 0;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    if (parent_mp[node]) { // * check if parent exists
      auto parent = parent_mp[node];
      if (parent_mp[parent]) { // * check if grand parent exists
        auto grand_parent = parent_mp[parent];
        if (!(grand_parent->data % 2)) {
          ans += node->data;
        }
      }
    }

    if (node->left) {
      parent_mp[node->left] = node;
      q.push(node->left);
    }
    
    if (node->right) {
      parent_mp[node->right] = node;
      q.push(node->right);
    }
  }

  return ans;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int sumEvenGrandparentDfs(TreeNode *root) {
  int sum = 0;
  dfs(root, nullptr, nullptr, sum);
  return sum;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(7);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(7);
  root->left->left->left = new TreeNode(9);
  root->left->right->left = new TreeNode(1);
  root->left->right->right = new TreeNode(4);
  
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(5);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  cout << "Answer: " << endl;
  // int ans = bruteForce(root);
  int ans = sumEvenGrandparent(root);
  // int ans = sumEvenGrandparentDfs(root);
  cout << "Sum of Nodes with Even-Valued Grandparent: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 43-sum-of-nodes-with-even-valued-grandparent.cpp -o output && ./output

