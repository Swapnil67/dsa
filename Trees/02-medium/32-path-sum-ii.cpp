/*
* Leetcode - 113
* Path Sum II

* Given the root of a binary tree and an integer targetSum, 
* return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
* Each path should be returned as a list of the node values, not node references.

* A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

* Example 1:
* Input: 
*                  5        
*               /     \     
*             4        8
*            /        /  \  
*           11       13   4
*         /   \          /  \
*        7    2        5     1

* Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
* Output: [[5,4,11,2],[5,8,4,5]]

* https://leetcode.com/problems/path-sum-ii/
* https://www.naukri.com/code360/problems/finding-paths_1281314
* https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
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

void dfs(
    TreeNode *root,
    int &cur_sum,
    int &target_sum,
    std::vector<int> &path,
    std::vector<std::vector<int>> &ans)
{
  if (!root)
    return;

  cur_sum += root->data;
  path.push_back(root->data);
  
  // * Found Root to Leaf which matches target sum
  if (cur_sum == target_sum && !root->left && !root->right) {
    ans.push_back(path);
  }
  
  dfs(root->left, cur_sum, target_sum, path, ans);
  dfs(root->right, cur_sum, target_sum, path, ans);
  
  cur_sum -= root->data;
  path.pop_back();
}


// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::vector<std::vector<int>> pathSum(TreeNode *root, int target_sum) {
  std::vector<std::vector<int>> ans;
  if (!root)
    return ans;

  std::vector<int> path;
  int cur_sum = 0;
  dfs(root, cur_sum, target_sum, path, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  int target_sum = 22;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(1);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  std::vector<std::vector<int>> ans = pathSum(root, target_sum);
  std::cout << "Path Sum: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 32-path-sum-ii.cpp -o output && ./output

