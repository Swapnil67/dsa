/*
* Construct Binary Tree From String
*
*
* https://www.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1
* https://www.naukri.com/code360/problems/binary-tree-from-bracket_1118117
*/

// ! Meta, Google

#include <stack>
#include <queue>
#include <vector>
#include <iostream>

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


// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
TreeNode* str2tree(std::string &str) {
  std::stack<TreeNode *> st;
  int n = str.size();
  for (int i = 0; i < n; ++i) {
    if (str[i] == '-') { // * Handle -ve value
      i += 1;
      int val = 0;
      while (i < n && isdigit(str[i])) {
        val = val * 10 + (str[i] - '0');
        i++;
      }
      // std::cout << val << std::endl;
      st.push(new TreeNode(val * -1));
    }
    else if (isdigit(str[i])) { // * Handle digit
      int val = 0;
      while (i < n && isdigit(str[i])) {
        val = val * 10 + (str[i] - '0');
        i++;
      }
      // std::cout << val << std::endl;
      st.push(new TreeNode(val));
    }

    if (str[i] == ')') {
      if (st.size() >= 2) {
        TreeNode *child = st.top();
        st.pop();
      
        TreeNode* parent = st.top();
        if (!parent->left) {
          // std::cout << "L" << std::endl;
          parent->left = child;
        } else {
          // std::cout << "R" << std::endl;
          parent->right = child;
        }
      }
    }
  }

  return st.top();
}

int main(void) {
  // * testcase 1
  // std::string str = "10(-20(30))";
  
  // * testcase 2
  std::string str = "1()(3)";

  // * testcase 3
  // std::string str = "4(2(3)(1))(6(5))";

  std::cout << "Input String: " << str << std::endl;

  TreeNode *root = str2tree(str);
  std::cout << "Binary Tree" << std::endl;
  levelOrderTraversal(root);

  return 0;
}


// * run the code
// * g++ --std=c++20 30-construct-bt-from-str.cpp -o output && ./output
