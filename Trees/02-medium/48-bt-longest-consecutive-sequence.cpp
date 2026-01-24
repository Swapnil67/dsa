/*
* Leetcode - PAID
* Longest Consecutive Sequence In A Binary Tree

* Given a binary tree, return the length of the longest path which has consecutive integers in increasing order 
* from root to leaves. 

* A path is defined as a sequence of nodes which share an edge between them.

* Example 1:
* Input : root = [1,null,3,2,4,null,null,null,5]
*                  1        
*                    \     
*                     3
*                   /   \     
*                  2     4
*                          \
*                           5
* Output: 3

* Example 2:
* Input : root = [2,null,3,2,null,1]
*                  2        
*                    \     
*                     3
*                   /       
*                  2    
*                 /
*                1
* Output: 2

* https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
* https://neetcode.io/problems/binary-tree-longest-consecutive-sequence/question
* https://www.naukri.com/code360/problems/longest-consecutive-sequence-in-a-binary-tree_977251
* https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1
*/

// ! Google, Amazon, Tiktok, Walmart

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

// * For every node we check if it's equal to its parent_val
void dfs(int cur, int &ans, int parent_val, TreeNode* root) {
  if (!root)
    return;
  
  // * Check if we have an increasing node [3 -> 4 -> 5]
  if (root->data - 1 == parent_val) {
    cur += 1;
  } else {
    cur = 1; // * reset the count
  }
  
  ans = std::max(ans, cur);
  dfs(cur, ans, root->data, root->left);
  dfs(cur, ans, root->data, root->right);
}

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(h) 
int longestConsecutive(TreeNode* root) {
  int ans = 0;
  if (!root)
    return ans;

  dfs(1, ans, -1, root);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);

  // * testcase 2
  // TreeNode *root = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->right->left = new TreeNode(2);
  // root->right->left->left = new TreeNode(1);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  int ans = longestConsecutive(root);
  std::cout << "Longest Consecutive Sequence: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 48-longest-consecutive-sequence-in-a-bt.cpp -o output && ./output

