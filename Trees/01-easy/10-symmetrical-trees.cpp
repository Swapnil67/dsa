/*
* Leetcode - 101
* Symmetric Tree

* Example 1:
* Input: root = [1,2,2,3,4,4,3]
*
*                  1
*               /     \  
*             2        2
*           /  \     /   \  
*          3    4   4     3

* Output: true

* Example 2:
* Input: root = [1,2,2,null,3,null,3]
*
*                  1
*               /     \  
*             2        2
*              \         \  
*               3         3

* Output: false

* https://leetcode.com/problems/symmetric-tree/description/
* https://www.naukri.com/code360/problems/tree-symmetricity_630426
* https://www.geeksforgeeks.org/problems/symmetric-tree/1
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

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
void printArr(vector<T> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

// * rootA -> root | left | right
// * rootB -> root | right | left
// * And Compare 
bool dfs(TreeNode* rootA, TreeNode* rootB) {
  if (!rootA || !rootB)
    return rootA == rootB;

  if (rootA->data != rootB->data)
    return false;

  // * Go in the opposite directions since its a mirror image
  return dfs(rootA->left, rootB->right) &&
         dfs(rootA->right, rootB->left);
}

bool isSymmetric(TreeNode* root) {
  if (!root)
    return true;
  
  return dfs(root->left, root->right);
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  // * testcase 2
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(2);
  
  // root->left->right = new TreeNode(3);
  // root->right->right = new TreeNode(3);

  bool ans = isSymmetric(root);
  cout << "Is Symmetric Tree " << ans << endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 10-symmetrical-trees.cpp -o output && ./output
