/*
  * Leetcode - 337
  * House Robber III

  * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

  * Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that 
  * all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses
  * were broken into on the same night.

  * Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

  * Example 1:
  *                 3        
  *               /   \     
  *             2      3
  *             \       \       
  *              3       1     

  * Input       : root = [3,2,3,null,3,null,1]
  * Output      : 7
  * Explanation : Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

  * Example 2:
  *                  3        
  *               /     \     
  *             4        5
  *           /   \       \ 
  *          1     3       1

  * Input       : root = [3,4,5,1,3,null,1]
  * Output      : 9
  * Explanation : Maximum amount of money the thief can rob = 4 + 5 = 9.


  * https://leetcode.com/problems/house-robber-iii/description/
  * https://www.naukri.com/code360/problems/amusement-park_1280139
*/

// ! Google, Adobe

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

int dfs_dp(TreeNode *root, std::unordered_map<TreeNode*, int> &cache) {
  if (cache.find(root) != cache.end())
    return cache[root];
    
  int with_root = root->data;
  if (root->left) {
    with_root += dfs_dp(root->left->left, cache) + dfs_dp(root->left->right, cache);
  }
  if (root->right) {
    with_root += dfs_dp(root->right->left, cache) + dfs_dp(root->right->right, cache);
  }
  
  int without_root = dfs_dp(root->left, cache) + dfs_dp(root->right, cache);
  int ans = std::max(with_root, without_root);
  cache[root] = ans;
  return ans;
}

std::pair<int, int> dfs(TreeNode *root) {
  if (!root)
    return {0, 0};

  auto left_p = dfs(root->left);
  auto right_p = dfs(root->right);

  int with_root = root->data + left_p.second + right_p.second;
  // * take max from left or right path
  int without_root = std::max(left_p.first, left_p.second) +
                     std::max(right_p.first, right_p.second);

  return {with_root, without_root};
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Recursion two possibilities [with_root, without_root]
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(N) [recursion stack]
int bruteForce(TreeNode *root) {
  if (!root)
    return 0;

  int with_root = root->data;
  if (root->left) {
    with_root += bruteForce(root->left->left) + bruteForce(root->left->right);
  }
  if (root->right) {
    with_root += bruteForce(root->right->left) + bruteForce(root->right->right);
  }

  int without_root = bruteForce(root->left) + bruteForce(root->right);
  return std::max(with_root, without_root);
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * Dynamic Programming (Memoization)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int betterApproach(TreeNode *root) {
  std::unordered_map<TreeNode*, int> cache;
  cache[nullptr] = 0;
  return dfs_dp(root, cache);
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------
// * Recursion two possibilities [with_root, without_root]
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) [recursion stack]
int rob(TreeNode* root) {
  auto p = dfs(root);
  return std::max(p.first, p.second);
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(3);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->right = new TreeNode(3);
  // root->right->right = new TreeNode(1);
  
  // * testcase 2
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(1);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  // int ans = bruteForce(root);
  // int ans = betterApproach(root);
  int ans = rob(root);
  std::cout << "Rob amount: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 37-house-robber-iii.cpp -o output && ./output

