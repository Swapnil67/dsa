/*
* Leetcode - 230
* Kth Smallest Element in a BST
* Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all 
* the values of the nodes in the tree.

*
*                  5
*               /     \  
*             3        6
*           /  \     /   \  
*          2    4   x     7

* Example 1:
* Input: root = [5,3,6,2,4,null,7], k = 3
* Output: 4

* Example 2:
* Input: root = [5,3,6,2,4,null,7], k = 2
* Output: 3

* https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
* https://www.naukri.com/code360/problems/delete-node-in-bst_920381
*/

#include <stack>
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

void sizeOfTree(TreeNode *root, int &c) {
  if (!root)
    return;
  sizeOfTree(root->left, c);
  c++;
  sizeOfTree(root->right, c);
}

void inOrder(TreeNode *root, std::vector<int> &vec) {
  if (!root)
    return;
  inOrder(root->left, vec);
  vec.push_back(root->data);
  // std::cout << root->data << std::endl;
  inOrder(root->right, vec);
}


// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(TreeNode* root, int k) {
  std::vector<int> treeNodesVec;
  inOrder(root, treeNodesVec);
  // printArr(treeNodesVec);
  return treeNodesVec[k - 1];
}

int inOrderIterative(TreeNode *root, int k) {
  int n = 0;
  TreeNode *cur = root;
  std::stack<TreeNode *> st;
  while (cur || st.size()) {
    // * keep going to left
    while (cur) {
      st.push(cur);
      cur = cur->left;
    }

    // * Process this element
    cur = st.top();
    st.pop();
    n += 1;
    if (n == k)
      return cur->data;

    // * Go to the right
    cur = cur->right;
  }

  return -1;
}

// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
int kthSmallest(TreeNode* root, int k) {
  return inOrderIterative(root, k);
}

// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
int kthLargest(TreeNode* root, int k) {
  int size = 0;
  sizeOfTree(root, size);
  std::cout << size << std::endl;
  return inOrderIterative(root, (size - k));
}

int main(void) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  root->right->right = new TreeNode(7);

  // int k = 3;
  int k = 2;
  
  // int ans = bruteForce(root, k);
  int ans = kthSmallest(root, k);
  std::cout << "kth smallest element is " << ans << std::endl;
  ans = kthLargest(root, k);
  std::cout << "kth largest element is " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-kth-smallest-ele-in-bst.cpp -o output && ./output
