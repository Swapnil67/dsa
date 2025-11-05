/*
* Leetcode - 257
* Binary Tree Paths

* Example 1:
* Input: root = [1,2,3,null,5]
*
*                  1
*               /     \  
*             2        3
*              \          
*               5       

* Output: ["1->2->5", "1->3"]

* https://leetcode.com/problems/binary-tree-paths/description/
* https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
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

// * Note here the 'temp' passed by value so it won't have its previous value when it gets returned from
// * function in recursion
void dfs(TreeNode *root,  std::vector<std::string> &ans, std::string temp) {
  temp += std::to_string(root->data);
  
  // * Go to the left
  if (root->left)
    dfs(root->left, ans, temp + "->");
  
  // * Go to the right
  if (root->right)
    dfs(root->right, ans, temp + "->");
    
  // * Add the path
  if (!root->left && !root->right)
    ans.push_back(temp);
}

std::vector<std::string> rootToNode(TreeNode *root) {
  std::vector<std::string> ans;
  std::string cur = "";
  dfs(root, ans, "");
  return ans;
}


int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->right = new TreeNode(5);

  std::vector<std::string> ans = rootToNode(root);
  printArr(ans);

  return 0;
}

// * run the code
// * g++ --std=c++20 11-binary-tree-paths.cpp -o output && ./output
