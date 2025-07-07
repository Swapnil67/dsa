#include <stack>
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

void threeTraversal(TreeNode *root,
                    std::vector<int> &preOrder,
                    std::vector<int> &inOrder,
                    std::vector<int> &postOrder)
{

  if (root == nullptr)
    return;

  std::stack<std::pair<TreeNode *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // * increment 1 to 2
    // * then push left side of the tree
    if(it.second == 1) {
      preOrder.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->left != nullptr) {
        st.push({it.first->left, 1});
      }
    } else if(it.second == 2) {
      inOrder.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->right != nullptr) {
        st.push({it.first->right, 1});
      }
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

  std::vector<int> preOrder, inOrder, postOrder;
  threeTraversal(root, preOrder, inOrder, postOrder);

  std::cout << "Pre Order Traversal" << std::endl;
  printArr(preOrder);
  std::cout << "In Order Traversal" << std::endl;
  printArr(inOrder);
  std::cout << "Post Order Traversal" << std::endl;
  printArr(postOrder);
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-all-3-traversal.cpp -o output && ./output