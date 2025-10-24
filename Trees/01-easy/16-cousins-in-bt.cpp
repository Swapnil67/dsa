/*
* Leetcode - 993
* Cousins in Binary Tree

* Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y
* return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

* Two nodes of a binary tree are cousins if they have the same depth with different parents.

* Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

* Example 1:
* Input: root = [1,2,3,4], x = 4, y = 3
* Output: false

* Example 1:
* Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
* Output: true

* https://leetcode.com/problems/cousins-in-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

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
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
};

void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> level;
    int size = q.size();
    for(int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      std::cout << node->data << " ";
    }
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool isCousins(TreeNode* root, int x, int y) {
  std::unordered_map<int, TreeNode *> parent_map; // * for checking parents of cousins

  // * Classic BFS
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    TreeNode *x_node = nullptr;
    TreeNode *y_node = nullptr;
    while (n--) {
      TreeNode* node = q.front();
      std::cout<<node->data<<" ";
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
    std::cout << std::endl;
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
  // int x = 4, y = 5;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->right = new TreeNode(4);
  // root->right->right = new TreeNode(5);

  // * testcase 2
  int x = 2, y = 3;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);

  std::cout << "x: " << x << ", y: " << y << std::endl;
  std::cout << "Input Tree: ";
  levelOrder(root);

  bool ans = isCousins(root, x, y);
  std::cout << "Is Cousins: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 16-cousins-in-bt.cpp -o output && ./output

