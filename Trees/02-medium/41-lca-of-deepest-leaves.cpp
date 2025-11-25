/*
* Leetcode - 1123
* Lowest Common Ancestor of Deepest Leaves

* Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
* Recall that:
* - The node of a binary tree is a leaf if and only if it has no children
* - The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its
*   children is d + 1.
* - The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every
*   node in S is in the subtree with root A.

* Example 1:
*                  3        
*               /     \     
*             5        1
*           /  \      /  \ 
*          6   '2'      0   8
*             /   \           
*           '7'   '4'

* Input       : root = [3,5,1,6,2,0,8,null,null,7,4]
* Output      : [2,7,4]
* Explanation : Deepest leaf nodes are ['7', '4'] depth is '3' and their LCA is '2'

* Example 2:
*                    3        
*               /         \     
*             5            1
*           /  \          /  \ 
*          6   '2'       0   8
*             /   \     /      
*           '7'   '4'  '10'

* Input       : root = [3,5,1,6,2,0,8,null,null,7,4]
* Output      : [3,5,1,6,2,0,8,null,null,7,4]
* Explanation : Deepest leaf nodes are ['7', '4', '10'] depth is '3' and their LCA is '3' (root)

* https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description
*/

// ! Google

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

// * Maps the depth of each node {node: depth}
void build_depth_map(
    TreeNode *root, int d, int &max_depth,
    std::unordered_map<TreeNode *, int> &depth_map)
{
  if (!root)
    return;

  depth_map[root] = d;
  max_depth = std::max(max_depth, d); // * check max_depth

  build_depth_map(root->left, d + 1, max_depth, depth_map);
  build_depth_map(root->right, d + 1, max_depth, depth_map);
}

TreeNode *dfs(TreeNode *root, int &max_depth,
              std::unordered_map<TreeNode *, int> &depth_map)
{
  // * Found null or node with max depth
  if (!root || max_depth == depth_map[root])
    return root;

  TreeNode *left = dfs(root->left, max_depth, depth_map);
  TreeNode *right = dfs(root->right, max_depth, depth_map);

  // * Found the LCA of max depth nodes
  if (left && right)
    return root;

  return left != nullptr ? left : right;
}

std::pair<int, TreeNode*> dfs2(TreeNode *root)
{
  // * Found null or node with max depth
  if (!root)
    return {0, nullptr};

  auto [left_depth, left] = dfs2(root->left);
  auto [right_depth, right] = dfs2(root->right);

  // * Found the LCA of max depth nodes
  if (left_depth == right_depth) {
    return {1 + left_depth, root};
  }
  else if(left_depth > right_depth) { // * left depth is more
    return {1 + left_depth, left};
  }
  return {1 + right_depth, right};    // * right depth is more
}

// * ------------------------- APPROACH: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N + N) = O(2N)
// * SPACE COMPLEXITY O(N) 
TreeNode* bruteForce(TreeNode* root) {
  // * 1. Build the depth map
  int max_depth = 0;
  std::unordered_map<TreeNode *, int> depth_map;
  build_depth_map(root, 0, max_depth, depth_map); // * O(N)

  // * For Debugging
  // std::cout << "Max Depth: " << max_depth << std::endl;
  // for (auto &[node, depth]: depth_map) {
  //   std::cout << node->data << " " << depth << std::endl;
  // }

  // * 2. Return the LCA of max_depth nodes
  return dfs(root, max_depth, depth_map); // * O(N)
}

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) [Recursion Stack]
TreeNode* lcaDeepestLeaves(TreeNode* root) {
  // * 1. Return the LCA of max_depth nodes
  return dfs2(root).second; // * O(N)
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(3);
  // root->left = new TreeNode(5);
  // root->right = new TreeNode(1);
  // root->left->left = new TreeNode(6);
  // root->left->right = new TreeNode(2);
  // root->left->right->left = new TreeNode(7);
  // root->left->right->right = new TreeNode(4);
  // root->right->left = new TreeNode(0);
  // root->right->right = new TreeNode(8);

  // * testcase 2
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->right->left->left = new TreeNode(10);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  std::cout << "Answer: " << std::endl;
  // TreeNode* ans = bruteForce(root);
  TreeNode* ans = lcaDeepestLeaves(root);
  levelOrderTraversal(ans);


  return 0;
}

// * Run the code
// * g++ --std=c++20 41-lca-of-deepest-leaves.cpp -o output && ./output

