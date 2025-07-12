
/*
* Bottom View of Binary tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  

* Output: ans = [4, 2, 1, 3, 7]

* https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401
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

std::vector<int> bottomView(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;
  
  return ans;
}

int main() {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::vector<int> ans = bottomView(root);
  printArr(ans);
}


// * run the code
// * g++ --std=c++17 05-top-view-bt.cpp -o output && ./output
