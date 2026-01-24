/*
* Leetcode - PAID
* Binary Tree Longest Consecutive Sequence II

* A consecutive path is a path where the values of the consecutive nodes in the path differ by one. 
* This path can be either increasing or decreasing.
* 
* - For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
* 
* On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
* 
* Example 1:
* Input       : root = [1,2,3]
*                  1        
*                /   \     
*               2     3
*
* Output      : 2
* Explanation : The longest consecutive path is [1, 2] or [2, 1].
* 
* Example 2:
* Input       : root = [2,1,3]
*                  2        
*                /   \     
*               1     3
*
* Output      : 3
* Explanation : The longest consecutive path is [1, 2, 3] or [3, 2, 1].

* https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
* https://neetcode.io/problems/binary-tree-longest-consecutive-sequence-ii/
*/

// ! Google, Uber

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

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
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

std::vector<int> solve(int &max_val, TreeNode *root) {
  if (!root)
    return {0, 0};

  int inr = 1, dcr = 1;

  if (root->left) {
    std::vector<int> left = solve(max_val, root->left);
    if (root->data == root->left->data + 1) {
      dcr = left[1] + 1; // * decreasing
    } else if (root->data == root->left->data - 1) {
      inr = left[0] + 1; // * increasing
    }
  }
  
  if (root->right) {
    std::vector<int> right = solve(max_val, root->right);
    if (root->data == root->right->data + 1) {
      dcr = right[1] + 1; // * decreasing
    } else if (root->data == root->right->data - 1) {
      inr = right[0] + 1; // * increasing
    }
  }

  max_val = std::max(max_val, (inr + dcr - 1));
  return {inr, dcr};
}

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(h) 
int longestConsecutive(TreeNode* root) {
  int ans = 0;
  solve(ans, root);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  // * testcase 2
  // TreeNode *root = new TreeNode(2);
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(3);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  int ans = longestConsecutive(root);
  std::cout << "Longest Consecutive Sequence: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 49-bt-longest-consecutive-sequence-ii.cpp -o output && ./output
