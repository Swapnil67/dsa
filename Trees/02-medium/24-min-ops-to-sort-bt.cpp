/*
* Leetcode - 2471
* Minimum Number of Operations to Sort a Binary Tree by Level

* You are given the root of a binary tree with unique values.

* In one operation, you can choose any two nodes at the same level and swap their values.
* Return the minimum number of operations needed to make the values at each level sorted in a strictly
* increasing order.
* The level of a node is the number of edges along the path between it and the root node.

* Example 1:
* Input: 
*                   1        
*               /      \     
*             4         3
*           /  \      /   \  
*          7    6    8    5
*                  /     /  
*                9     10

* Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
* Output: 3
* Explanation:
* - Swap 4 and 3. The 2nd level becomes [3,4].
* - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
* - Swap 8 and 7. The 3rd level becomes [5,6,7,8].

* https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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
};


void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
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

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int findOps(std::vector<int> &arr, std::unordered_map<int, int> &idxMap) {
  // * create an actual sorted array
  std::vector<int> sorted_vec(arr.begin(), arr.end());
  std::sort(sorted_vec.begin(), sorted_vec.end());

  // printArr(sorted_vec);

  int swaps = 0;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == sorted_vec[i])
      continue;  // * no swap required

    // * swap the indexes
    int cur_idx = idxMap[sorted_vec[i]];  // * actual sorted index
    idxMap[arr[i]] = cur_idx;
    swap(arr[cur_idx], arr[i]);

    swaps++;
  }

  // std::cout << "cur ops: " << swaps << std::endl;
  return swaps;
}


// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * Level Order Traversal + Find min ops to make array sorted
// * TIME COMPLEXITY O(level * wlogw + w) ('w' is no. of nodes on each level)
// * SPACE COMPLEXITY O(W)
int minimumOperations(TreeNode *root) {
  int ans = 0;
  if (!root)
    return ans;

  std::queue<TreeNode *> q;
  q.push(root);

  while(!q.empty()) {

    std::vector<int> arr;
    std::unordered_map<int, int> idxMap;

    int n = q.size();
    // * traverse the whole level
    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();

      arr.push_back(node->data);
      idxMap[node->data] = i;

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    // printArr(arr);

    // * Find how many ops are required to sort the array
    ans += findOps(arr, idxMap);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(4);
  // root->right = new TreeNode(3);
  
  // root->left->left = new TreeNode(7);
  // root->left->right = new TreeNode(6);
  
  // root->right->left = new TreeNode(8);
  // root->right->right = new TreeNode(5);
  
  // root->right->left->left = new TreeNode(9);
  // root->right->right->left = new TreeNode(10);

  // * testcase 2
  TreeNode* root = new TreeNode(49);
  root->left = new TreeNode(45);
  root->right = new TreeNode(1);
  
  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(46);
  
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(39);
  
  root->left->left->left = new TreeNode(27);
  root->right->left->left = new TreeNode(25);

  std::cout << "Input Tree" << std::endl;
  levelOrderTraversal(root);

  int ans = minimumOperations(root);
  std::cout << "Minimum Number of Operations to Sort a Binary Tree by Level " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 24-min-ops-to-sort-bt.cpp -o output && ./output

