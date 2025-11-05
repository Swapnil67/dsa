/*
* Leetcode - 1008
* Construct Binary Search Tree from Preorder Traversal
*
* Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree),
* construct the tree and return its root.

* It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

* A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than 
* Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

* A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

* Example : 1
* Input   : preorder = [8,5,1,7,10,12]
* Output  : [8,5,10,1,7,null,12]
*
* Example : 2
* Input   : preorder = [1,3]
* Output  : [1,null,3]

* https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
* https://www.naukri.com/code360/problems/construct-bst-from-preorder-traversal_2689307
* https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1
*/

// ! Samsung

#include <vector>
#include <climits>
#include <iostream>

struct TreeNode {
  public:
  int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
      data = v;
      left = nullptr;
      right = nullptr;
    }

    TreeNode(int v, TreeNode* l, TreeNode* r) {
      data = v;
      left = l;
      right = r;
    }

    ~TreeNode() {
      if (left)
        delete left;
      if (right)
        delete right;
    }
};


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

TreeNode* insertIntoBST(TreeNode* root, int val) {
  TreeNode *new_node = new TreeNode(val);
  if (!root)
    return new_node;

  TreeNode *ans = root;
  while (root) {
    if (val > root->data) {
      if (!root->right ) {
        root->right = new_node;
        break;
      } else {
        root = root->right;
      }
    } else {
      if (!root->left) {
        root->left = new_node;
        break;
      } else {
        root = root->left;
      }
    }
  }

  return ans;
}

TreeNode* helper(std::vector<int> &arr, int &i, int bound) {
  if (i == arr.size() || arr[i] > bound)
    return nullptr;

  TreeNode* root = new TreeNode(arr[i++]);
  root->left = helper(arr, i, root->data);
  root->right = helper(arr, i, bound);
  return root;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY  O(n^2)
// * SPACE COMPLEXITY O(1)
TreeNode *bruteForce(std::vector<int> &preorder) {
  int n = preorder.size();
  if (n == 0)
    return nullptr;

  TreeNode *root = new TreeNode(preorder[0]);
  for (int i = 1; i < n; ++i) {
    insertIntoBST(root, preorder[i]);
  }

  return root;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`
// * Sort the preorder and then it will became in-order for BST
// * TIME COMPLEXITY  O(nlogn) + O(n)
// * SPACE COMPLEXITY O(n)
TreeNode *betterApproach(std::vector<int> &preorder) {
// * create tree from `inorder` & `preorder`
// TODO
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------`
// * TIME COMPLEXITY  O(3n) ~ O(n)
// * SPACE COMPLEXITY O(n) [Recursion Space]
TreeNode *bstFromPreorder(std::vector<int> &preorder) {
  int i = 0;
  return helper(preorder, i, INT_MAX);
}


int main(void) {
  std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
  std::cout << "Preorder: ";
  printArr(preorder);

  // bruteForce(root);
  // recoverTree(root);

  // std::vector<int> ans;
  // inorder(root, ans);
  // printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-construct-bst-from-preorder-traversal.cpp -o output && ./output
