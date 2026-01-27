/*
 * Leetcode - 429 
 * N-ary Tree Level Order Traversal
 * 
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal, each group of children 
 * is separated by the null value (See examples).
 * 
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

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

class Node {
public:
  int val;
  vector<Node*> children;

  Node(int v) {
    val = v;
  }
};

vector<vector<int>> levelOrder(Node *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    vector<int> level;
    while (n--) {
      Node *node = q.front();
      q.pop();

      level.push_back(node->val);
      for (int i = 0; i < node->children.size(); ++i) {
        q.push(node->children[i]);
      }
    }

    ans.push_back(level);
  }
  return ans;
}

int main(void) {
  // * Do this on leetcode
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 59-n-ary-tree-level-order-traversal.cpp -o output && ./output
