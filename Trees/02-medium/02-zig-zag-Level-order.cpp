#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

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
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
  std::vector<std::vector<int>> ans;
  if (root == nullptr)
      return ans;

  // * 0 = L -> R
  // * 1 = R -> L
  int flag = 0;

  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> cur;
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
      std::reverse(cur.begin(), cur.end());
    }
    ans.push_back(cur);
    flag = !flag;
  }

  return ans;
}

std::vector<std::vector<int>> zigzagLevelOrder2(TreeNode *root) {
  std::vector<std::vector<int>> ans;
  if (root == nullptr)
      return ans;

  // * 1 = L -> R
  // * 0 = R -> L
  int leftToRight = 1;

  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {

    int n = q.size();
    std::vector<int> cur(n);

    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();
      
      int idx = (leftToRight) ? i : (n - 1 - i);
      // std::cout << node->data << " => " << idx << std::endl;
      cur[idx] = node->data;

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }

    // std::cout << std::endl;

    leftToRight = !leftToRight;
    ans.push_back(cur);
  }

  return ans;
}

int main() {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // std::vector<std::vector<int>> ans = zigzagLevelOrder(root);
  std::vector<std::vector<int>> ans = zigzagLevelOrder2(root);
  for(auto it: ans) {
    printArr(it);
  }

}

// * run the code
// * g++ --std=c++17 02-zig-zag-Level-order.cpp -o output && ./output
