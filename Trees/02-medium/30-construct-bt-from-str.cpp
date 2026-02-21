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
#include "common.hpp"

using namespace std;

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
TreeNode* str2tree(string &str) {
  stack<TreeNode *> st;
  int n = str.size();
  for (int i = 0; i < n; ++i) {
    // * Handle -ve digit
    if (str[i] == '-') { 
      i += 1;
      int val = 0;
      while (i < n && isdigit(str[i])) {
        val = val * 10 + (str[i] - '0');
        i++;
      }
      // cout << val << endl;
      st.push(new TreeNode(val * -1));
    }
    else if (isdigit(str[i])) { // * Handle +ve digit
      int val = 0;
      while (i < n && isdigit(str[i])) {
        val = val * 10 + (str[i] - '0');
        i++;
      }
      // cout << val << endl;
      st.push(new TreeNode(val));
    }

    if (str[i] == ')') {
      if (st.size() >= 2) {
        TreeNode *child = st.top();
        st.pop();
      
        TreeNode* parent = st.top();
        if (!parent->left) {
          // cout << "L" << endl;
          parent->left = child;
        } else {
          // cout << "R" << endl;
          parent->right = child;
        }
      }
    }
  }

  return st.top();
}

// * Variant (With no -ve digits)
TreeNode *treeFromBracket(string &s) {
  stack<TreeNode *> st;
  int n = s.size();

  // * for root having multiple digits
  TreeNode *root = new TreeNode(s[0] - '0');
  int i = 1;
  while (i < n && s[i] != '(' && s[i] != ')') {
    root->data = root->data * 10 + (s[i] - '0');
    i++;
  }

  TreeNode *cur = root;

  for (; i < n; ++i) {
    // * if '(' signifies the beginning of new subtree, 
    if (s[i] == '(') {
      if (cur) {
        st.push(cur);
      }
      cur = NULL;
    }
    else if (s[i] == ')') {
      // * if ')' signifies the end of this subtree
      TreeNode* parent = st.top();
      st.pop();

      if (!parent->left)
        parent->left = cur;
      else
        parent->right = cur;

      cur = parent;
    } else {
      // * if digit then keep concat to current data
      if (!cur)
        cur = new TreeNode(s[i] - '0');
      else
        cur->data = cur->data * 10 + (s[i] - '0');
    }
  }

  return root;
}

int main(void) {
  // * testcase 1
  // string str = "10(-20(30))";
  
  // * testcase 2
  // string str = "1()(3)";

  // * testcase 3
  // string str = "4(2(3)(1))(6(5))";

  // * testcase 4 (Variant)
  string str = "4(4(2))(3()(2()(1)))";

  cout << "Input String: " << str << endl;

  // TreeNode *root = str2tree(str);
  TreeNode *root = treeFromBracket(str);
  cout << "Binary Tree" << endl;
  levelOrderTraversal(root);

  return 0;
}


// * run the code
// * g++ --std=c++20 30-construct-bt-from-str.cpp -o output && ./output
