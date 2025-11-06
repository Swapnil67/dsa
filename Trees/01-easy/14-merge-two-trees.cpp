/*
* Leetcode - 617
* Merge Two Binary Trees

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
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
};


void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> level;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      std::cout << node->data << " ";
    }
    std::cout << std::endl;
  }
}


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

  std::cout << "Root A: " << std::endl;
  levelOrder(rootA);
  std::cout << "Root B: " << std::endl;
  levelOrder(rootB);
  
  std::cout << "Merged Root: " << std::endl;
  TreeNode *ans = mergeTrees(rootA, rootB);
  levelOrder(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-merge-two-trees.cpp -o output && ./output

