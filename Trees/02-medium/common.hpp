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

  ~TreeNode()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

template <typename T>
void printArr(std::vector<T> &arr)
{
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i)
  {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

void levelOrderTraversal(TreeNode *root)
{
  if (!root)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int n = q.size();
    // * traverse the whole level
    while (n--)
    {
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
