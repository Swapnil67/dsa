#include <vector>
#include <climits>
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
}

// * 01 - Search in a Binary Search Tree
// TreeNode *searchBST(TreeNode *root, int val) {
//   TODO
// }

// * 02 - Ceil in a Binary Search Tree
// int findCeil(TreeNode* root, int val) {
// TODO
// }

// * 03 - Floor in a Binary Search Tree
// int findFloor(TreeNode* root, int val) {
// TODO
// }

// * 04 - Convert Sorted Array to Binary Search Tree
// TreeNode *sortedArrayToBST(std::vector<int> &nums) {
// TODO
// }

// * 05 - Closest Binary Search Tree Value
// int findClosestElement(TreeNode *root, int k) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
