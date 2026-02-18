/*
* Leetcode - 572
* Subtree of Another Tree

* Example 1:
* Input: root = [3,4,5,1,2], subRoot = [4,1,2]
* Output: true

* https://leetcode.com/problems/subtree-of-another-tree/
* https://www.naukri.com/code360/problems/subtree-of-another-tree_893071
* https://www.geeksforgeeks.org/problems/check-if-subtree/1
*/

// ! Meta, Amazon, Microsoft

#include <vector>
#include <iostream>

using namespace std;

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
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

bool isSame(TreeNode *rootA, TreeNode *rootB) {
  if (!rootA || !rootB)
    return rootA == rootB;

  return (rootA->data == rootB->data &&
          isSame(rootA->left, rootB->left) &&
          isSame(rootA->right, rootB->right));
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  // * We can have empty subtree
  if (!subRoot)
    return true;

  if (!root)
    return false;

  // * Check from the root itself first
  if (isSame(root, subRoot))
    return true;

  // * Now Check from root->left & root->right subtrees
  return (isSubtree(root->left, subRoot) ||
          isSubtree(root->right, subRoot));
}

int main(void) {
  // * testcase 1
  TreeNode *rootA = new TreeNode(3);
  rootA->left = new TreeNode(4);
  rootA->right = new TreeNode(5);
  
  rootA->left->left = new TreeNode(1);
  rootA->left->right = new TreeNode(2);
  
  TreeNode *rootB = new TreeNode(3);
  rootB->left = new TreeNode(1);
  rootB->right = new TreeNode(2);

  bool ans = isSubtree(rootA, rootB);
  cout << "Subtree of Another Tree: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-subtree-of-another-tree.cpp -o output && ./output

