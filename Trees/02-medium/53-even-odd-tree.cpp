/*
* Leetcode - 1609
* Even Odd Tree

* A binary tree is named Even-Odd if it meets the following conditions:

* - The root of the binary tree is at level index 0, its children are at level index 1, 
*   their children are at level index 2, etc.

* - For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order 
*   (from left to right).

* - For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order 
*   (from left to right).

* Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

* Example 1:
* Input       : root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
*
*                      1
*                /           \  
*              10              4
*            /               /   \
*           3               7     9
*         /  \             /       \
*        12   8           6         2
*

* Output      : true

* Example 2:
* Input       : root = [5,4,2,3,3,7]
*
*                    5
*                /       \  
*              4          2
*            /   \       / 
*           3     3     7  
*

* Output      : false
* 
* https://leetcode.com/problems/even-odd-tree/description/
*/

// ! Amazon

#include <queue>
#include <vector>
#include <climits>
#include <iostream>

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

// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------
// * BFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool bruteForce(TreeNode *root) {
  if (!root)
    return true;

  std::queue<TreeNode *> q;
  q.push(root);

  bool even = true;
  while (!q.empty()) {
    int N = q.size();
    std::vector<int> arr;
    while (N--) {
      TreeNode *node = q.front();
      q.pop();

      arr.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    // std::cout << "Level " << level << " : ";
    // printArr(arr);

    if (even) {
      for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 != 1) // * value must be odd
          return false;

        // * For Strictly increasing
        if (i > 0 && arr[i] <= arr[i - 1])
          return false;
      }
    } else {
      for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 != 0) // * value must be even
          return false;

        // * For Strictly decreasing
        if (i > 0 && arr[i] >= arr[i - 1])
          return false;
      }
    }

    even = !even;
  }

  return true;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * BFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool isEvenOddTree(TreeNode *root) {
  if (!root)
    return true;

  std::queue<TreeNode *> q;
  q.push(root);

  bool even = true;
  while (!q.empty()) {
    int N = q.size();

    int prev = INT_MAX;
    if (even) {
      prev = INT_MIN;
    }

    while (N--) {
      TreeNode *node = q.front();
      q.pop();

      // * If even then check if its increasing
      if (even && (node->data % 2 == 0 || node->data <= prev)) {
        return false;
      }

      // * If odd then check if its decreasing
      if (!even && (node->data % 2 != 0 || node->data >= prev)) {
        return false;
      }

      prev = node->data;

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    even = !even;
  }
  return true;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(10);
  root->right = new TreeNode(4);
  
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(12);
  root->left->left->right = new TreeNode(8);

  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  
  root->right->left->left = new TreeNode(6);
  root->right->right->right = new TreeNode(2);

  std::cout << "Input BT" << std::endl;
  levelOrderTraversal(root);

  // * testcase 2
  bool ans = isEvenOddTree(root);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 53-even-odd-tree.cpp -o output && ./output

