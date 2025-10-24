/*
* Leetcode - 1161
* Maximum Level Sum of a Binary Tree

* Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

* Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

* Example 1:
* Input: 
*                   1             
*               /      \     
*             7         0
*           /   \     /  \  
*          7    -8   x   x

* Output: 2

* https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <climits>
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
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
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

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Calculate level sum on the go
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxLevelSum(TreeNode* root) {
  if (!root)
    return 0;

  std::queue<TreeNode *> q;
  q.push(root);

  int ans = 0;
  int max_sum = INT_MIN, level = 1;

  while (!q.empty()) {
    int level_sum = 0;
    int n = q.size();

    while (n--) {
      TreeNode *node = q.front();
      q.pop();
      
      level_sum += node->data;

      // * Calculate the next level sum
      if (node->left) {
        q.push(node->left);
      }
      
      if (node->right) {
        q.push(node->right);
      }
    }

    if (level_sum > max_sum) {
      max_sum = level_sum;
      ans = level;
    }
    level++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);

  // * testcase 2
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(0);
  
  // root->left->left = new TreeNode(7);
  // root->left->right = new TreeNode(-8);
  
  // root->right->left = new TreeNode(-7);
  // root->right->right = new TreeNode(9);

  std::cout << "Input Tree" << std::endl;
  std::vector<std::vector<int>> tree = bfsTraversal(root);
  for (auto &level : tree)
    printArr(level);
  
  int level = maxLevelSum(root); 
  std::cout << "Max sum level: " << level << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 29-max-level-sum-of-a-bt.cpp -o output && ./output