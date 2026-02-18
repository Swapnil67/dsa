/*
 * Leetcode - 872
 * Leaf Similar trees
 * 
 * Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
 * 
 * Example 1    :
 * Input        : root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output       : true
 * 
 * Example 2    :
 * Input        : root1 = [1,2,3], root2 = [1,3,2]
 * Output       : false
 * 
 * https://leetcode.com/problems/leaf-similar-trees/description/
*/

// ! Amazon, twitter, Meta, Microsoft

#include <vector>
#include <iostream>

using namespace std;

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

void collectLeaves(TreeNode *root, string &leaves) {
  if (!root)
    return;

  collectLeaves(root->left, leaves);
  if (!root->left && !root->right) {
    leaves += to_string(root->data) + "_";
  }
  collectLeaves(root->right, leaves);
}

// * ------------------ Approach 1: Optimal Approach ---------------------
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool leafSimilar(TreeNode *root1, TreeNode *root2) {
  string leaves1;
  collectLeaves(root1, leaves1);

  string leaves2;
  collectLeaves(root2, leaves2);

  return leaves1 == leaves2;
}

int main(void) {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);

  bool ans = leafSimilar(root1, root2);
  std::cout << "Leaf Similar: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 21-leaf-similar-trees.cpp -o output && ./output
