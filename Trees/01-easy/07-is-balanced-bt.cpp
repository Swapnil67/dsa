/*
* Leetcode - 110
* Balanced Binary Tree 

* https://leetcode.com/problems/balanced-binary-tree/
* https://www.naukri.com/code360/problems/is-height-balanced-binary-tree_975497
* https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
*/

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

// * Use Max Depth of a tree
// * Using DFS 
int isBalanced(TreeNode *root) {
  if (!root)
    return 0;

  // * calculate left height
  int lh = isBalanced(root->left);
  if (lh == -1)
    return -1;

  // * calculate right height
  int rh = isBalanced(root->right);
  if (rh == -1)
    return -1;

  if (abs(rh - lh) > 1)
    return -1;

  return 1 + max(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);

  // * toggle this
  // root->left->left->left = new TreeNode(5);

  int balanced = isBalanced(root);
  bool ans = balanced >= 0;
  cout << "is Balanced Binary Tree: " << ans << endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 07-is-balanced-bt.cpp -o output && ./output

