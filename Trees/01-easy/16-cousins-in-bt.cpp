/*
* Leetcode - 993
* Cousins in Binary Tree
*
* Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y
* return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
*
* Two nodes of a binary tree are cousins if they have the same depth with different parents.
*
* Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
*
* Example 1:
* Input: root = [1,2,3,4], x = 4, y = 3
* Output: false
*
* Example 1:
* Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
* Output: true
*
* https://leetcode.com/problems/cousins-in-binary-tree/description/
* https://www.naukri.com/code360/problems/cousins-of-given-node-in-binary-tree_873363
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct TreeNode TreeNode;

struct TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
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

void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> level;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      cout << node->data << " ";
    }
    cout << endl;
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool isCousins(TreeNode* root, int x, int y) {
  unordered_map<int, TreeNode *> parent_map; // * for checking parents of cousins

  // * Classic BFS
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    TreeNode *x_node = nullptr;
    TreeNode *y_node = nullptr;
    while (n--) {
      TreeNode* node = q.front();
      // cout << node->data << " ";
      q.pop();

      if (node->data == x) {
        x_node = node;
      }

      if (node->data == y) {
        y_node = node;
      }

      // * cousins
      if (x_node && y_node && parent_map[x] != parent_map[y]) {
        return true;
      }

      if (node->left) {
        parent_map[node->left->data] = node;
        q.push(node->left);
      }
      
      if (node->right) {
        parent_map[node->right->data] = node;
        q.push(node->right);
      }
    }
    cout << endl;
  }

  return false;
}

int main(void) {
  // * testcase 1
  // int x = 4, y = 3;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);

  // * testcase 2
  int x = 4, y = 5;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(5);

  // * testcase 2
  // int x = 2, y = 3;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->right = new TreeNode(4);

  cout << "x: " << x << ", y: " << y << endl;
  cout << "Input Tree: ";
  levelOrder(root);

  bool ans = isCousins(root, x, y);
  cout << "Is Cousins: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-cousins-in-bt.cpp -o output && ./output

