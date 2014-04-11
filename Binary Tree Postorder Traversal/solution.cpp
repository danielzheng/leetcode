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
	vector<int> postorderTraversal(TreeNode *root) {
		postorderTraversalHelper(root, vi);
		return vi;
	}

private:
	void postorderTraversalHelper(TreeNode *root, vector<int>& vi)
	{
		if (root == NULL)
		{
			return;
		}
		postorderTraversalHelper(root->left, vi);
		postorderTraversalHelper(root->right, vi);
		vi.push_back(root->val);
	}
	vector<int> vi;
};