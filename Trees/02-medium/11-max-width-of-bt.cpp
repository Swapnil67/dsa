/*
* Leetcode - 662
* Maximum Width of Binary Tree
* Given the root of a binary tree, return the maximum width of the given tree.
* width = no of nodes in a level b/w any 2 nodes

* Example 1:
*
*                  1
*               /     \  
*             3         2
*           /  \         \  
*          5    3         9

{1, 0}
{3, 1}, {2, 2}
{5, 3}, {3, }

* Input: root = [1,3,2,5,3,null,9]
* Output: 4

* Example 2:
*
*                  1
*               /     \  
*              3       2
*             /         \  
*            5           9
*           /             \  
*          7               8

* Input: root = [1,3,2,5,null,null,9,7,null,null,null,null,null,null,8]
* Output: 8

* https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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

  TreeNode(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

// * BFS
int widthOfBinaryTree(TreeNode *root) {
  std::queue<std::pair<TreeNode *, long long>> q;
  q.push({root, 0});

  int max_width = 0;
  while (!q.empty()) {
    
    // * find the max_width in cur_level
    int L = (int)q.front().second, R = (int)q.back().second;
    long long level_min = q.front().second; // * base value
    max_width = std::max(max_width, R - L + 1);

    long long level_min = q.front().second; // * base value
    
    // * Loop over the cur level
    size_t n = q.size();  
    for (int i = 0; i < n; ++i) {
      TreeNode* node = q.front().first;
      long long cur_id = q.front().second - level_min;
      q.pop();

      if (node->left)
        q.push({node->left, (cur_id * 2l + 1l)});

      if (node->right)
        q.push({node->right, (cur_id * 2l + 2l)});
    }

  }

  return max_width;
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  int width = widthOfBinaryTree(root);
  std::cout << "Maximum Width of Binary Tree " << width << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 11-max-width-of-bt.cpp -o output && ./output
