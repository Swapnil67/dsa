/*
* Leetcode - 543
* Diameter of Binary Tree
*
* The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
* This path may or may not pass through the root.
* The length of a path between two nodes is represented by the number of edges between them.

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

int diameterOfBinaryTree(TreeNode* root, int &diameter) {
  if (!root)
    return 0;

  // * calculate the left height
  int lh = diameterOfBinaryTree(root->left, diameter);

  // * calculate the right height
  int rh = diameterOfBinaryTree(root->right, diameter);

  // * calculate max diamter
  diameter = std::max(diameter, lh + rh);

  // * Add cur node to height
  return 1 + std::max(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  int diameter = 0;
  diameterOfBinaryTree(root, diameter);
  std::cout << "Diameter of Binary Tree: " << diameter << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 08-diameter-of-bt.cpp -o output && ./output

