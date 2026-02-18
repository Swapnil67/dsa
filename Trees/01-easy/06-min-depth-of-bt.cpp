/*
* Leetcode - 111
* Minimum Depth of Binary Tree 

* Example 1:
*                  1
*               /     \  
*             2        3
*           /  \     /   \  
*          4    4   6     7
* Output: 3
*
* Example 2:
*                 1
*               /   \  
*              x     3
*                  /   \  
*                 x     7
* Output: 3

* https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
* https://www.naukri.com/code360/problems/minimum-depth-in-a-binary-tree_696332
* https://www.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1
*/

// ! Amazon, Meta

#include <queue>
#include <vector>
#include <climits>
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
void printArr(vector<T> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
};

// * Using BFS 
// * As soon as we found the first leaf node we return.
int minDepthBFS(TreeNode *root) {
  if (!root)
    return 0;
  
  int level = 1;  // * Default 1 level
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {

    int n = q.size();
    // cout << n << endl;
    
    // * Process the complete level
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      // * Found the first leaf node
      if (!node->left && !node->right)
        return level;
        
      // * If exists left node then push
      if (node->left)
        q.push(node->left);

      // * If exists right node then push
      if (node->right)
        q.push(node->right);
    }

    level++;
  }

  return -1;
}

// * Using DFS 
int minDepthDFS(TreeNode *root) {
  if (!root)
    return 0;

  // * Leaf node
  if (!root->left && !root->right)
    return 1;

  int lh = root->left ? minDepthDFS(root->left) : INT_MAX;
  int rh = root->right ? minDepthDFS(root->right) : INT_MAX;

  return 1 + min(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  int depth = minDepthDFS(root);
  // int depth = minDepthBFS(root);
  cout << "Minimum Depth: " << depth << endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 06-min-depth-of-bt.cpp -o output && ./output

