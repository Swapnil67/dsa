
/*
* Left View of Binary tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \        \  
*          4    5        7  
*              /
*             6


* Output: ans = [1, 2, 4, 6]

* https://www.naukri.com/code360/problems/right-view_764605
* https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*/

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

void printArr(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

// * Recursive Pre Order Traversal (Root -> Left -> Right)
void solve(TreeNode *root, std::vector<int> &ans, int level) {
  if (!root)
    return;

  // * To get the first node from level
  if (level == ans.size())
    ans.push_back(root->data);

  solve(root->left, ans, level + 1);
  solve(root->right, ans, level + 1);
}

std::vector<int> leftView(TreeNode *root) {
  std::vector<int> ans;
  solve(root,ans,0);
  return ans;
}

int main() {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);

  root->right->right = new TreeNode(7);
  
  std::vector<int> ans = leftView(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 08-left-view-bt.cpp -o output && ./output
