/*
* Leetcode - 513
* Find Bottom Left Tree Value

* Given the root of a binary tree, return the leftmost value in the last row of the tree.

* Example 1:
*                 2        
*               /   \     
*             1      3

* Input       : root = [2,1,3]
* Output      : 1

* Example 2:
*                  1        
*               /     \     
*             2        3
*           /         /  \ 
*          4         5   6
*                  /  
*                 7  

* Input       : root = [1,2,3,4,null,5,6,null,null,7]
* Output      : 7


* https://leetcode.com/problems/find-bottom-left-tree-value/description/
* https://www.naukri.com/code360/problems/amusement-park_1280139
*/


#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();
    // * traverse the whole level
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      std::cout << node->data << " ";

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    std::cout << std::endl;
  }
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) [recursion stack]
int findBottomLeftValue(TreeNode* root) {
  std::queue<TreeNode *> q;
  q.push(root);

  int ans = -1;
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();

      if (i == 0)
        ans = node->data;

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  
  // * testcase 2
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  int ans = findBottomLeftValue(root);
  std::cout << "Bottom Left Tree Value: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 39-find-bottom-left-tree-value.cpp -o output && ./output

