
/*
* Leetcode - 199
* Right View of Binary tree

* Example 1:
* Input: 
*
*                  1
*               /     \  
*             2        3
*           /  \        \  
*          4    5        7  
*              /
*             6


* Output: ans = [1, 3, 7, 6]

* https://leetcode.com/problems/binary-tree-right-side-view/
* https://www.naukri.com/code360/problems/right-view_764605
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

// * Recursive Pre Order Traversal (Root -> Right -> Left)
void solve(TreeNode *root, std::vector<int> &ans, int level) {
  if (!root)
    return;

  // * To get the last node from level
  if (level == ans.size())
    ans.push_back(root->data);

  solve(root->right, ans, level + 1); // * First go to right
  solve(root->left, ans, level + 1); // * Then check on left
}

std::vector<int> rightView(TreeNode *root) {
  std::vector<int> ans;
  solve(root, ans, 0);
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

  std::vector<int> ans = rightView(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 07-right-view-bt.cpp -o output && ./output
