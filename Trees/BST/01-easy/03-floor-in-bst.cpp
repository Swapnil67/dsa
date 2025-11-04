/*
* Leetcode - 700
* Floor in a Binary Search Tree
* Floor of an integer is the closest integer greater than or equal to a given number.

*
*                  6
*               /     \  
*             2        13
*           /  \     /   \  
*          1    4   9     15
*                        /
*                       14

* Example 1:
* Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], val = 10
* Output: 9

* Example 2:
* Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], val = 16
* Output: 15

* https://www.naukri.com/code360/problems/floor-from-bst_920457
* https://www.geeksforgeeks.org/problems/floor-in-bst/1
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
int findFloor(TreeNode* root, int val) {
  int ans = -1;

  while (root) {
    if (root->data == val)
      return val;

    if (root->data < val)
      ans = root->data;

    root = (root->data < val) ? root->right : root->left;
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

  std::cout << "floor of 3: " << findFloor(root, 3) << std::endl;
  std::cout << "floor of 10: " << findFloor(root, 10) << std::endl;
  std::cout << "floor of 16: " << findFloor(root, 16) << std::endl;
  std::cout << "floor of 8: " << findFloor(root, 8) << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-floor-in-bst.cpp -o output && ./output
