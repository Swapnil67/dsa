/*
 * Path In Tree
 * 
 * Example 1    :
 *                  1
 *               /     \  
 *             2        3
 *           /  \     /   \  
 *          4    5   6     7

 * Input        : x = 7
 * Output       : [1, 3, 7]
 * 
 * https://www.naukri.com/code360/problems/path-in-a-tree_3843990
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

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

bool dfs(TreeNode *root, int &x, vector<int> &ans) {
  if (!root)
    return false;

  ans.push_back(root->data);

  if (root->data == x)
    return true;

  if (dfs(root->left, x, ans) || dfs(root->right, x, ans)) {
    return true;
  }

  ans.pop_back();
  return false;
}

vector<int> pathInATree(TreeNode *root, int x) {
  vector<int> ans;
  if (!root) 
		return ans;

	dfs(root, x, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  int x = 7;

  vector<int> ans =pathInATree(root, 7);
  std::cout << "Path: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-path-in-tree.cpp -o output && ./output















