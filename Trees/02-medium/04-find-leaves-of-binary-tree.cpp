
/*
* Find Leaves of Binary Tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \    
*          4    5   

* Output: ans = [[4, 5, 3], [2], [1]]

* https://neetcode.io/problems/find-leaves-of-binary-tree/question
* https://www.naukri.com/code360/problems/collect-leaves_1281192
*/

// ! Google, Meta, Amazon

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int binaryTreeHeight(TreeNode* root, std::unordered_map<int, std::vector<int>> &mp) {
  if (!root)
    return 0;

  int lh = binaryTreeHeight(root->left, mp);
  int rh = binaryTreeHeight(root->right, mp);
  int height = 1 + std::max(lh, rh);
  mp[height].push_back(root->val);
  return height;
}

int height(TreeNode *root, vector<vector<int>> &ans) {
  if (!root)
    return -1; // * becoz we want leaves to have height of '0'

  int lh = height(root->left, ans);
  int rh = height(root->right, ans);

  int cur_height = max(lh, rh) + 1;
  if (ans.size() == cur_height) { // * To prevent out of bound errors
    ans.push_back({});
  }
  ans[cur_height].push_back(root->val);
  return cur_height;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Depth First Search (DFS)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> findLeaves1(TreeNode *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  std::unordered_map<int, std::vector<int>> mp;
  binaryTreeHeight(root, mp);

  for (auto &it: mp) {
    ans.push_back(it.second);
  }
  reverse(begin(ans), end(ans));
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Depth First Search (DFS)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> findLeaves2(TreeNode *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  height(root, ans);
  return ans;
}

int main() {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  std::cout << "Vertical Traversal of tree: " << std::endl;
  // std::vector<std::vector<int>> ans = findLeaves1(root);
  std::vector<std::vector<int>> ans = findLeaves2(root);
  for (auto &p : ans)
    printArr(p);

  return 0;
}


// * run the code
// * g++ --std=c++20 04-find-leaves-of-binary-tree.cpp -o output && ./output
