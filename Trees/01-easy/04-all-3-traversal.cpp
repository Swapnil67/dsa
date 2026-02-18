#include <stack>
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
void printArr(vector<T> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
};

void threeTraversal(TreeNode *root,
                    vector<int> &preOrder,
                    vector<int> &inOrder,
                    vector<int> &postOrder)
{

  if (root == nullptr)
    return;

  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // * increment 1 to 2
    // * then push left side of the tree
    if (it.second == 1) {
      preOrder.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->left)
        st.push({it.first->left, 1});
      
    } else if(it.second == 2) {
      inOrder.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->right)
        st.push({it.first->right, 1});
      
    } else {
      postOrder.push_back(it.first->data);
    }
  }
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<int> preOrder, inOrder, postOrder;
  threeTraversal(root, preOrder, inOrder, postOrder);

  cout << "Pre Order Traversal" << endl;
  printArr(preOrder);
  cout << "In Order Traversal" << endl;
  printArr(inOrder);
  cout << "Post Order Traversal" << endl;
  printArr(postOrder);

  return 0;
}

// * Run the code
// * g++ --std=c++17 04-all-3-traversal.cpp -o output && ./output