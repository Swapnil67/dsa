/*
 * Leetcode - 1038
 * Binary Search Tree to Greater Sum Tree
 *
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST
 * is changed to the original key plus the sum of all keys greater than the original key in BST.
 *
 * As a reminder, a binary search tree is a tree that satisfies these constraints:
 *
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * Example 1    :
 *         4
 *     /      \
 *    1        6
 *   / \     /  \
 *  0   2   5    7
 *      \        \
 *      3         8
 *
 * Input        : root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 * Output       : [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 *
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
 */

// ! Amazon, Google, Meta, Microsoft

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val) {
		data = val;
		left = right = nullptr;
	}
};

void inorderTraversal(TreeNode *root) {
	if (!root)
		return;
	inorderTraversal(root->left);
	cout << root->data << endl;
	inorderTraversal(root->right);
}

void inorder(TreeNode *root, vector<int> &nums) {
	if (!root)
		return;
	inorder(root->left, nums);
	nums.push_back(root->data);
	inorder(root->right, nums);
}

void dfsBrute(TreeNode* root, vector<int> &nums) {
	if (!root)
		return;
	dfsBrute(root->left, nums);

	// * Sum all the elements greater >= cur node val
	int newVal = root->data;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > newVal)
			newVal += nums[i];
	}
	root->data = newVal;
	// * cout << curVal << " " << newVal << endl;
	dfsBrute(root->right, nums);
}

void dfsBetter(TreeNode* root, vector<int> &nums) {
	if (!root)
		return;
	dfsBetter(root->left, nums);

	// * Loop backward and break early
	int curVal = root->data, newVal = root->data;
	for (int i = nums.size() - 1; i >= 0; --i) {
		if (nums[i] > curVal)
			newVal += nums[i];
		else break;
	}
	root->data = newVal;

	// * cout << curVal << " " << newVal << endl;
	dfsBetter(root->right, nums);
}

void dfs(TreeNode *root, int &sum) {
	if (!root)
		return;
	dfs(root->right, sum);
	sum += root->data;
	root->data = sum;
	dfs(root->left, sum);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY  O(n^2)
// * SPACE COMPLEXITY O(n)
TreeNode* bruteForce(TreeNode *root) {
	vector<int> nums;
	inorder(root, nums);
	dfsBrute(root, nums);
	// printArr(nums);
	return root;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * TIME COMPLEXITY  O(n^2)
// * SPACE COMPLEXITY O(n)
TreeNode* betterApproach(TreeNode *root) {
	vector<int> nums;
	inorder(root, nums);
	dfsBetter(root, nums);
	// printArr(nums);
	return root;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
TreeNode *bstToGst(TreeNode *root) {
	if (!root)
		return root;

	int sum = 0;
	dfs(root, sum);
	return root;
}

int main(void)
{
	// * testcase 1
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(1);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	root->right->right->right = new TreeNode(8);

	inorderTraversal(root);

	// TreeNode* ans = bruteForce(root);
	// TreeNode* ans = betterApproach(root);
	root = bstToGst(root);

	cout << "Answer " << endl;
	inorderTraversal(root);

	return 0;
}

// * Run the code
// * g++ --std=c++20 11-binary-search-tree-to-greater-sum-tree.cpp -o output && ./output
