/*
* Leetcode - 173
* Binary Search Tree Iterator
*
*                  7
*               /     \  
*             3        15
*                    /   \  
*                   9     20

* Example 1:
* Input: ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
*        [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
* Output: [null, 3, 7, true, 9, true, 15, true, 20, false]

* https://leetcode.com/problems/binary-search-tree-iterator/description/
* https://www.naukri.com/code360/problems/bst-iterator_1112601
*/

// ! Amazon, Google, Meta, HSBC, Visa

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

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * H - Height of tree
// * TIME COMPLEXITY  O(H) - At any given point we have 'H' nodes in stack
// * SPACE COMPLEXITY O(1) - Because we are removing all the elements from stack
class BSTIterator {
  void pushAll(TreeNode *root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

public:
  std::stack<TreeNode *> st;
  BSTIterator(TreeNode *root) { pushAll(root); }

  int next() {
    TreeNode *node = st.top();
    st.pop();
    pushAll(node->right);
    return node->data;
  }

  bool hasNext() { return !st.empty(); }
};

int main(void) {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator *bSTIterator = new BSTIterator(root);
  bSTIterator->next();    // return 3
  bSTIterator->next();    // return 7
  bSTIterator->hasNext(); // return True
  bSTIterator->next();    // return 9
  bSTIterator->hasNext(); // return True
  bSTIterator->next();    // return 15
  bSTIterator->hasNext(); // return True
  bSTIterator->next();    // return 20
  bSTIterator->hasNext(); // return False
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-ceil-in-bst.cpp -o output && ./output
