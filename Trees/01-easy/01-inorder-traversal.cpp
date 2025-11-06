/*
* Leetcode - 94
* Binary Tree Inorder Traversal

*
* Example 1:
*                  1
*               /     \  
*             2        3
*           /  \     /   \  
*          4    4   6     7

* Output: [4, 2, 5, 1, 6, 3, 7]

* https://leetcode.com/problems/binary-tree-inorder-traversal/description/
* https://www.naukri.com/code360/problems/inorder-traversal_3839605
* https://www.geeksforgeeks.org/problems/inorder-traversal/1
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
}

// ! Left | Root | Right

// * DFS Recursion
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
// * SPACE COMPLEXITY Best Case  = O(logn) ~ O(height of tree) * Size of Activation Record
void inOrderDFS(TreeNode* node, std::vector<int> &ans) {
  if (node == nullptr)
    return;

  inOrderDFS(node->left, ans);
  ans.push_back(node->data);
  inOrderDFS(node->right, ans);
}

// * DFS Iterative - (Stack)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
void inOrderIterative(TreeNode* root, std::vector<int> &ans) {
  if (root == nullptr)
    return;

  std::stack<TreeNode *> st;
  TreeNode *node = root;
  while (root || st.size()) {
    // * Go to extreme left
    while (root) {
      st.push(root);
      root = root->left;
    }

    root = st.top();
    st.pop();
    ans.push_back(root->data);

    // * Go to right
    root = root->right;
  }
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);


  // * testcase 2
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  std::vector<int> ans;
  inOrderDFS(root, ans);
  // inOrderIterative(root, ans);

  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-inorder-traversal.cpp -o output && ./output
