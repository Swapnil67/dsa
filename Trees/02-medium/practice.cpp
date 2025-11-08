#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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

void inOrderTraversal(TreeNode* root) {
  if (!root)
    return;

  inOrderTraversal(root->left);
  std::cout << root->data << " ";
  inOrderTraversal(root->right);
}

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();
    // * traverse the whole level
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      std::cout << node->data << " ";

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    std::cout << std::endl;
  }
}


// * 27 - Populating Next Right Pointers in Each Node I
// bool isCompleteTreeBFS(TreeNode* root) {
// TODO (Do this in leetcode)
// }

// * 28 - Find Duplicate Subtrees
// std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
// TODO
// }

// * ------------------------------------------------------------------------

// * 01 - Binary Tree Level Order Traversal
// std::vector<std::vector<int>> levelOrder(TreeNode *root) {
// TODO
// }

// * 02 - Binary Tree Zigzag Level Order Traversal
// std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
// TODO
// }

// * 03 - Boundary Traversal of tree
// std::vector<int> boundaryTraversal(TreeNode* root) {
// TODO
// }

// * 04 - Vertical Traversal of tree
// std::vector<std::vector<int>> verticalOrderTraversal(TreeNode *root) {
// TODO
// }

// * 05 - Top View of Binary tree
// std::vector<int> topView(TreeNode *root) {
// TODO
// }

// * 06 - Bottom View of Binary tree
// std::vector<int> bottomView(TreeNode *root) {
// TODO
// }

// * 07 - Right View of Binary tree
// std::vector<int> rightView(TreeNode *root) {
// TODO
// }

// * 08 - left View of Binary tree
// std::vector<int> leftView(TreeNode *root) {
// TODO
// }

// * 09 - Root to Node
// std::vector<int> rootToNode(TreeNode *root, int x) {
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
// std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
// TODO
// }

// * 13 - Amount of Time for Binary Tree to Be Infected
// int amountOfTime(TreeNode* root, int start) {
// TODO
// }

// * 14 - Construct Binary Tree from Preorder and Inorder Traversal
// TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
// TODO
// }

// * 15 - Construct Binary Tree from Inorder and Postorder Traversal
// TreeNode *buildTree(std::vector<int> &postorder, std::vector<int> &inorder) {
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
// TODO
// }

// * 20 - Create Binary Tree From Descriptions
// TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) {
// TODO
// }

// * 21 - Construct String from Binary Tree
// std::string tree2str(TreeNode *root) {
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

// * 24 - Minimum Number of Operations to Sort a Binary Tree by Level
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

int main(void) {
  return 0;
}

// * run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
