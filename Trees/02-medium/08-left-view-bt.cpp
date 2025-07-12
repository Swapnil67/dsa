
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
*/

#include <map>
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

void printArr(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

// * Recursive Pre Order Traversal (Root -> Left -> Right)
void leftView(TreeNode *root, std::vector<int> &ans, int level) {
  if (!root)
    return;

  if (level == ans.size())
    ans.push_back(root->data);

  leftView(root->left, ans, level + 1);
  leftView(root->right, ans, level + 1);
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
  
  std::vector<int> ans;
  leftView(root, ans, 0);
  printArr(ans);
}


// * run the code
// * g++ --std=c++17 08-left-view-bt.cpp -o output && ./output
