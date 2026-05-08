/*
* Leetcode - 2196
* Create Binary Tree From Descriptions

* You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti]
* indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

* - If isLefti == 1, then childi is the left child of parenti.
* - If isLefti == 0, then childi is the right child of parenti.

* Construct the binary tree described by descriptions and return its root.
! The test cases will be generated such that the binary tree is valid.

* Example 1:
*                  50
*               /     \  
*             20      80
*           /   \     /   
*          15   17   19      

* Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
* Output: [50,20,80,15,17,19]

* https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
*/

#include <map>
#include <unordered_set>
#include "../common.hpp"
 
using namespace std;


// * ------------------------- APPROACH: Optimal Approach -------------------------
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
  map<int, TreeNode *> hash;
  unordered_set<int> children; // * They can never be root of the tree

  for(vector<int> &vec: descriptions) {
    int parent_val = vec[0];
    int child_val = vec[1];
    bool is_left = vec[2];

    // * Check if parent already exists
    if (hash.find(parent_val) == hash.end()) {
      hash[parent_val] = new TreeNode(parent_val);
    }

    // * Check if child already exists
    if (hash.find(child_val) == hash.end()) {
      hash[child_val] = new TreeNode(child_val);
    }

    if (is_left == 1) {
      hash[parent_val]->left = hash[child_val];
    } else {
      hash[parent_val]->right = hash[child_val];
    }

    children.insert(child_val);
  }

  // * Find the root
  for(vector<int> &vec: descriptions) {
    const int parent = vec[0];
    if (!children.count(parent))
      return hash[parent];
  }

  return nullptr;
}

int main(void) {
  // * testcase 1
  vector<vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};

  // * testcase 2
  // vector<vector<int>> descriptions = {{85, 82, 1}, {74, 85, 1}, {39, 70, 0}, {82, 38, 1}, {74, 39, 0}, {39, 13, 1}};

  cout << "----- Tree Description ------" << endl;
  for (auto &arr : descriptions)
    printArr(arr);

  cout << "\n----- Binary Tree ------" << endl;
  TreeNode* root = createBinaryTree(descriptions);
  levelOrderTraversal(root);

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-create-bt-from-descriptions.cpp -o output && ./output

