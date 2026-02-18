/*
* Leetcode - 112
* Path Sum

* Example 1   :
* Input       : root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
* Output      : true

* Example 2   :
* Input       : root = [1,2,3], targetSum = 5
* Output      : false

* Example 3   :
* Input       : root = [], targetSum = 0
* Output      : false
* Explanation : Since the tree is empty, there are no root-to-leaf paths.


* https://leetcode.com/problems/path-sum/description/
* https://www.naukri.com/code360/problems/path-sum_3170353/
* https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
*/

// ! Amazon, Meta

#include <queue>
#include <vector>
#include <iostream>

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
};

void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> level;
    int size = q.size();
    for(int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      std::cout << node->data << " ";
    }
  }
  std::cout << std::endl;
}

bool solve(TreeNode *node, int target_sum, int total) {
  if (!node)
    return false;
  
  total += node->data;

  // * If sum matched target and is Leaf node
  if (total == target_sum && !node->left && !node->right) {
    return true;
  }

  return solve(node->left, target_sum, total) || solve(node->right, target_sum, total);
}

// * Depth First Search
bool hasPathSum(TreeNode* root, int targetSum) {
  return solve(root, targetSum, 0);
}

// * Depth First Search
bool hasPathSum2(TreeNode *root, int targetSum) {
  if (!root)
    return false;

  targetSum -= root->data;

  if (targetSum == 0 && !root->left && !root->right)
    return true;

  return hasPathSum(root->left, targetSum) ||
         hasPathSum(root->right, targetSum);
}

int main(void) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);

  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);

  int target = 22;
  std::cout << "Target Sum: " << target << std::endl;
  std::cout << "Input Tree: ";
  levelOrder(root);
  
  bool ans = hasPathSum(root, target);
  std::cout << "Path Sum: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-path-sum.cpp -o output && ./output

