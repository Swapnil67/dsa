/*
* Leetcode - 145
* Binary Tree Prostorder Traversal

* https://leetcode.com/problems/binary-tree-postorder-traversal/description/
* https://www.naukri.com/code360/problems/postorder-traversal_2035933
*/

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

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

// ! Left | Right | Root


// * Using Recursion
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
// * SPACE COMPLEXITY Best Case  = O(logn) ~ O(height of tree) * Size of Activation Record
void postOrder(TreeNode* node, std::vector<int> &ans) {
  if (node == nullptr)
    return;

  // std::cout << node->data << std::endl;
  postOrder(node->left, ans);
  postOrder(node->right, ans);
  ans.push_back(node->data);
}

// * Using 2 Stacks
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY 
// *    O(2n) - stack
// *    O(n) - output array
std::vector<int> postOrderIterative1(TreeNode* root) {
  std::vector<int> ans;
  if (root == nullptr)
    return ans;

  std::stack<TreeNode *> st1, st2;
  st1.push(root);
  
  while (!st1.empty()) {
    TreeNode *node = st1.top();
    st1.pop();
    st2.push(node);

    if(node->left) {
      st1.push(node->left);
    }

    if(node->right) {
      st1.push(node->right);
    }
  }

  while (!st2.empty()) {
    ans.push_back(st2.top()->data);
    st2.pop();
  }

  return ans;
}

// * Using 1 Stack
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY 
// *    O(n) - stack
// *    O(n) - output array
std::vector<int> postOrderIterative2(TreeNode* root) {
  std::vector<int> ans;
  if (root == nullptr)
    return ans;

  std::stack<TreeNode *> st;
  TreeNode *cur = root;

  while (!st.empty() || cur != nullptr) {
    if(cur != nullptr) {
      st.push(cur);
      cur = cur->left;
    }
    else {
      TreeNode *temp = st.top()->right;
      if (temp == nullptr) {
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        while (!st.empty() && st.top()->right == temp) {
          temp = st.top();
          st.pop();
          ans.push_back(temp->data);
        }
      } else {
        cur = temp;
      }
    }
  }

  return ans;
}

// * Much easy to understand
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY 
// *    O(n) - stack
// *    O(n) - output array
void postOrderIterative3(TreeNode *root, std::vector<int> &ans) {
  if (root == nullptr)
    return;

  std::stack<TreeNode*> st;
  TreeNode*cur = root; 

  while (cur || !st.empty()) {
    if (cur) {
      ans.push_back(cur->data);
      st.push(cur);
      cur = cur->right;
    } else {
      cur = st.top();
      st.pop();
      cur = cur->left;
    }
  } 

  std::reverse(ans.begin(), ans.end());
}

// * Just reverse of Pre Order Traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY 
// *    O(n) - stack
// *    O(n) - output array
void postOrderIterative4(TreeNode *root, std::vector<int> &ans) {
 if (!root)
    return;

  std::stack<TreeNode *> st;

  TreeNode* cur = root;
  st.push(root);
  while (st.size()) {
    TreeNode* topNode = st.top();
    st.pop();

    ans.push_back(topNode->data);
    if (topNode->left)
      st.push(topNode->left);
      
    if (topNode->right)
      st.push(topNode->right);
  }

  std::reverse(ans.begin(), ans.end());
}


int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::vector<int> ans;
  // postOrder(root, ans);
  // ans = postOrderIterative1(root);
  ans = postOrderIterative2(root);

  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-post-order-traversal.cpp -o output && ./output
