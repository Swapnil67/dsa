/*
* Leetcode - 894
* All Possible Full Binary Trees

* Given an integer n, return a list of all possible full binary trees with n nodes. 
* Each node of each tree in the answer must have Node.val == 0.

* Each element of the answer is the root node of one possible tree. 
* You may return the final list of trees in any order.

* A full binary tree is a binary tree where each node has exactly 0 or 2 children.

* Example 1:
* Input       : n = 7
* Output      : [[0,0,0,null,null,0,0,null,null,0,0],
*                [0,0,0,null,null,0,0,0,0],
*                [0,0,0,0,0,0,0],
*                [0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

* https://leetcode.com/problems/all-possible-full-binary-trees/description/
*/

// ! DP
// ! Amazon, Google

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

// * Recursion
// * Draw recursion tree to understand more clearly
// * Full Binary tree (FBT) is only possible with odd 'n' values
std::vector<TreeNode *> solve_brute(int n) {
  if (n % 2 == 0) // * Cannot create FBT with even nodes
    return {};

  if (n == 1) {
    return {new TreeNode(0)};
  }

  std::vector<TreeNode *> ans;
  for (int i = 1; i < n; i += 2) { // * odd loop

    // * All possible FBT from left
    // * no of nodes in left = i
    std::vector<TreeNode *> fbt_left = solve_brute(i);

    // * All possible FBT from right
    // * no of nodes in right = n - i - 1
    std::vector<TreeNode *> fbt_right = solve_brute(n - i - 1);

    // * Here we will try all the possibilites from left & right side
    for (auto &fbt_l : fbt_left) {
      for (auto &fbt_r : fbt_right) {
        TreeNode *root = new TreeNode(0);
        root->left = fbt_l;
        root->right = fbt_r;
        ans.push_back(root);
      }
    }
  }

  return ans;
}

// * Recursion + Memoization
// * Draw recursion tree to understand more clearly
// * Full Binary tree (FBT) is only possible with odd 'n' values
std::vector<TreeNode *> solve(int n, std::unordered_map<int, std::vector<TreeNode *>> &cache) {
  // * Return from cache
  if (cache.count(n))
    return cache[n];

  if (n % 2 == 0) // * Cannot create FBT with even nodes
    return {};

  if (n == 1) {
    return {new TreeNode(0)};
  }

  std::vector<TreeNode *> ans;
  for (int i = 1; i < n; i += 2) { // * odd loop

    // * All possible FBT from left
    // * no of nodes in left = i
    std::vector<TreeNode *> fbt_left = solve(i, cache);

    // * All possible FBT from right
    // * no of nodes in right = n - i - 1
    std::vector<TreeNode *> fbt_right = solve(n - i - 1, cache);

    // * Here we will try all the possibilites from left & right side
    for (auto &fbt_l : fbt_left) {
      for (auto &fbt_r : fbt_right) {
        TreeNode *root = new TreeNode(0);
        root->left = fbt_l;
        root->right = fbt_r;
        ans.push_back(root);
      }
    }
  }

  cache[n] = ans;
  return ans;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) 
std::vector<TreeNode *> bruteForce(int n) {
  return solve_brute(n);
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) 
std::vector<TreeNode *> allPossibleFBT(int n) {
  std::unordered_map<int, std::vector<TreeNode *>> cache;
  return solve(n, cache);
}

int main(void) {
  int n = 7;
  
  std::vector<TreeNode *> trees = allPossibleFBT(n);
  for (int i = 0; i < trees.size(); ++i) {
    std::cout << "--------- Tree " << i + 1 << " ---------" << std::endl;
    levelOrderTraversal(trees[i]);
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 45-all-possible-full-bt.cpp -o output && ./output

/* 
 * Case 1
 * root
 * |
 * v
 * 0 1 2 3 4 5 6
 * 
 * Not Possible to make FBT becoz there are no nodes on left
 
 * Case 2
 *   root
 *   |
 *   v
 * 0 1 2 3 4 5 6
 * 
 * Possible to make FBT 
 
 * Case 3
 *    root
 *     |
 *     v
 * 0 1 2 3 4 5 6
 * 
 * Not Possible to make FBT since right side has even no. of nodes
 
 * So we can say that
 * 0 1 2 3 4 5 6
 * Only [1, 3, 5] can be a root for FBT (Only odd indexes)
*/