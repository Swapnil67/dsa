/*
* Leetcode - 104
* Maximum Depth of Binary Tree 
*
* Example 1:
*                  1
*               /     \  
*             2        3
*           /  \     /   \  
*          4    4   6     7
* Output: 3
*
* Example 2:
*                  1
*               /     \  
*             x        3
* Output: 2

* https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
* https://www.naukri.com/code360/problems/maximum-depth-of-a-binary-tree_1090542
* https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
*/

#include <queue>
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

// * Using BFS
int maxDepthBFS(TreeNode *root) {
  int level = 0;
  if (!root)
    return level;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {

    // * Process the complete level
    int n = q.size();
    // cout << n << endl;
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      // * If exists left node then push
      if (node->left)
        q.push(node->left);
      
      // * If exists right node then push
      if (node->right)
        q.push(node->right);
    }
    level++; // * Add this level to tree depth
  }

  return level;
}

// * Using DFS
int maxDepthDFS(TreeNode *root) {
  if (!root)
    return 0;
  
  int lh = maxDepthDFS(root->left); // * calculate left height
  int rh = maxDepthDFS(root->right); // * calculate right height

  return 1 + max(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // int depth = maxDepthBFS(root);
  int depth = maxDepthDFS(root);
  cout << "Maximum Depth: " << depth << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 05-max-depth-of-bt.cpp -o output && ./output