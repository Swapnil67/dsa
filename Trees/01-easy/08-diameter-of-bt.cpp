/*
* Leetcode - 543
* Diameter of Binary Tree
*
* The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
* This path may or may not pass through the root.
* The length of a path between two nodes is represented by the number of edges between them.

* Example 1:
*
*                 1
*               /  \  
*             2     3
*           /  \        
*          4    5     

* Input: root = [1,2,3,4,5]
* Output: 3
* Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

* https://leetcode.com/problems/diameter-of-binary-tree/
* https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552
* https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*/

// ! Paypal, Adobe, Amazon

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

// * Same as max depth of BT
int dfs(TreeNode* root, int &diameter) {
  if (!root)
    return 0;

  // * calculate the left height
  int lh = dfs(root->left, diameter);

  // * calculate the right height
  int rh = dfs(root->right, diameter);

  // * calculate max diamter
  diameter = max(diameter, lh + rh);

  // * Add cur node to height
  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
  int d = 0;
  dfs(root, d);
  return d;
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  int diameter = diameterOfBinaryTree(root);
  cout << "Diameter of Binary Tree: " << diameter << endl;
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 08-diameter-of-bt.cpp -o output && ./output

