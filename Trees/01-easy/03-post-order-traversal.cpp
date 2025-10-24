/*
* Leetcode - 145
* Binary Tree Prostorder Traversal

* https://leetcode.com/problems/binary-tree-postorder-traversal/description/
* https://www.naukri.com/code360/problems/postorder-traversal_2035933
*/

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

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

// ! Left | Right | Root


// * Using Recursion
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
// * SPACE COMPLEXITY Best Case  = O(logn) ~ O(height of tree) * Size of Activation Record
void postOrderRecursive(TreeNode* node, std::vector<int> &ans) {
  if (node == nullptr)
    return;

  // std::cout << node->data << std::endl;
  postOrderRecursive(node->left, ans);
  postOrderRecursive(node->right, ans);
  ans.push_back(node->data);
}

// * Just reverse of Pre Order Traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY 
// *    O(n) - stack
// *    O(n) - output array
void postOrderIterative(TreeNode *root, std::vector<int> &ans) {
 if (!root)
    return;

  std::stack<TreeNode *> st;

  TreeNode* cur = root;
  st.push(root);
  while (st.size()) {
    TreeNode* topNode = st.top();
    st.pop();

    ans.push_back(topNode->data);
    if (topNode->left)
      st.push(topNode->left);
      
    if (topNode->right)
      st.push(topNode->right);
  }

  std::reverse(ans.begin(), ans.end());
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
  // postOrderRecursive(root, ans);
  postOrderIterative(root, ans);

  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-post-order-traversal.cpp -o output && ./output
