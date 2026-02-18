/*
* Leetcode - 145
* Binary Tree Prostorder Traversal

*
* Example 1:
*                  1
*               /     \  
*             2        3
*           /  \     /   \  
*          4    5   6     7

* Output: [4, 5, 2, 6, 7, 3, 1]

* https://leetcode.com/problems/binary-tree-postorder-traversal/description/
* https://www.naukri.com/code360/problems/postorder-traversal_2035933
* https://www.geeksforgeeks.org/problems/postorder-traversal/1
*/

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct TreeNode TreeNode;

struct TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
  }
};

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

// ! Left | Right | Root


// * Using Recursion
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
// * SPACE COMPLEXITY Best Case  = O(logn) ~ O(height of tree) * Size of Activation Record
void postOrderDFS(TreeNode* node, vector<int> &ans) {
  if (node == nullptr)
    return;

  // cout << node->data << endl;
  postOrderDFS(node->left, ans);
  postOrderDFS(node->right, ans);
  ans.push_back(node->data);
}

// * Just reverse of Pre Order Traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY 
// *    O(n) - stack
// *    O(n) - output array
void postOrderIterative(TreeNode *root, vector<int> &ans) {
 if (!root)
    return;

  stack<TreeNode *> st;
  st.push(root);
  while (st.size()) {
    TreeNode* topNode = st.top();
    st.pop();
    ans.push_back(topNode->data);

    if (topNode->left)
      st.push(topNode->left);
      
    if (topNode->right)
      st.push(topNode->right);
  }

  reverse(ans.begin(), ans.end());
}


int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<int> ans;
  // postOrderDFS(root, ans);
  postOrderIterative(root, ans);

  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-post-order-traversal.cpp -o output && ./output
