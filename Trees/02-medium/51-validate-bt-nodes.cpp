/*
* Leetcode - 1361
* Validate Binary Tree Nodes

* You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i],
* return true if and only if all the given nodes form exactly one valid binary tree.

* If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

* Note that the nodes have no values and that we only use the node numbers in this problem.

* Example 1:
* Input       : n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
*                  0        
*                /   \     
*               1     2
*                   /
*                  3
*
* Output      : true

* Example 2:
* Input       : n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
*                  0        
*                /   \     
*               1     2
*               \    /
*                 3
*
* Output      : false
* 
* https://leetcode.com/problems/validate-binary-tree-nodes/description/
*/

// ! Meta

#include <vector>
#include <iostream>
#include <unordered_map>

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
};


template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

void dfs(int u, int &count,
         vector<bool> &visited,
         unordered_map<int, vector<int>> &adj)
{
  visited[u] = true;
  count += 1;
  for (auto &v: adj[u]) {
    if (!visited[v]) {
      dfs(v, count, visited, adj);
    }
  }
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool validateBinaryTreeNodes(int n, vector<int> &left_child, vector<int> &right_child) {

  // * { child_node: parent_node }
  unordered_map<int, int> child_to_parent_mp;

  // * Adjacency List
  // * { { node1: {left_child, right_child} }, { node2: {left_child, right_child}} }
  unordered_map<int, vector<int>> adj;
  for (int node = 0; node < n; ++node) {
    int left_c = left_child[node]; // * left child
    if (left_c != -1) {
      // * Already has parent (Invalid BT)
      if (child_to_parent_mp.count(left_c)) {
        return false;
      }

      adj[node].push_back(left_c);
      child_to_parent_mp[left_c] = node;
    }
    
    int right_c = right_child[node]; // * right child
    if (right_c != -1) {
      // * Already has parent (Invalid BT)
      if (child_to_parent_mp.count(right_c)) {
        return false;
      }
      adj[node].push_back(right_c);
      child_to_parent_mp[right_c] = node;
    }
  }

  // * Find the root from map
  int root = -1;
  for (int node = 0; node < n; ++node) {
    // * Possible root
    if (!child_to_parent_mp.count(node)) {
      // * Found multiple roots (Invalid BT)
      if (root != -1)
        return false;

      root = node;
    }
  }

  // * No root found (Invalid BT)
  if (root == -1)
    return false;

  // * Normal DFS to count the nodes of bt
  int count = 0;
  vector<bool> visited(n, false);
  dfs(root, count, visited, adj);

  return count == n; // * Valid BT
} 

int main(void) {
  // * testcase 1
  // int n = 4;
  // vector<int> left_child = {1, -1, 3, -1};
  // vector<int> right_child = {2, -1, -1, -1};
  
  // * testcase 2
  int n = 4;
  vector<int> left_child = {1, -1, 3, -1};
  vector<int> right_child = {2, 3, -1, -1};

  bool ans = validateBinaryTreeNodes(n, left_child, right_child);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 51-validate-bt-nodes.cpp -o output && ./output

