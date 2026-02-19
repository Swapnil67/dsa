/*
 * Leetcode - 103
 * Binary Tree Zigzag Level Order Traversal
 * 
 * Example 1:
 * Input  : root = [3,9,20,null,null,15,7]
 * Output : [[3],[20,9],[15,7]]
 * 
 * Example 2:
 * Input  : root = [1]
 * Output : [[1]]
 * 
 * https://www.naukri.com/code360/problems/zig-zag-traversal_1062662
*/

// ! Amazon, Flipkart

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
void printArr(vector<T> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();
    // * traverse the whole level
    while (n--) {
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


vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == nullptr)
      return ans;

  // * 0 = L -> R
  // * 1 = R -> L
  int flag = 0;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> cur;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      cur.push_back(node->data);
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    
    // * Reverse the cur level
    if(flag == 1) {
      reverse(cur.begin(), cur.end());
    }
    ans.push_back(cur);
    flag = !flag;
  }

  return ans;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> zigzagLevelOrder2(TreeNode *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  queue<TreeNode *> q;
  q.push(root);

  int reverse = 1;
  while (!q.empty()) {
    int n = q.size();
    vector<int> cur(n);

    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();
      
      int idx = (reverse) ? i : (n - 1 - i);
      cur[idx] = node->data;

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    reverse = !reverse; // * toggle reverse 
    ans.push_back(cur);
  }

  return ans;
}

int main() {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);

  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);

  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);

  // * testcase 2
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);

  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  cout << "Input Tree:" << endl;
  levelOrderTraversal(root);

  // vector<vector<int>> ans = zigzagLevelOrder(root);
  vector<vector<int>> ans = zigzagLevelOrder2(root);
  cout << "Zigzag Level Order Traversal: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * run the code
// * g++ --std=c++20 02-zig-zag-Level-order.cpp -o output && ./output
