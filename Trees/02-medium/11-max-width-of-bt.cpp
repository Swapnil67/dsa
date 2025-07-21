/*
* Leetcode - 662
* Maximum Width of Binary Tree
* Given the root of a binary tree, return the maximum width of the given tree.

*
*                   1
*               /       \  
*             3          2
*           /  \          \  
*          5    3          9

* Example 1:
* Input: root = [1,3,2,5,3,null,9]
* Output: 4

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

int widthOfBinaryTree(TreeNode *root) {
  std::queue<std::pair<TreeNode *, int>> q;
  q.push({root, 0});

  int ans = 0;
  while (!q.empty()) {
    size_t n = q.size();
    int levelMin = q.front().second;
    int first, last;

    // * Loop over the cur level
    for (int i = 0; i < n; ++i) {
      TreeNode* node = q.front().first;
      int cur_id = q.front().second - levelMin;
      q.pop();
      // std::cout << cur_id << std::endl;

      if (i == 0)
        first = cur_id; // * save the first element of current level
      if (i == n - 1)
        last = cur_id; // * save the last element of current level

      if (node->left)
        q.push({node->left, (long long)cur_id * 2l + 1l});
      if (node->right)
        q.push({node->right, (long long)cur_id * 2l + 2l});
    }

    ans = std::max(ans, last - first + 1);
    // std::cout << first << " " << last << std::endl;
  }

  return ans;
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
