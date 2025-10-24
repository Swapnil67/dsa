/*
* Leetcode - 99
* Recover Binary Search Tree
* You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
* Recover the tree without changing its structure.

*
* Example 1:
* Input: root = [3,1,4,null,null,2]
*                  3
*               /     \  
*             1        4
*                     / 
*                   2
* Output: [2,1,4,null,null,3]
*                  2
*               /     \  
*             1        4
*                     / 
*                   3

* https://leetcode.com/problems/recover-binary-search-tree/description/
*/

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

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
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

void inorder(TreeNode *root, std::vector<int> &arr) {
  if (!root)
    return;

  inorder(root->left, arr);
  arr.push_back(root->data);
  // std::cout << root->data << std::endl;
  inorder(root->right, arr);
}

void solve_brute(TreeNode *root, int &idx, std::vector<int> &arr) {
  if (!root)
    return;

  solve_brute(root->left, idx, arr);
  if (root->data != arr[idx]) {
    root->data = arr[idx];
  }
  idx += 1;
  solve_brute(root->right, idx, arr);
}

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * TIME COMPLEXITY  O(n + nlogn)
// * SPACE COMPLEXITY O(n)
void bruteForce(TreeNode* root) {
  std::vector<int> arr;
  inorder(root, arr);
  printArr(arr);

  std::sort(arr.begin(), arr.end()); // * O(nlogn)
  // printArr(arr);

  int idx = 0;
  solve_brute(root, idx, arr);
}

TreeNode *prev = new TreeNode(INT_MIN);
TreeNode *first = nullptr;
TreeNode *middle = nullptr;
TreeNode *last = nullptr;

void solve(TreeNode *root)
{
  if (!root)
    return;

  solve(root->left);

  if (prev != NULL && (root->data < prev->data)) {
    if (!first) {
      first = prev;
      middle = root;
    } else {
      last = root;
    }
  }

  // * Mark current as node as previous
  prev = root;
  solve(root->right);
}

void recoverTree(TreeNode* root) {
  solve(root);

  if (first && last) {
    // std::cout << "1" << std::en  dl;
    std::swap(first->data, last->data);
  }

  if (first && middle) {
    // std::cout << "2" << std::endl;
    std::swap(first->data, middle->data);
  }
}

int main(void) {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(2);

  // bruteForce(root);
  recoverTree(root);

  std::vector<int> ans;
  inorder(root, ans);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-recover-bst.cpp -o output && ./output
