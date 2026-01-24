
/*
* Leetcode - 543
* Boundary Traversal of tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  

* Output: ans = [1, 2, 4, 5, 6, 7, 3]

* https://neetcode.io/problems/boundary-of-binary-tree
* https://leetcode.com/problems/boundary-of-binary-tree/description/
* https://www.naukri.com/code360/problems/boundary-traversal_790725
* https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/

// ! Meta, Amazon, Google, Uber, Adobe, Microsoft

#include <stack>
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

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

bool isLeaf(TreeNode *node) {
  return !node->left && !node->right;
}

void addLeaves(TreeNode* root, std::vector<int> &ans) {
  if (isLeaf(root)) {
    ans.push_back(root->data);
    return;
  }

  if (root->left)
    addLeaves(root->left, ans);

  if (root->right)
    addLeaves(root->right, ans);
}

void addLeftBoundary(TreeNode *root, std::vector<int> &res) {
  TreeNode *cur = root->left;
  while (cur) {
    if (!isLeaf(cur))
      res.push_back(cur->data);
    if (cur->left)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

void addRightBoundary(TreeNode *root, std::vector<int> &res) {
  TreeNode *cur = root->right;
  std::stack<int> st;
  
  while (cur) {
    if (!isLeaf(cur))
      st.push(cur->data);

    if (cur->right)
      cur = cur->right;
    else
      cur = cur->left;
  }

  while (!st.empty()) {
    res.push_back(st.top());
    st.pop();
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> boundaryTraversal(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;

  // * Root is not leaf the push to ans
  if (!isLeaf(root))
    ans.push_back(root->data);

  // * Left Boundary of tree
  addLeftBoundary(root, ans);

  // * Only Leaf Nodes of tree
  addLeaves(root, ans);

  // * Right Boundary of tree reverse order
  addRightBoundary(root, ans);

  return ans;
}

int main() {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);

  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);

  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);

  // * testcase 2
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(20);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);

  root->right->left = new TreeNode(18);
  root->right->right = new TreeNode(25);

  std::vector<int> ans = boundaryTraversal(root);
  printArr(ans);

  return 0;
}

// * run the code
// * g++ --std=c++17 03-boundary-traversal.cpp -o output && ./output