/*
* Leetcode - 450
* Delete Node in a BST
* Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
* Return the root node reference (possibly updated) of the BST.

* Basically, the deletion can be divided into two stages:
* 1. Search for a node to remove.
* 2. If the node is found, delete the node.

* Example 1:
*                  5
*               /     \  
*             3        6
*           /  \     /   \  
*          2    4   x     7
* Input: root = [5, 3, 6, 2, 4, null, 7], key = 3
*
*                  5
*               /     \  
*             2        6
*              \        \  
*               4        7
* Output: [4, 2, 7, 1, 3, 5]

* https://leetcode.com/problems/delete-node-in-a-bst/description/
* https://www.naukri.com/code360/problems/delete-node-in-bst_920381
* https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1
*/

#include <vector>
#include <iostream>

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
}

void inOrder(TreeNode *root) {
  if (!root)
    return;
  inOrder(root->left);
  std::cout << root->data << std::endl;
  inOrder(root->right);
}

// * To find the rightmost child of node
TreeNode* getLastRightChild(TreeNode* root) {
  if (root->right == nullptr)
    return root;
  return getLastRightChild(root->right);
}

// * Reconcile The Deleted Node
TreeNode* helper(TreeNode* node) {
  if (!node->left)
    return node->right;
  else if (!node->right)
    return node->left;

  TreeNode *rightChild = node->right;
  TreeNode *lastRight = getLastRightChild(node->left);
  lastRight->right = rightChild;
  return node->left;
}

// * Take the right child of del_node and attact it to the right most child in del_node->left tree
// * and finally attach del_node->left to its parent

// * TIME COMPLEXITY  O(logn) - (Height of tree)
// * SPACE COMPLEXITY O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
  if (!root)
    return root;

  // * Trying to remove root node
  if (root->data == key) {
    return helper(root);
  }

  // * Save this for returning
  TreeNode *dummy = root;
  while (root) {
    if (root->data > key) {
      if(root->left && root->left->data == key) {
        root->left = helper(root->left);  // * reconcile tree
        break;
      } else {
        root = root->left;
      }
    } else {
      if(root->right && root->right->data == key) {
        root->right = helper(root->right);  // * reconcile tree
        break;
      } else {
        root = root->right;
      }
    }
  }

  return dummy;
}

int main(void) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  root->right->right = new TreeNode(7);

  // inOrder(root);
  
  int key = 3;
  // int key = 5;
  
  TreeNode *ans = deleteNode(root, key);
  inOrder(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-delete-in-bst.cpp -o output && ./output
