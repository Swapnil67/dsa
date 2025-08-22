/*
* Leetcode - 2641
* Cousins in Binary Tree II

* Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

* Two nodes of a binary tree are cousins if they have the same depth with different parents.
* Return the root of the modified tree.

* Note that the depth of a node is the number of edges in the path from the root node to it.


* Example 1:
* Input: 
*                   5             => 5
*               /      \     
*             4         9         => 13
*           /   \     /  \  
*          1    10   x    7       => 18

* Output: 
*                   0        
*               /      \     
*             0         0      
*           /  \      /   \  
*          7    7    x    11


* https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
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
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void inOrderTraversal(TreeNode* root) {
  if (!root)
    return;

  inOrderTraversal(root->left);
  std::cout << root->data << " ";
  inOrderTraversal(root->right);
}

// * Finds the level sum at each level in given BT
std::vector<int> getTreeLevelSum(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    int level_sum = 0;
    while (n--) {
      TreeNode *node = q.front();
      q.pop();
      level_sum += node->data;
      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    ans.push_back(level_sum);
  }

  return ans;
}

// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
TreeNode *bruteForce(TreeNode *root) {
  if (!root)
    return root;

  // * 1. Find the sum of each level
  std::vector<int> level_sum_arr = getTreeLevelSum(root);
  printArr(level_sum_arr);

  // * 2. Level order traversal
  std::queue<TreeNode *> q;
  q.push(root);
  root->data = 0; // * Since root does not have any cousins

  int cur_level = 1;
  while (!q.empty()) {
    int n = q.size();
    
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      // * node->data = level_sum - sibling_sum
  
      int sibling_sum = node->left ? node->left->data : 0;
      sibling_sum += node->right ? node->right->data : 0;

      // * Find the sum for left child
      if (node->left) {
        node->left->data = level_sum_arr[cur_level] - (sibling_sum);
        q.push(node->left);
      }
      
      // * Find the sum for right child
      if (node->right) {
        node->right->data = level_sum_arr[cur_level] - (sibling_sum);
        q.push(node->right);
      }

    }

    cur_level++;
  }

  return root;
}


// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * Calculate level sum on the go
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
TreeNode* replaceValueInTree(TreeNode* root) {
  if (!root)
    return root;

  std::queue<TreeNode *> q;
  q.push(root);

  int level_sum = root->data;
  while (!q.empty()) {  
    int next_level_sum = 0;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      q.pop();


      // * Calculate the next level sum
      if (node->left) {
        next_level_sum += node->left->data;
      }

      if (node->right) {
        next_level_sum += node->right->data;
      }

      // * Calculate the sibling sum
      int sibling_sum = node->left ? node->left->data : 0;
      sibling_sum += node->right ? node->right->data : 0;

      // * update the sibling sum as node value
      if (node->left) {
        node->left->data = sibling_sum;
        q.push(node->left);
      }
      
      // * update the sibling sum as node value
      if (node->right) {
        node->right->data = sibling_sum;
        q.push(node->right);
      }

      // * node->data = level_sum - sibling_sum
      // * Update the current nodes value
      node->data = level_sum - node->data;
    }
    
    level_sum = next_level_sum;
  }

  return root;
}

int main(void) {
  // * testcase 1
  int k = 2;

  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(9);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(10);
  
  root->right->right = new TreeNode(7);

  std::cout << "Input Tree" << std::endl;
  inOrderTraversal(root);
  std::cout << std::endl;
  
  // TreeNode *ans = bruteForce(root); 
  TreeNode *ans = replaceValueInTree(root); 

  std::cout << "Output Tree" << std::endl;
  inOrderTraversal(ans);
  std::cout << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 23-cousins-in-bt.cpp -o output && ./output

