#include <queue>
#include <vector>
#include <iostream>

using namespace std;

// typedef struct TreeNode TreeNode;

class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
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

void inOrderTraversal(TreeNode* root) {
  if (!root)
    return;

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int n = q.size();
    // * traverse the whole level
    while (n--)
    {
      TreeNode *node = q.front();
      q.pop();

      cout << node->data << " ";

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    cout << endl;
  }
}
