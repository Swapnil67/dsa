/**
 * * Leetcode - 114
 * * Flatten Binary Tree to Linked List
 * 
 * * Example 1:
 * *             1
 * *           /    \
 * *          2      5
 * *        /   \     \
 * *       3    4      6
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

using namespace std;

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
  cout << root->data << endl;
  inOrderTraversal(root->right);
}

TreeNode* solve(TreeNode* root, TreeNode* &prev) {
  if (!root) // * Recursion Exit Condition
    return;

  solve(root->right, prev);
  solve(root->left, prev);

  root->right = prev;
  root->left = nullptr;

  prev = root;
  return root;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * DFS Approach
// * Traverse => Right -> Left -> Root
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode* flatten(TreeNode* root) {
  TreeNode* prev = nullptr;
  solve(root, prev);
  return root;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Stack Approach
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
void flatten2(TreeNode* root) {
  if (!root)
    return;

  stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    st.pop();

    // * push right to stack
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

  flatten(root);
  // flatten2(root);
  inOrderTraversal(root);

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-flatten-bt-to-ll.cpp -o output && ./output

