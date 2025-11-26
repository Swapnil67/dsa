/*
* Leetcode - 1530
* Number of Good Leaf Nodes Pairs

* You are given the root of a binary tree and an integer distance. 
* A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest 
* path between them is less than or equal to distance.

* Return the number of good leaf node pairs in the tree.

* Example 1:
* Input: 
*                  1        
*               /     \     
*             2        3

* Input       : root = [1,2,3,null,4], distance = 3
* Output      : 1
* Explanation : The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. 
*               This is the only good pair.

* Example 2:
* Input: 
*                  1        
*               /     \     
*             2        3
*           /   \    /   \   
*          4    5   6     7

* Input       : root = [1,2,3,4,5,6,7], distance = 3
* Output      : 2
* Explanation : The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not
*               good because the length of ther shortest path between them is 4.


* https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
*/

// ! Meta, Amazon, tiktok

// ! convert tree to UDG (Undirected Graph)

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

// * Builds a Adj list from graph
void makeGraph(TreeNode *root, TreeNode *prev,
               std::unordered_set<TreeNode *> &leaves,
               std::unordered_map<TreeNode *, std::vector<TreeNode *>> &adj)
{
  if (!root)
    return;

  // * Save the leaf node to set
  if (!root->left && !root->right) {
    leaves.insert(root);
  }

  if (prev) {
    adj[root].push_back(prev);
    adj[prev].push_back(root);
  }

  makeGraph(root->left, root, leaves, adj);
  makeGraph(root->right, root, leaves, adj);
}

// * BFS Traversal
int bfs(int d, TreeNode *root,
        std::unordered_set<TreeNode*> &leaves,
        std::unordered_map<TreeNode *, std::vector<TreeNode *>> &adj)
{
  int good_pairs = 0;
  if (!root)
    return good_pairs;

  std::unordered_set<TreeNode *> visited;
  visited.insert(root);

  std::queue<TreeNode *> q;
  q.push(root);

  int level = 0;
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
        TreeNode* node = q.front();
        q.pop();

        // * Found a leaf node
        if (leaves.count(node) && node != root) {
            good_pairs++;
        }

        // * Visit neighbours
        for (auto& ngbr : adj[node]) {
            if (!visited.count(ngbr)) {
                // * Mark node as visited
                visited.insert(ngbr);
                q.push(ngbr);
            }
        }
    }

    level += 1;

    if (level > d)
        break;
  }

  return good_pairs;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * convert tree to UDG (Undirected Graph)
// * Find shortest distance b/w all leaf nodes (BFS)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int countPairs(TreeNode* root, int distance) {
  int good_pairs = 0;
  if (!root)
    return good_pairs;

  // * 1. convert tree to a UDG
  std::unordered_map<TreeNode *, std::vector<TreeNode *>> adj;
  std::unordered_set<TreeNode *> leaves;
  makeGraph(root, NULL, leaves, adj);

  // * 2. Do BFS from leaf to other leaf nodes
  for (auto &leaf : leaves) {
    // std::cout << leaf->data << std::endl;
    // * BFS to another leaf node
    int cur_pairs = bfs(distance, leaf, leaves, adj);
    good_pairs += cur_pairs;
  }

  return good_pairs / 2;
}

int main(void) {
  // * testcase 1
  // int distance = 3;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->right = new TreeNode(4);

  // * testcase 1
  int distance = 3;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  int ans = countPairs(root, distance);
  std::cout << "Number of Good Leaf Nodes Pairs: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 34-no-of-good-leaf-nodes-pairs.cpp -o output && ./output

