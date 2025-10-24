
/*
* Bottom View of Binary tree

* Example 1:
* Input: 
*
*                  1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  
*             /  \ 
*            8    9

* Output: ans = [4, 8, 6, 9, 7]

* https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
* https://www.naukri.com/code360/problems/bottom-view-of-binary-tree_893110
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

// * Vertical Order Traversal
std::vector<int> bottomView(TreeNode *root) {
  std::vector<int> ans;
  if (!root)
    return ans;

  std::map<int, int> mp;
  std::queue<std::pair<int, TreeNode *>> q;
  q.push({0, root});

  // * Classic BFS
  while (!q.empty()) {
    int n = q.size();

    std::pair<int, TreeNode*> p = q.front();
    q.pop();

    int cur_ver = p.first;
    TreeNode *cur_node = p.second;

    mp[cur_ver] = cur_node->data;

    if (cur_node->left) {
      q.push({cur_ver - 1, cur_node->left});
    }

    if (cur_node->right) {
      q.push({cur_ver + 1, cur_node->right});
    }
  }

  for (auto &it : mp) {
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

  root->left->right->left = new TreeNode(8);
  root->left->right->right = new TreeNode(9);

  std::vector<int> ans = bottomView(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 06-bottom-view-bt.cpp -o output && ./output
