/*
* Leetcode - 144
* Binary Tree Preorder Traversal

*
* Example 1:
*                  1
*               /     \  
*             2        3
*           /  \     /   \  
*          4    4   6     7

* Output: [1, 2, 4, 5, 3, 6, 7]

* https://leetcode.com/problems/binary-tree-preorder-traversal/description/
* https://www.naukri.com/code360/problems/preorder-traversal_2035934
* https://www.geeksforgeeks.org/problems/preorder-traversal/1
*/

#include <stack>
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

// ! Root | Left | Right

// * DFS Recursion
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
// * SPACE COMPLEXITY Best Case  = O(logn) ~ O(height of tree) * Size of Activation Record
void preOrderDFS(TreeNode* node, std::vector<int> &ans) {
  if (!node)
    return;

  // std::cout << node->data << std::endl;
  ans.push_back(node->data);
  preOrderDFS(node->left, ans);
  preOrderDFS(node->right, ans);
}

// * DFS Iterative - (Stack)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
void preOrderIterative(TreeNode* root, std::vector<int> &ans) {
  if (!root)
    return;

  std::stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* node = st.top();
    st.pop();
    ans.push_back(node->data);
    // std::cout << node->data << std::endl;

    // * since its a stack we'll store right node first and then left node
    
    if (node->right)
      st.push(node->right);
    
    if (node->left)
      st.push(node->left);
  }
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::vector<int> ans;
  preOrderDFS(root, ans);
  // preOrderIterative(root, ans);

  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-pre-order-traversal.cpp -o output && ./output
