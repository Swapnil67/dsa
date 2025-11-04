/*
* Leetcode - 938
* Range Sum of BST
*
* Given the root node of a binary search tree and two integers low and high, 
* return the sum of values of all nodes with a value in the inclusive range [low, high].
*
* Example : 1
* Input   : root = [10,5,15,3,7,null,18], low = 7, high = 15
* Output  : 32
*
* Example : 2
* Input   : root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
* Output  : 23

* https://leetcode.com/problems/range-sum-of-bst/description/
* https://www.naukri.com/code360/problems/range-sum-of-bst_1262280
* https://www.geeksforgeeks.org/problems/range-sum-of-bst/1
*/

// ! Apple, Ola

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

void inorderBrute(TreeNode *root, std::vector<int> &arr) {
  if (!root)
    return;

  inorderBrute(root->left, arr);
  arr.push_back(root->data);
  inorderBrute(root->right, arr);
}

void inorderOptimal(int& ans, TreeNode* root, int& l, int& r) {
  if (!root)
    return;

  inorderOptimal(ans, root->left, l, r);
  if (root->data >= l && root->data <= r) {
    ans += root->data;
  }
  inorderOptimal(ans, root->right, l, r);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(n)
int bruteForce(TreeNode *root, int low, int high) {
  // * 1. create a vector in inorder
  std::vector<int> arr;
  inorderBrute(root, arr);
  // printArr(arr);

  // * 2. Find the sum b/w range
  int ans = 0;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] >= low && arr[i] <= high) {
      ans += arr[i];
    }
  }
  
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
int rangeSumBST(TreeNode *root, int low, int high) {
  int ans = 0;
  inorderOptimal(ans, root, low, high);
  return ans;
}

int main(void) {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);

  root->right->right = new TreeNode(18);


  int low = 7, high = 15;
  std::cout << "low: " << low << ", high: " << high << std::endl;
  int ans = bruteForce(root, low, high);
  // int ans = rangeSumBST(root, low, high);
  std::cout << "Range Sum of BST: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-range-sum-of-bst.cpp -o output && ./output
