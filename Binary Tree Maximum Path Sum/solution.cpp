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
    int maxPathSum(TreeNode *root) {
		if (!root)
		{
			return 0;
		}
		max = INT_MIN;
		buildNodeSum(root);
		return max;
	}
private:
	int buildNodeSum(TreeNode * node)
	{
		if (!node)
		{
			return 0;
		}

		int maxLeft = buildNodeSum(node->left);
		int maxRight = buildNodeSum(node->right);

		int currentMax = node->val;
		int biggerChild = maxLeft > maxRight ? maxLeft : maxRight;
		biggerChild = biggerChild > 0 ? biggerChild : 0;

		if (maxLeft > 0)
		{
			currentMax += maxLeft;
		}
		if (maxRight > 0)
		{
			currentMax += maxRight;
		}
		if (currentMax > max)
		{
			max = currentMax;
		}
		return node->val + biggerChild;
	}
	int max;
};