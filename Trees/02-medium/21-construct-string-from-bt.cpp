/*
* Leetcode - 606
* Construct String from Binary Tree

* Given the root node of a binary tree, your task is to create a string representation of the tree following 
* a specific set of formatting rules. The representation should be based on a preorder traversal of the 
* binary tree and must adhere to the following guidelines:

* Node Representation: Each node in the tree should be represented by its integer value.
* - Parentheses for Children: If a node has at least one child (either left or right), 
* its children should be represented inside parentheses. Specifically:
* - If a node has a left child, the value of the left child should be enclosed in parentheses 
* immediately following the node's value.
* - If a node has a right child, the value of the right child should also be enclosed in parentheses. 
* The parentheses for the right child should follow those of the left child.

* Example 1:
*                 1
*               /   \  
*             2      3
*              \     
*               4    

* Output: "1(2()(4))(3)"

* Example 2:
*                   1
*               /      \  
*             2         3
*           /   \     /  \  
*          4    5    6    7      

* Output: "1(2(4)(5))(3(6)(7))"

* Example 3:
*                 1
*               /      
*             2      

* Output: "1(2)"

* Example 4:
*                1
*                  \      
*                   2      

* Output: "1()(2)"

* https://leetcode.com/problems/construct-string-from-binary-tree/description/
*/

#include <vector>
#include <iostream>

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

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

std::string tree2str(TreeNode* root) {
  std::string ans = "";
  if (!root)
    return ans;
  
  ans += std::to_string(root->data);

  std::string left_str = tree2str(root->left);
  std::string right_str = tree2str(root->right);

  // * no children
  if (!root->left && !root->right) {
    return ans;   // * single node in tree    
  }

  // * does not have left node
  if (!root->left) {
    return ans + "()" + "(" + right_str + ")";
  }
  
  // * does not have right node
  if (!root->right) {
    return ans + "(" + left_str + ")";
  }

  return ans + "(" + left_str + ")" + "(" + right_str + ")";
}

int main(void) {
  // * testcase 1
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);
  
  // * testcase 2
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  // * testcase 3
  // TreeNode* root = new TreeNode(1);
  // root->right = new TreeNode(2);

  std::string ans = tree2str(root);
  std::cout << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-construct-string-from-bt.cpp -o output && ./output

