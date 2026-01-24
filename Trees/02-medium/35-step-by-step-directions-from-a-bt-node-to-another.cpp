/*
  * Leetcode - 2096
  * Step-By-Step Directions From a Binary Tree Node to Another

  * You are given the root of a binary tree with n nodes. 
  * Each node is uniquely assigned a value from 1 to n. 
  * You are also given an integer startValue representing the value of the start node s, and a different integer
  * destValue representing the value of the destination node t.

  * Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path
  * as a string consisting of only the uppercase letters 'L', 'R', and 'U'. 

  * Each letter indicates a specific direction:
  * - 'L' means to go from a node to its left child node.
  * - 'R' means to go from a node to its right child node.
  * - 'U' means to go from a node to its parent node.

  * Return the step-by-step directions of the shortest path from node s to node t.

  * Example 1:
  * Input: 
  *                  5        
  *               /     \     
  *             1        2
  *            /        /  \  
  *           3       6     4

  * Input       : root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
  * Output      : "UURL"
  * Explanation : The shortest path is: 3 → 1 → 5 → 2 → 6.


  * https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
  * https://www.naukri.com/code360/problems/finding-paths_1281314
  * https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
*/

// ! Google, Amazon

#include <queue>
#include <vector>
#include <iostream>

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


TreeNode* find_lca(TreeNode* root, int start, int dest) {
  if (!root || root->data == start || root->data == dest)
    return root;

  TreeNode* left = find_lca(root->left, start, dest);
  TreeNode* right = find_lca(root->right, start, dest);

  if (left && right)
    return root;

  return left != nullptr ? left : right;
}

// * Root to Node
bool root_to_node(TreeNode *root, std::string &path, int target) {
  if (!root)
    return false;
  // std::cout << path << std::endl;

  // * Found the target node
  if (root->data == target) {
    return true;
  }

  // * If we found node in 'left' or 'right' return
  path.push_back('L');
  if (root_to_node(root->left, path, target)) {
    return true;
  }

  path.pop_back();
  path.push_back('R');
  if (root_to_node(root->right, path , target)) {
    return true;
  }

  path.pop_back();
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// ! Memory Limit Exceeded
// * 1. Find LCA for Src & Dest
// * 2. Find Path from LCA to Src
// * 3. Find Path from LCA to dest
// * TIME COMPLEXITY O(3N) ~ O(N)
// * SPACE COMPLEXITY O(N)
std::string bruteForce(TreeNode* root, int src, int dest) {
  // * 1. Find LCA for Src & Dest
  TreeNode *lca = find_lca(root, src, dest);
  // std::cout << "LCA : " << lca->data << std::endl;
  
  // * 2. Find Path from LCA to src
  std::string lca_to_src = "";
  root_to_node(lca, lca_to_src, src);
  // std::cout << "lca_to_src : " << lca_to_src << std::endl;
  
  // * 3. Find Path from LCA to Dest
  std::string lca_to_dest = "";
  root_to_node(lca, lca_to_dest, dest);
  // std::cout << "lca_to_dest : " << lca_to_dest << std::endl;

  std::string ans(lca_to_src.size(), 'U');
  ans += lca_to_dest;

  return ans;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * 1. Find Path from root to Src
// * 2. Find Path from root to dest
// * TIME COMPLEXITY O(2N) ~ O(N)
// * SPACE COMPLEXITY O(N)
std::string getDirections(TreeNode* root, int src, int dest) {
  // * 1. Find Path from root to src
  std::string lca_to_src = "";
  root_to_node(root, lca_to_src, src);
  // std::cout << "lca_to_src : " << lca_to_src << std::endl;
  
  // * 2. Find Path from root to Dest
  std::string lca_to_dest = "";
  root_to_node(root, lca_to_dest, dest);
  // std::cout << "lca_to_dest : " << lca_to_dest << std::endl;

  // * The LCA Will be point at which both directions changed
  int i = 0;
  while (lca_to_src[i] == lca_to_dest[i])
    i++;

  std::string ans(lca_to_src.size() - i, 'U');
  ans += lca_to_dest.substr(i, lca_to_dest.size());

  return ans;
}

int main(void) {
  // * testcase 1
  // int startValue = 3, destValue = 6;
  // TreeNode *root = new TreeNode(5);
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(2);
  // root->left->left = new TreeNode(3);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(4);

  // * testcase 2
  int startValue = 3, destValue = 6;
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);
  root->left->left->left = new TreeNode(3);
  root->right->right = new TreeNode(2);
  root->right->right->right = new TreeNode(4);

  // * testcase 3
  // int startValue = 2, destValue = 1;
  // TreeNode *root = new TreeNode(2);
  // root->left = new TreeNode(1);

  std::cout << "start: " << startValue << ", dest: " << destValue << std::endl;
  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  // std::string ans = bruteForce(root, startValue, destValue);
  std::string ans = getDirections(root, startValue, destValue);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 35-step-by-step-directions-from-a-bt-node-to-another.cpp -o output && ./output

