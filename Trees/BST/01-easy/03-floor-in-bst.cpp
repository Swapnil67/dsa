/*
* Leetcode - 700
* Ceil in a Binary Search Tree
* Ceil of an integer is the closest integer greater than or equal to a given number.

*
*                  6
*               /     \  
*             2        13
*           /  \     /   \  
*          1    4   9     15
*                        /
*                       14

* Example 1:
* Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], val = 8
* Output: 9

* Example 2:
* Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], val = 16
* Output: -1

* https://www.naukri.com/code360/problems/floor-from-bst_920457
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

// * TIME COMPLEXITY  O(logn)
// * SPACE COMPLEXITY O(1)
int findCeil(TreeNode* root, int val) {
  int ans = -1;
  while (root) {
    if (root->data == val)
      return val;

    // * if cur node is > val then this is possible ceil
    if (root && root->data > val)
      ans = root->data;

    root = (val > root->data) ? root->right : root->left;

  }
  return ans;
}

int main(void) {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(13);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(15);
  
  root->right->right->left = new TreeNode(14);

  std::cout << "Ceil of 2: " << findCeil(root, 2) << std::endl;
  std::cout << "Ceil of 5: " << findCeil(root, 5) << std::endl;
  std::cout << "Ceil of 8: " << findCeil(root, 8) << std::endl;
  std::cout << "Ceil of 16: " << findCeil(root, 16) << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-ceil-in-bst.cpp -o output && ./output
