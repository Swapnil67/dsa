
/*
* Vertical Traversal of tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  

* Output: ans = [4, 2, 1, 5, 6, 3, 7]

* https://www.naukri.com/code360/problems/vertical-order-traversal_920533
* https://leetcode.com/problems/binary-tree-vertical-order-traversal/
* https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

#include <set>
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

// * Using Level Order Traversal
vector<vector<int>> verticalOrderTraversal(TreeNode *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  // * vertical | level | { nodes }
  map<int, map<int, multiset<int>>> nodes;
  // * node | { vertical, level }
  queue<pair<TreeNode *, pair<int, int>>> todo;
  todo.push({root, {0, 0}});

  while (!todo.empty()) {
    pair<TreeNode *, pair<int, int>> el = todo.front();
    todo.pop();

    TreeNode* cur_node = el.first;
    int cur_ver = el.second.first;      // * current vertical
    int cur_level = el.second.second;   // * current level
    
    nodes[cur_ver][cur_level].insert(el.first->data);

    int new_level = cur_level + 1; // * new level

    // * push left node if exists
    if (cur_node->left) {
      todo.push({el.first->left, {cur_ver - 1, new_level}});
    }

    // * push right node if exists
    if (cur_node->right) {
      todo.push({el.first->right, {cur_ver + 1, new_level}});
    }
  }

  for (auto &p : nodes) {
    vector<int> col;
    for (auto &q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }

  return ans;
}

int main() {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  // root->left->left->right = new TreeNode(9);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::vector<std::vector<int>> ans = verticalOrderTraversal(root);
  for (auto &p : ans)
    printArr(p);

  return 0;
}


// * run the code
// * g++ --std=c++17 04-vertical-order-traversal.cpp -o output && ./output
