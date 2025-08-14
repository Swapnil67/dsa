/*
* Leetcode - 2415
* Reverse Odd Levels of Binary Tree

* Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
* Return the root of the reversed tree.

* A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
* The level of a node is the number of edges along the path between it and the root node.

* Example 1:
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  

* Input: [1, 2, 3, 4, 5, 6, 7]

*                   1
*               /     \  
*             3        2
*           /  \     /  \  
*          4    5   6    7  

* Output: [1, 3, 2, 4, 5, 6, 7]

* https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <iostream>

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

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

std::vector<std::vector<int>> bfsTraversal(TreeNode* root) {
  std::vector<std::vector<int>> ans;
  if (!root)
    return ans;

  std::queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();

    int is_odd_level = 0;
    std::vector<int> temp;
    while(n--) {
      TreeNode* front = q.front();
      q.pop();

      temp.push_back(front->data);
      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }

    ans.push_back(temp);
  }

  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode* reverseOddLevelsBFS(TreeNode* root) {
  std::queue<TreeNode*> q;
  q.push(root);

  int is_odd_level = 0;
  while(!q.empty()) {
    int n = q.size();

    // * Nodes of current level
    std::vector<TreeNode*> level;

    while (n--) {
      TreeNode* front = q.front();
      q.pop();

      level.push_back(front);

      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }

    // * Reverse the odd level
    if (is_odd_level) {
      int l = 0, r = level.size() - 1;
      while (l <= r) {
        int temp = level[l]->data;
        level[l]->data = level[r]->data;
        level[r]->data = temp;
        l++, r--;
      }
    }

    is_odd_level = !is_odd_level;
  }

  return root;
}

void helper(TreeNode *p, TreeNode *q, int level) {
  // * base case
  if (!p || !q)
    return;

  // * Odd level
  if (level % 2 == 1) {
    // std::cout << p->data << " " << q->data << std::endl;
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
  }

  helper(p->left, q->right, level + 1);
  helper(p->right, q->left, level + 1);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) ~ Auxillary Recursion Space
TreeNode* reverseOddLevelsDFS(TreeNode* root) {
  helper(root->left, root->right, 1);
  return root;
}

int main(void) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::cout << "Tree Before Reverse" << std::endl;
  std::vector<std::vector<int>> tree = bfsTraversal(root);
  for (auto &level : tree)
    printArr(level);
  
  // root = reverseOddLevelsBFS(root);
  root = reverseOddLevelsDFS(root);
  
  std::cout << "Tree After Reverse" << std::endl;
  tree = bfsTraversal(root);
  for (auto &level : tree)
    printArr(level);

  return 0;
}

// * Run the code
// * g++ --std=c++20 19-reverse-odd-levels.cpp -o output && ./output

