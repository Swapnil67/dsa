
/*
* Leetcode - 297
* Serialize and Deserialize Binary Tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          x    x   4    5

* Input: root = [1,2,3,null,null,4,5]
* Output: [1,2,3,null,null,4,5]

* https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <sstream>
#include <iostream>

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

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

class Codec {
public:

  // * Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    std::string ans = "";
    if (!root)
      return ans;

    std::queue<TreeNode *> q;
    q.push(root);

    // * BFS
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      // * For NULL node push '#' symbol
      if (!node)
        ans += "#,";
      else
        ans += std::to_string(node->data) + ",";

      // * If node is not NULL then push left and right children
      if (node) {
        q.push(node->left);
        q.push(node->right);
      }
    }

    return ans;
  }

  // * Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    if (!data.length())
      return nullptr;

    // * Create a stringstream with ',' as delimiter
    std::stringstream s(data);
    std::string str;
    getline(s, str, ',');
    
    std::queue<TreeNode*> q;
    TreeNode* root = new TreeNode(std::stoi(str));
    q.push(root);
      
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      getline(s, str, ',');
      if(str == "#") {
        node->left = nullptr;
      } else {
        TreeNode *leftNode = new TreeNode(std::stoi(str));
        node->left = leftNode;
        q.push(leftNode);
      }

      if (str == "#") {
        node->right = nullptr;
      } else {
        TreeNode *rightNode = new TreeNode(std::stoi(str));
        node->right = rightNode;
        q.push(rightNode);
      }
    }
    return root;
  }
};

void inOrderTraversal(TreeNode* root) {
  if (!root)
    return;

  inOrderTraversal(root->left);
  std::cout << root->data << std::endl;
  inOrderTraversal(root->right);
}

int main(void) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  Codec *c = new Codec();
  std::string ans = c->serialize(root);
  std::cout << ans << std::endl;

  root = c->deserialize(ans);
  inOrderTraversal(root);

  return 0;
}

// * run the code
// * g++ --std=c++17 02-serialize-anddeserialize-bt.cpp -o output && ./output
