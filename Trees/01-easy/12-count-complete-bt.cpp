/*
* Leetcode - 543
* Diameter of Binary Tree

* Example 1:
*
*                 1
*               /  \  
*             2     3
*           /  \        
*          4    5     

* Input: root = [1,2,3,4,5]
* Output: 3
* Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

* https://leetcode.com/problems/diameter-of-binary-tree/
*/

#include <vector>
#include <iostream>

typedef struct TreeNode TreeNode;

struct TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
  }
};

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
};

void inOrderDFS(TreeNode *root, int &count) {
  if (!root)
    return;
  count++;
  inOrderDFS(root->left, count);
  inOrderDFS(root->right, count);
}

int countLeftHeight(TreeNode *root) {
  int height = 0;
  if (!root)
    return height;

  while (root) {
    height++;
    root = root->left;
  }

  return height;
}

int countRightHeight(TreeNode *root) {
  int height = 0;
  if (!root)
    return height;

  while (root) {
    height++;
    root = root->right;
  }

  return height;
}

// * ------------------ Approach 1: Brute Force ---------------------
// * DFS Recursion
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(h)
int bruteForce(TreeNode* root) {    
  int count = 0;
  inOrderDFS(root, count);
  return count;
}

// * ------------------ Approach 2: Optimal Approach ---------------------
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(logn^2)
int countNodes(TreeNode* root) {
  if (!root)
    return 0;
  
  // * Count the left height of tree
  int lh = countLeftHeight(root);

  // * Count the right height of tree
  int rh = countRightHeight(root);
  // std::cout << lh << " " << rh << std::endl;

  // * If both height are same then it is a complete tree
  if (lh == rh)
    return (1 << lh) - 1; // * 2^lh - 1

  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);

  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(11);

  // int count = bruteForce(root);
  int count = countNodes(root);
  std::cout << "Count: " << count << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-count-complete-bt.cpp -o output && ./output

