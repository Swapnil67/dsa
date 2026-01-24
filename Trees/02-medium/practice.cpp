#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef struct TreeNode TreeNode;

struct TreeNode {
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

// * ------------------------------------------------------------------------

// * 01 - Binary Tree Level Order Traversal
// vector<vector<int>> levelOrder(TreeNode *root) {
// TODO
// }

// * 02 - Binary Tree Zigzag Level Order Traversal
// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
// TODO
// }

// * 03 - Boundary Traversal of tree
// vector<int> boundaryTraversal(TreeNode* root) {
// TODO
// }

// * 04 - Find Leaves of Binary Tree
// vector<vector<int>> findLeaves2(TreeNode *root) {
// TODO
// }

// * 05 - Top View of Binary tree
// vector<int> topView(TreeNode *root) {
// TODO
// }

// * 06 - Bottom View of Binary tree
// vector<int> bottomView(TreeNode *root) {
// TODO
// }

// * 07 - Right View of Binary tree
// vector<int> rightView(TreeNode *root) {
// TODO
// }

// * 08 - left View of Binary tree
// vector<int> leftView(TreeNode *root) {
// TODO
// }

// * 09 - Root to Node
// vector<int> rootToNode(TreeNode *root, int x) {
// TODO
// }

// * 10 - Lowest Common Ancestor of a Binary Tree
// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
// TODO
// }

// * 11 - Maximum Width of Binary Tree
// int widthOfBinaryTree(TreeNode *root) {
// TODO
// }

// * 12 - All Nodes Distance K in Binary Tree
// vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
// TODO
// }

// * 13 - Amount of Time for Binary Tree to Be Infected
// int amountOfTime(TreeNode* root, int start) {
// TODO
// }

// * 14 - Construct Binary Tree from Preorder and Inorder Traversal
// TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
// TODO
// }

// * 15 - Construct Binary Tree from Inorder and Postorder Traversal
// TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder) {
// TODO
// }

// * 16 - Flatten Binary Tree to Linked List
// void flatten(TreeNode* root) {
// TODO
// }

// * 17 - Count Good Nodes in Binary Tree
// int goodNodes(TreeNode* root) {
// TODO
// }

// * 18 - Delete Leaves With a Given Value
// TreeNode* removeLeafNodes(TreeNode* root, int target) {
// TODO
// }

// * 19 - Reverse Odd Levels of Binary Tree
// TreeNode* reverseOddLevelsBFS(TreeNode* root) {
// TODO Tomorrow
// }

// * 20 - Create Binary Tree From Descriptions
// TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
// TODO
// }

// * 21 - Construct String from Binary Tree
// string tree2str(TreeNode *root) {
// TODO
// }

// * 22 - Kth Largest Sum in a Binary Tree
// long long kthLargestLevelSum(TreeNode *root, int k) {
// TODO
// }

// * 23 - Cousins in Binary Tree II
// TreeNode* replaceValueInTree(TreeNode* root) {
// TODO
// }

// * 24 - Min Number of Operations to Sort a Binary Tree by Level
// int minimumOperations(TreeNode *root) {
// TODO
// }

// * 25 - Linked List in Binary Tree
// bool isSubPath(ListNode* head, TreeNode* root) {
// TODO
// }

// * 26 - Check Completeness of a Binary Tree
// bool isCompleteTreeBFS(TreeNode* root) {
// TODO
// }

// * 27 - Populating Next Right Pointers in Each Node I
// Node *connect(Node *root) {
// TODO (Solve this on leetcode)
// }

// * 28 - Find Duplicate Subtrees
// vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
// TODO
// }

// * 29 - Maximum Level Sum of a Binary Tree
// int maxLevelSum(TreeNode *root) {
// TODO
// }

// * 30 - Construct Binary Tree From String
// TreeNode *str2tree(string &str) {
// TODO
// }

// * 31 - Populating Next Right Pointers in Each Node II
// TreeNode *connect(TreeNode *root) {
// TODO 
// }

// * 32 - Path Sum II
// vector<vector<int>> pathSum(TreeNode *root, int target_sum) {
// TODO
// }

// * 33 - Sum Root to Leaf Numbers
// int sumNumbers(TreeNode* root) {
// TODO
// }

// * 34 - Number of Good Leaf Nodes Pairs
// int countPairs(TreeNode* root, int distance) {
// TODO
// }

// * 35 - Step-By-Step Directions From a Binary Tree Node to Another
// string getDirections(TreeNode* root, int src, int dest) {
// TODO
// }

// * 36 - Flip Equivalent Binary Trees
// bool flipEquiv(TreeNode* root1, TreeNode* root2) {
// TODO
// }

// * 37 - House Robber III
// int rob(TreeNode* root) {
// TODO
// }

// * 38 - Operations on Tree
// TODO TOMORROW (Solve this on leetcode)

// * 39 - Find Bottom Left Tree Value
// int findBottomLeftValue(TreeNode* root) {
// TODO
// }

// * 40 - Insufficient Nodes in Root to Leaf Paths
// TreeNode* sufficientSubset(TreeNode* root, int &limit) {
// TODO
// }

// * 41 - Lowest Common Ancestor of Deepest Leaves
// TreeNode* lcaDeepestLeaves(TreeNode* root) {
// TODO  
// }

// * 42 - Smallest Subtree with all the Deepest Nodes
// TreeNode* subtreeWithAllDeepest(TreeNode* root) {
// TODO  
// }

// * 43 - Sum of Nodes with Even-Valued Grandparent
// int sumEvenGrandparent(TreeNode* root) {
// TODO  
// }

// * 44 - Find Largest Value in Each Tree Row
// vector<int> largestValues(TreeNode *root) {
// TODO  
// }

// * 45 - All Possible Full Binary Trees
// vector<TreeNode *> allPossibleFBT(int n) {
// TODO  
// }

// * 46 - Lowest Common Ancestor of a Binary Tree III
// Node *lowestCommonAncestor2(vector<Node *> &nodes, Node *p_start, Node *q_start) {
// TODO
// }

// * 47 - Add One Row to Tree
// TreeNode* addOneRow(TreeNode* root, int val, int depth) {
// TODO
// }

// * 48 - Longest Consecutive Sequence In A Binary Tree
// int longestConsecutive(TreeNode* root) {
// TODO
// }

// * 49 - Binary Tree Longest Consecutive Sequence II
// int longestConsecutive(TreeNode* root) {
// TODO
// }

// * 50 - Count Nodes Equal to Average of Subtree
// int averageOfSubtree(TreeNode* root) {
// TODO
// }

// * 51 - Validate Binary Tree Nodes
// bool validateBinaryTreeNodes(int n, vector<int> &left_child, vector<int> &right_child) {
// TODO
// }

// * 52 - Delete Nodes And Return Forest
// vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
// TODO
// }

// * 53 - Even Odd Tree
// bool isEvenOddTree(TreeNode *root) {
// TODO
// }

// * 54 - Smallest String Starting From Leaf
// string smallestFromLeaf(TreeNode *root) {
// TODO
// }

// * 55 - Distribute Coins in Binary Tree
// int distributeCoins(TreeNode *root) {
// TODO
// }

// * 56 - Binary Tree Level Order Traversal II
// vector<vector<int>> levelOrderBottom(TreeNode *root) {
// TODO
// }

int main(void) {
  return 0;
}

// * run the code
// * g++ --std=c++20 practice.cpp -o output && ./output