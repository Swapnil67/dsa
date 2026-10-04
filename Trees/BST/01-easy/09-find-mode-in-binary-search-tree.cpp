/*
* Leetcode - 501
* Find Mode in Binary Search Tree
*
* Given the root of a binary search tree (BST) with duplicates, return all the mode(s) 
* (i.e., the most frequently occurred element) in it.

* If the tree has more than one mode, return them in any order.
* Assume a BST is defined as follows:
* - The left subtree of a node contains only nodes with keys less than or equal to the node's key.
* - The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
* - Both the left and right subtrees must also be binary search trees.
*
*                  4
*               /     \  
*             2        7
*           /  \     /   \  
*          1    3   x     x

* Example 1:
* Input: root = [4,2,7,1,3], val = 2
* Output: [2,1,3]

* Example 2:
* Input: root = [4,2,7,1,3], val = 5
* Output: []

* https://leetcode.com/problems/search-in-a-binary-search-tree/
* https://www.naukri.com/code360/problems/search-in-bst_1402878
*/

// ! Google

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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
void dfs(TreeNode *root, int &curNum, int &curFreq, int &maxFreq,
         vector<int> &ans) {
  if (!root)
    return;
  dfs(root->left, curNum, curFreq, maxFreq, ans);

  if (root->data == curNum) {
    curFreq += 1;
  }
  else {
    curNum = root->data;
    curFreq = 1;
  }

  // * new possible result
  if (curFreq > maxFreq) {
    maxFreq = curFreq;
    ans.clear();
  }

  if (curFreq == maxFreq) { // * same freq val
    ans.push_back(root->data);
  }

  dfs(root->right, curNum, curFreq, maxFreq, ans);
}

int main(void) {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-find-mode-in-binary-search-tree.cpp -o output && ./output
