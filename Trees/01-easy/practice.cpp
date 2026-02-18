#include <stack>
#include <queue>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

// * 01A - In Order DFS
// void inOrderDFS(TreeNode *root, vector<int> &ans) {
// TODO
// }

// * 01B - In Order Iterative
// void inOrderIterative(TreeNode *root, vector<int> &ans) {
// TODO
// }

// * 02A - Pre Order Recursive DFS
// void preOrderDFS(TreeNode *root, vector<int> &ans) {
// TODO
// }

// * 02B - Pre Order Iterative
// void preOrderIterative(TreeNode *root, vector<int> &ans) {
// TODO
// }

// * 03A - Post Order Recursive DFS
// void postOrderDFS(TreeNode *root, vector<int> &ans) {
// TODO
// }

// * 03B - Post Order Iterative
// void postOrderIterative(TreeNode *root, vector<int> &ans) {
// TODO
// }

// * 04 - All 3 traversals
// void threeTraversal(TreeNode *root,
//                     vector<int> &preOrder,
//                     vector<int> &inOrder,
//                     vector<int> &postOrder)
// {
// TODO
// }

// * 05A - Maximum Depth of Binary Tree (DFS)
// int maxDepthDFS(TreeNode *root) {
// TODO
// }

// * 05B - Maximum Depth of Binary Tree (BFS)
// int maxDepthBFS(TreeNode *root) {
// TODO
// }

// * 06A - Minimum Depth of Binary Tree (DFS)
// int minDepthDFS(TreeNode *root) {
// TODO
// }

// * 06B - Minimum Depth of Binary Tree (BFS)
// int minDepthBFS(TreeNode *root) {
// TODO
// }

// * 07 - Balanced Binary Tree
// int isBalanced(TreeNode *root) {
// TODO
// }

// * 08 - Diameter of Binary Tree
// int diameterOfBinaryTree(TreeNode *root, int &diameter) {
// TODO  
// }
 
// * 09 - Same Tree
// bool isSameTree(TreeNode* p, TreeNode* q) {
// TODO
// }

// * 10 - Symmetric Tree
// bool isSymmetric(TreeNode* root) {
// TODO
// } 

// * 11 - Binary Tree Paths
// vector<string> rootToNode(TreeNode* root) {
// TODO
// }

// * 12 - Count Complete Tree Nodes
// int countNodes(TreeNode* root) {
// TODO
// }

// * 13 - Subtree of Another Tree
// bool isSubtree(TreeNode* root, TreeNode* subRoot) {
// TODO
// }

// * 14 - Merge Two Binary Trees
// TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
// TODO
// }

// * 15 - Path Sum
// bool hasPathSum(TreeNode* root, int targetSum) {
// TODO
// }

// * 16 - Cousins in Binary Tree
// bool isCousins(TreeNode* root, int x, int y) {
// TODO
// }

// * 17 - Invert Binary Tree
// TreeNode *invertTreeDFS(TreeNode *root) {
// TODO
// }

// * 18 - Path In Tree
// vector<int> pathInATree(TreeNode *root, int x) {
// TODO
// }

// * 21 - N-ary Tree Postorder Traversal
// vector<int> postorder(Node *root) {
// TODO
// }

// * 20 - N-ary Tree Preorder Traversal
// vector<int> preorder(Node *root) {
// TODO
// }

// * 21 - Leaf Similar trees
// bool leafSimilar(TreeNode *root1, TreeNode *root2) {
// TODO
// }

// * 22 - Evaluate Boolean Binary Tree
// bool evaluateTree(TreeNode* root) {
// TODO
// }

// * ---------------------------------------------------------------------------------------

int main(void) {
  return 0;
}

// * run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
