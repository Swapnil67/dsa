/*
* Leetcode - 2583
* Kth Largest Sum in a Binary Tree

* You are given the root of a binary tree and a positive integer k.
* The level sum in the tree is the sum of the values of the nodes that are on the same level.
* Return the kth largest level sum in the tree (not necessarily distinct). 
* If there are fewer than k levels in the tree, return -1.

* Note that two nodes are on the same level if they have the same distance from the root.

* Example 1:
*                   5             => 5
*               /      \     
*             8         9         => 17
*           /   \     /  \  
*          2    1    3    7       => 13
*        /  \       
*       4    6                    => 10

* Input:  root = [5,8,9,2,1,3,7,4,6], k = 2
* Output: 13

* https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

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

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * BFS + Vector
int bruteForce(TreeNode *root, int k) {
  std::queue<TreeNode *> q;
  q.push(root);
  
  std::vector<int> level_sum_arr;
  while (!q.empty()) {
    int n = q.size();
    int level_sum = 0;

    while (n--) {
      TreeNode* node = q.front();
      q.pop();

      level_sum += node->data;

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    level_sum_arr.push_back(level_sum);
  }

  std::sort(level_sum_arr.begin(), level_sum_arr.end());
  printArr(level_sum_arr);

  return level_sum_arr[level_sum_arr.size() - k];
}

// * BFS + Min Heap
int betterApproach(TreeNode *root, int k) {
  std::queue<TreeNode *> q;
  q.push(root);

  std::priority_queue<int> pq;
  std::vector<int> level_sum_arr;
  while (!q.empty()) { // * O(n)
    int n = q.size();
    int level_sum = 0;

    while (n--) {
      TreeNode* node = q.front();
      q.pop();

      level_sum += node->data;

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    pq.push(level_sum);  // * O(h*logk)
    // std::cout << pq.size() << " -> " << pq.top() << std::endl;
  }

  while (k - 1) {
    k--;
    pq.pop();
  }

  return pq.size() < k ? -1 : pq.top();
}

int main(void) {
  // * testcase 1
  int k = 2;

  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(8);
  root->right = new TreeNode(9);
  
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(1);
  
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(7);

  root->left->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(6);

  // int ans = bruteForce(root, k);
  int ans = betterApproach(root, k);
  std::cout << k << "th largest element in BT: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-kth-largest-sum-in-bt.cpp -o output && ./output

