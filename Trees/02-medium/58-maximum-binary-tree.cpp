/*
 * 
*/

#include <vector>
#include <iostream>

using namespace std;

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

  ~TreeNode()
  {
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

int get_max_idx(vector<int> &nums, int l, int r) {
  int max_i = l;
  for (int i = l; i < r; i++) {
    if (nums[max_i] < nums[i]) {
      max_i = i;
    }
  }
  return max_i;
}

TreeNode *build(vector<int> &nums, int l, int r) {
  if (l == r)
    return nullptr;

  int max_i = get_max_idx(nums, l, r);
  TreeNode *root = new TreeNode(nums[max_i]);
  root->left = build(nums, l, max_i);
  root->right = build(nums, max_i + 1, r);
  return root;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
  return build(nums, 0, nums.size());
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
