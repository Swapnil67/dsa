/*
* Leetcode - 2265
* Count Nodes Equal to Average of Subtree

* Given the root of a binary tree, return the number of nodes where the value of the node is equal
* to the average of the values in its subtree.
* 
* - The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
* - A subtree of root is a tree consisting of root and all of its descendants.
* 
* On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
* 
* Example 1:
* Input       : root = [4,8,5,0,1,null,6]
*                  4        
*                /   \     
*               8     5
*             /   \    \    
*            0     1    6
*
* Output      : 5
* Explanation : For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
*               For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
*               For the node with value 0: The average of its subtree is 0 / 1 = 0.
*               For the node with value 1: The average of its subtree is 1 / 1 = 1.
*               For the node with value 6: The average of its subtree is 6 / 1 = 6.
* 
* Example 2:
* Input       : root = [2]
*                  2        
*
* Output      : 2

* https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/
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

void findSumAndCount(int &sum, int &count, TreeNode *root) {
  if (!root)
    return;
  sum += root->data;
  count += 1;
  findSumAndCount(sum, count, root->left);
  findSumAndCount(sum, count, root->right);
}

void solve_brute(TreeNode *root, int &ans) {
  if (!root)
    return;

  int sum = 0, count = 0;
  findSumAndCount(sum, count, root);
  std::cout << "(" << sum << " / " << count << ")"  << std::endl;
  if ((sum / count) == root->data) {
    ans += 1;
  }

  solve_brute(root->left, ans);
  solve_brute(root->right, ans);
}

std::pair<int, int> solve(TreeNode *root, int &ans) {
  if (!root)
    return {0, 0};

  auto [left_sum, left_cnt] = solve(root->left, ans);
  auto [right_sum, right_cnt] = solve(root->right, ans);

  int cur_sum = root->data + left_sum + right_sum; // * current sum of subtree.
  int cur_count = 1 + left_cnt + right_cnt;        // * current count of subtree.
  if ((cur_sum / cur_count) == root->data)
    ans += 1;

  return {cur_sum, cur_count};
}

// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------
// * Calculate Sum & count for each node in tree
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) [Recursion Stack Space] 
int bruteForce(TreeNode* root) {
  int ans = 0;
  solve_brute(root, ans);
  return ans;
}


// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * Start calculating from the bottom of tree 
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) [Recursion Stack Space]  
int averageOfSubtree(TreeNode* root) {
  int ans = 0;
  solve(root, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(8);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(6);

  // * testcase 2
  // TreeNode *root = new TreeNode(1);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  // int ans = bruteForce(root);
  int ans = averageOfSubtree(root);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 50-count-nodes-equal-to-average-of-subtree.cpp -o output && ./output

