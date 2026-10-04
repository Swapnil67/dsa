/*
 * Leetcode - 1382
 * Balance a Binary Search Tree
 *
 * Given the root of a binary search tree, return a balanced binary search tree with the same node values.
 * If there is more than one answer, return any of them.
 *
 * A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
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
 * Input        : root = [1,null,2,null,3,null,4,null,null]
 * Output       : [2,1,3,null,null,null,4]
 *
 * https://leetcode.com/problems/balance-a-binary-search-tree/description/
 */

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr)
{
	int n = arr.size();
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ", ";
	}
	cout << " ]" << endl;
}

typedef struct TreeNode TreeNode;

struct TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val)
	{
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

TreeNode *construct(int l, int r, vector<int> &nums) {
	if (l > r)
		return NULL;
	int m = l + (r - l) / 2;
	TreeNode *root = new TreeNode(nums[m]);
	root->left = construct(l, m - 1, nums);
	root->right = construct(m + 1, r, nums);
	return root;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(n)
TreeNode *balanceBST(TreeNode *root)
{
	if (!root)
		return root;

	vector<int> nums;
	inorder(root, nums);
	int l = 0, r = nums.size() - 1;
	return construct(l, r, nums);
}

int main(void)
{
	// * testcase 1
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	root->right->right->right = new TreeNode(4);

	inorderTraversal(root);

	root = balanceBST(root);

	cout << "Answer " << endl;
	inorderTraversal(root);

	return 0;
}

// * Run the code
// * g++ --std=c++20 12-balance-bst.cpp -o output && ./output
