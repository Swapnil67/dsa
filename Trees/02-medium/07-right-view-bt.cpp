
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
* https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
*/

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

// * Recursive Pre Order Traversal (Root -> Right -> Left)
void dfs(TreeNode *root, std::vector<int> &ans, int level) {
  if (!root)
    return;

  // * To get the last node from level
  if (level == ans.size())
    ans.push_back(root->data);

  dfs(root->right, ans, level + 1); // * First go to right
  dfs(root->left, ans, level + 1); // * Then check on left
}

// * DFS
std::vector<int> rightViewDFS(TreeNode *root) {
  std::vector<int> ans;
  dfs(root, ans, 0);
  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using Level Order Traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> rightViewBFS(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();

      if (i == n - 1)
        ans.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
  }

  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Variant1: Print Both Left & right side view in clockwise order (Do not repeat root node)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> rightViewVariant1(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;

  std::queue<TreeNode *> q;
  q.push(root);

  std::vector<int> left_side;
  std::vector<int> right_side;

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();

      if (i == 0)
        left_side.push_back(node->data);
      if (i == n - 1)
        right_side.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
  }

  // * Merge two left_side & right_side clockwise
  for (int i = left_side.size() - 1; i >= 0; --i)
    ans.push_back(left_side[i]);
  for (int i = 1; i < right_side.size(); ++i)
    ans.push_back(right_side[i]);
  
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

  std::cout << "Input Tree" << std::endl;
  levelOrderTraversal(root);

  std::cout << "Right view of the BT" << std::endl;
  // std::vector<int> ans = rightViewDFS(root);
  // std::vector<int> ans = rightViewBFS(root);
  std::vector<int> ans = rightViewVariant1(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 07-right-view-bt.cpp -o output && ./output

