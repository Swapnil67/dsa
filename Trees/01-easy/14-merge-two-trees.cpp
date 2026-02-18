/*
* Leetcode - 617
* Merge Two Binary Trees
*
* Example:
* Input: 
* rootA = [1,3,2,5]
*
*                  1
*               /     \  
*             3        2
*           /
*          5 
* rootB = [2,1,3,null,4,null,7]
*
*                  2
*               /     \  
*             1        3
*              \        \
*               4        7

* Output: [3,4,5,5,4,null,7]
*
*                  3
*               /     \  
*             4        5
*           /  \        \
*          5    4        7

* https://leetcode.com/problems/merge-two-binary-trees/description/
* https://www.naukri.com/code360/problems/fasdf_1263729
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

void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> level;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      cout << node->data << " ";
    }
    cout << endl;
  }
}

// * Depth First Search (Creating New Tree)
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
  if (!root1 && !root2)
    return nullptr;

  int val1 = root1 ? root1->data : 0;
  int val2 = root2 ? root2->data : 0;

  TreeNode *ans = new TreeNode(val1 + val2);

  ans->left = mergeTrees(
      (root1 ? root1->left : NULL),
      (root2 ? root2->left : NULL));

  ans->right = mergeTrees(
      (root1 ? root1->right : NULL),
      (root2 ? root2->right : NULL));

  return ans;
}

// * Depth First Search (In Place)
TreeNode *mergeTrees2(TreeNode *p, TreeNode *q) {
  if (!p)
    return q;
    
  if (!q)
    return p;

  p->data += q->data;
  p->left = mergeTrees2(p->left, q->left);
  p->right = mergeTrees2(p->right, q->right);
  return p;
}

int main(void) {
  TreeNode *rootA = new TreeNode(1);
  rootA->left = new TreeNode(3);
  rootA->right = new TreeNode(2);
  rootA->left->left = new TreeNode(5);
   
  TreeNode *rootB = new TreeNode(2);
  rootB->left = new TreeNode(1);
  rootB->right = new TreeNode(3);
  rootB->left->right = new TreeNode(4);
  rootB->right->right = new TreeNode(7);

  cout << "Root A: " << endl;
  levelOrder(rootA);
  cout << "Root B: " << endl;
  levelOrder(rootB);
  
  cout << "Merged Root: " << endl;
  TreeNode *ans = mergeTrees(rootA, rootB);
  levelOrder(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-merge-two-trees.cpp -o output && ./output

