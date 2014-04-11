/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int sumNumbers(TreeNode *root) {
		sum = 0;
		sumNumbers(root, 0);
		return sum;
	}

private:
	void sumNumbers(TreeNode *root, int num)
	{
		if (!root)
		{
			return;
		}
		num = num * 10 + root->val;
		if (!root->left && !root->right)
		{
			sum += num;
			return;
		}
		sumNumbers(root->left, num);
		sumNumbers(root->right, num);
	}
	int sum;
};