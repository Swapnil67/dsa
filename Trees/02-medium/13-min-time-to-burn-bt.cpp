/*
  * Leetcode - 2385
  * Amount of Time for Binary Tree to Be Infected
  * You are given the root of a binary tree with unique values, and an integer start. At minute 0, 
  * an infection starts from the node with value start.
  * 
  * Each minute, a node becomes infected if:
  * - The node is currently uninfected.
  * - The node is adjacent to an infected node.
  * 
  * Return the number of minutes needed for the entire tree to be infected.

  *
  *                    1
  *               /        \  
  *             5           3
  *           /   \       /  \  
  *          x     4     10    6
  *              /  \     
  *             9    2
  * Example 1:
  * Input: root = [1,5,3,null,4,10,6,9,2], start = 3
  * Output: 4
  * 
  * https://www.geeksforgeeks.org/problems/burning-tree/1
  * https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

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

void markParents(TreeNode *root,
                 std::unordered_map<TreeNode *, TreeNode *> &parent_map,
                 TreeNode *&startNode, int start)
{
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      TreeNode* cur = q.front();
      // * Save the start node to this reference variable
      if (cur->data == start)
        startNode = cur;
      q.pop();

      // * If 'cur' has left node then make 'cur' node as parent of the 'cur->left' node
      if (cur->left) {
        parent_map[cur->left] = cur;
        q.push(cur->left);
      }
      
      // * If 'cur' has right node then make 'cur' node as parent of the 'cur->right' node
      if (cur->right) {
        parent_map[cur->right] = cur;
        q.push(cur->right);
      }
    }
  }
}

int amountOfTime(TreeNode* root, int start) {
  // * For counting burned time
  int time = 0;

  if (!root)
    return time;

  // * 1. Map the parent node of each node in hashmap
  TreeNode *startNode = nullptr;
  std::unordered_map<TreeNode *, TreeNode *> parent_map;
  markParents(root, parent_map, startNode, start);
  if (!startNode)
    return time;

  // * For debugging
  // for(auto &it: parent_map) {
  //   std::cout << it.first->data << " -> " << it.second->data << std::endl;
  // }

  // * Queue for BFS
  std::queue<TreeNode *> q;
  q.push(startNode); // * Push the initial starting node to queue

  std::unordered_map<TreeNode *, bool> visited_map;
  visited_map[startNode] = true; // * Put the starting node in visited_map


  while (!q.empty()) {
    int n = q.size();
    int burned = 0;
    while (n--) {
      TreeNode* cur = q.front();
      q.pop();
      
      // * Go to the left if not previously visited
      if (cur->left && !visited_map[cur->left]) {
        burned = 1;
        visited_map[cur->left] = true;
        q.push(cur->left);
      }
      
      // * Go to the right if not previously visited
      if (cur->right && !visited_map[cur->right]) {
        burned = 1;
        visited_map[cur->right] = true;
        q.push(cur->right);
      }
      
      // * Go to the parent if not previously visited
      if (parent_map[cur] && !visited_map[parent_map[cur]]) {
        burned = 1;
        visited_map[parent_map[cur]] = true;
        q.push(parent_map[cur]);
      }
    }
    if (burned)
      time++;
  }

  return time;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(5);
  root->right = new TreeNode(3);
  
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(9);
  root->left->right->right = new TreeNode(2);

  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(6);

  int start =  3;

  int time = amountOfTime(root, start);
  std::cout << "Amount of Time for Binary Tree to Be Infected " << time << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++20 13-min-time-to-burn-bt.cpp -o output && ./output
