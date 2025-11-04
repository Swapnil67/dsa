/*
* Leetcode - 783, 530
* Minimum Distance Between BST Nodes
*
* Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two
* different nodes in the tree.
*

*
* Example : 1
*                  4
*               /     \  
*             2        6
*           /  \  
*          1    3 
*                        
* Input   : root = [4,2,6,1,3]
* Output  : 1

*
* Example : 2
*                  1
*               /     \  
*              0      48
*           /    \  
*          12    49
*                        
* Input   : root = [1,0,48,null,null,12,49]
* Output  : 1

* https://leetcode.com/problems/minimum-distance-between-bst-nodes/
* https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
*/

// ! Microsoft, Google

#include <vector>
#include <climits>
#include <iostream>

struct TreeNode {
  public:
  int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
      data = v;
      left = nullptr;
      right = nullptr;
    }

    TreeNode(int v, TreeNode* l, TreeNode* r) {
      data = v;
      left = l;
      right = r;
    }

    ~TreeNode() {
      if (left)
        delete left;
      if (right)
        delete right;
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

void inorder(TreeNode *root, std::vector<int> &nums) {
  if (!root)
    return;

  inorder(root->left, nums);
  nums.push_back(root->data);
  inorder(root->right, nums);
}

void dfs(int &cur_min, TreeNode *root, TreeNode *&prev) {
  if (!root)
    return;

  dfs(cur_min, root->left, prev);
  if (prev != nullptr) {
    cur_min = std::min(cur_min, (root->data - prev->data));
  }
  prev = root; // * save it to prev node
  dfs(cur_min, root->right, prev);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(n)
int bruteForce(TreeNode* root) {
  // * 1. create a vector in inorder
  std::vector<int> nums;
  inorder(root, nums);
  // printArr(nums);
  
  // * 2. Find min diff
  int res = nums[1] - nums[0];
  for (int i = 2; i < nums.size(); ++i) {
    res = std::min(res, (nums[i] - nums[i - 1]));
  }

  return res;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
int minDiffInBST(TreeNode* root) {
  TreeNode* prev = nullptr;
  int res = INT_MAX;
  dfs(res, root, prev);
  return res;
}

int main(void) {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  int ans = bruteForce(root);
  // int ans = minDiffInBST(root);
  std::cout << "Min distance: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-min-distance-between-bst-nodes.cpp -o output && ./output
