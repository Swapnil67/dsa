
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
* https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/
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
    int curVertical = el.second.first;
    int curLevel = el.second.second;
    nodes[curVertical][curLevel].insert(el.first->data);

    int newLevel = el.second.second + 1;
    if (el.first->left) {
      int newVertical = curVertical - 1;
      todo.push({el.first->left, {newVertical, newLevel}});
    }

    if (el.first->right) {
      int newVertical = curVertical + 1;
      todo.push({el.first->right, {newVertical, newLevel}});
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


  vector<vector<int>> ans = verticalOrderTraversal(root);
  for (auto &p : ans) {
    printArr(p);
  }
}


// * run the code
// * g++ --std=c++17 04-vertical-order-traversal.cpp -o output && ./output
