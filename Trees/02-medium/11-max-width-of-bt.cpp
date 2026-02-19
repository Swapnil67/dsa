/*
* Leetcode - 662
* Maximum Width of Binary Tree
* Given the root of a binary tree, return the maximum width of the given tree.
* width = no of nodes in a level b/w any 2 nodes

* Example 1:
*
*                  1
*               /     \  
*             3         2
*           /  \         \  
*          5    3         9

* Input: root = [1,3,2,5,3,null,9]
* Output: 4

* Example 2:
*
*                  1
*               /     \  
*              3       2
*             /         \  
*            5           9
*           /             \  
*          7               8

* Input: root = [1,3,2,5,null,null,9,7,null,null,null,null,null,null,8]
* Output: 8

* https://leetcode.com/problems/maximum-width-of-binary-tree/description/
* https://www.naukri.com/code360/problems/maximum-width-of-a-binary-tree_981173
* https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1
*/

// ! Meta, Amazon, Flipkart

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

template <typename T>
void printArr(vector<T> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}
// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Might go out of 'long long' range if input is too big.
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(TreeNode *root) {
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  int ans = 0;
  while (!q.empty()) {
    int n = q.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; ++i) {
      auto [node, idx] = q.front();
      q.pop();

      if (i == 0)
        first = idx;
      if (i == n - 1)
        last = idx;

      if (node->left) {
        q.push({node->left, ((2 * idx) + 1)});
      }
      if (node->right) {
        q.push({node->right, ((2 * idx) + 2)});
      }
    }
    ans = max(ans, (last - first + 1));
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * BFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int widthOfBinaryTree(TreeNode *root) {
  int max_width = 0;
  if (!root)
    return max_width;

  queue<pair<TreeNode *, long long>> q;
  q.push({root, 0});

  while (!q.empty()) {
    // * find the max_width in cur_level
    int L = (int)q.front().second, R = (int)q.back().second;
    max_width = max(max_width, R - L + 1);

    long long level_min = q.front().second; // * base value
    
    // * Loop over the cur level
    size_t n = q.size();  
    while (n--) {
      auto [node, idx] = q.front();
      q.pop();

      long long next_id = idx - level_min;

      if (node->left)
        q.push({node->left, (next_id * 2l + 1l)});

      if (node->right)
        q.push({node->right, (next_id * 2l + 2l)});
    }

  }

  return max_width;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // int width = bruteForce(root);
  int width = widthOfBinaryTree(root);
  cout << "Maximum Width of Binary Tree " << width << endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 11-max-width-of-bt.cpp -o output && ./output
