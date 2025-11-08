/**
 * * Leetcode - 114
 * * Flatten Binary Tree to Linked List
 * 
 * * Input: root = [1,2,5,3,4,null,6]
 * * Output: [1,null,2,null,3,null,4,null,5,null,6]
 * 
 * * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 * * https://www.naukri.com/code360/problems/flatten-binary-tree-to-linked-list_1112615
 * * https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
*/

// ! Meta, Apple

#include <stack>
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

void inOrderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  inOrderTraversal(root->left);
  std::cout << root->data << std::endl;
  inOrderTraversal(root->right);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * DFS Approach
// * Traverse => Right -> Left -> Root
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode* prev = nullptr;
void flatten(TreeNode* root) {
  if (!root) // * Recursion Exit Condition
    return;

  flatten(root->right);
  flatten(root->left);

  root->right = prev;
  root->left = nullptr;

  prev = root;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Stack Approach
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
void flatten2(TreeNode* root) {
  if (!root)
    return;

  std::stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    st.pop();

    // * push right to stac
    if (cur->right)
      st.push(cur->right);
    
    // * push left to stack
    if (cur->left)
      st.push(cur->left);

    if (!st.empty())
      cur->right = st.top();
    cur->left = nullptr;
  }
}

int main(void) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
 
  root->right->right = new TreeNode(6);

  // flatten(root);
  flatten2(root);
  inOrderTraversal(root);

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-flatten-bt-to-ll.cpp -o output && ./output

