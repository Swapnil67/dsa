/*
* Leetcode - 701
* Insert into a Binary Search Tree
* You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
* Return the root node of the BST after the insertion. 
* It is guaranteed that the new value does not exist in the original BST.

* Notice that there may exist multiple valid ways for the insertion, 
* as long as the tree remains a BST after insertion. You can return any of them.

*
*                  4
*               /     \  
*             2        7
*           /  \     /   \  
*          1    3   x     x

* Example 1:
* Input: root = [4, 2, 7, 1, 3], val = 5
*
*                  4
*               /     \  
*             2        7
*           /  \     /   \  
*          1    3   5     x
* Output: [4, 2, 7, 1, 3, 5]

* https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
* https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913
* https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
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

// * TIME COMPLEXITY  O(logn) - (Height of tree)
// * SPACE COMPLEXITY O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
  TreeNode *new_node = new TreeNode(val);

  // * 'new_node' as root
  if (!root)
    return new_node;

  TreeNode *ans = root;
  while (root) {
    if (val > root->data) {
      // * If nothing to right then insert 'new_node' at right ans break
      if (root->right == nullptr) {
        root->right = new_node; 
        break;
      }
      root = root->right;
    } else {
      // * If nothing to left then insert 'new_node' at left and break
      if (root->left == nullptr) {
        root->left = new_node; 
        break;
      }
      root = root->left;
    }
  }
  
  return ans;
}

int main(void) {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  // inOrder(root);
  
  int val = 5;
  
  TreeNode *ans = insertIntoBST(root, val);
  inOrder(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-insert-in-bst.cpp -o output && ./output
