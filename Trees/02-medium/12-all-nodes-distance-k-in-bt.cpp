/*
* Leetcode - 863
* All Nodes Distance K in Binary Tree
* Given the root of a binary tree, the value of a target node target, and an integer k, 
* return an array of the values of all nodes that have a distance k from the target node.
*
* You can return the answer in any order.
*
*                   3
*               /       \  
*             5          1
*           /   \       /  \  
*          6     2     0    8
*              /  \     
*             7   4
* Example 1:
* Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
* Output: [7,4,1]

* https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
* https://www.naukri.com/code360/problems/print-nodes-at-distance-k-from-a-given-node_842560
*/

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

  TreeNode(int val)
  {
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

// * Map the parent node of each node in hashmap
void markParents(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*> &parentMap) {
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      TreeNode* parent = q.front();
      q.pop();
      // * Map left node to its parent node
      if (parent->left) {
        parentMap[parent->left] = parent;
        q.push(parent->left);
      }
      
      // * Map right node to its parent node
      if (parent->right) {
        parentMap[parent->right] = parent;
        q.push(parent->right);
      }
    }
  }
}

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  // * 1. Map the parent node of each node in hashmap
  std::unordered_map<TreeNode*, TreeNode*> parentMap;
  markParents(root, parentMap);

  // * For debugging
  // for(auto &it: parentMap) {
  //   std::cout << it.first->data << " -> " << it.second->data << std::endl;
  // }
  
  // * 2. Do any type of traversal on tree 
  // * Visited Map for keeping track of which is we already visited during traversal
  std::unordered_map<TreeNode*, bool> visitedMap;
  int distance = 0;
  std::queue<TreeNode*> q;
  q.push(target);
  visitedMap[target] = true;

  while (!q.empty()) {
    int n = q.size();
    // std::cout << n << std::endl;
    if (distance++ == k)
      break;

    // * Loop over the current level
    while (n--) {
      TreeNode* current = q.front();
      q.pop();

      // * Go to the left if not previously visited
      if(current->left && !visitedMap[current->left]) {
        q.push(current->left);
        visitedMap[current->left] = true;
      }
      
      // * Go to the right if not previously visited
      if(current->right && !visitedMap[current->right]) {
        q.push(current->right);
        visitedMap[current->right] = true;
      }
      
      // * Go to the parent if not previously visited
      if(parentMap[current] && !visitedMap[parentMap[current]]) {
        q.push(parentMap[current]);
        visitedMap[parentMap[current]] = true;
      }
    }
  }

  // * 3. The queue will contain our answer
  std::vector<int> ans;
  while (!q.empty()) {
    ans.push_back(q.front()->data);
    q.pop();
  }

  return ans;
}

int main(void) {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  int k = 2;
  std::vector<int> ans = distanceK(root, root->left, k);
  printArr(ans);

  return 0;
}

// * run the code
// * g++ --std=c++20 12-all-nodes-distance-k-in-bt.cpp -o output && ./output
