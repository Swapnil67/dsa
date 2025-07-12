
/*
* Top View of Binary tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  

* Output: ans = [4, 2, 1, 3, 7]

* https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401
*/

#include <map>
#include <queue>
#include <vector>
#include <iostream>

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

void printArr(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

std::vector<int> topView(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;
  std::map<int, int> nodes;

  // * { vertical, TreeNode* }
  std::queue<std::pair<int, TreeNode*>> q;
  q.push({0, root});

  // * level order traversal
  while (!q.empty()) {
    std::pair<int, TreeNode*> p = q.front();
    q.pop();

    // std::cout << p.first << std::endl;
    if (!nodes.count(p.first)) {
      nodes[p.first] = p.second->data;     // * Add vertical level to map
    }

    if (p.second->left) {
      q.push({p.first - 1, p.second->left});
    }

    if (p.second->right) {
      q.push({p.first + 1, p.second->right});
    }
  }

  for (auto &it : nodes) {
    ans.push_back(it.second);
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

  std::vector<int> ans = topView(root);
  printArr(ans);
}


// * run the code
// * g++ --std=c++17 05-top-view-bt.cpp -o output && ./output
