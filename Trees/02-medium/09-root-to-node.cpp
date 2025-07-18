/*
* Root to Node

* Example 1:
* Input: root = [1,2,3,null,5,null,7], node = 5
*
*                  1
*               /     \  
*             2        3
*              \        \  
*               5        7

* Output: [ 1->2->5 ]

* https://www.naukri.com/code360/problems/path-in-a-tree_3843990
*/

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

bool rootToNode(TreeNode *root, int x, std::vector<int> &ans) {
  if (!root)
    return false;

  ans.push_back(root->data);

  if (root->data == x)
    return true;

  if (rootToNode(root->left, x, ans) ||
      rootToNode(root->right, x, ans))
    return true;
  
  ans.pop_back();
  return false;
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->right = new TreeNode(5);

  int node = 5;

  std::vector<int> ans;
  rootToNode(root, node, ans);
  printArr(ans);

  return 0;
}

// * run the code
// * g++ --std=c++20 11-root-to-node.cpp -o output && ./output
