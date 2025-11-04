/*
* Closest Binary Search Tree Value
*
* https://www.naukri.com/code360/problems/closest-element-in-bst_920449
* https://www.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
*/

// ! Adobe

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
