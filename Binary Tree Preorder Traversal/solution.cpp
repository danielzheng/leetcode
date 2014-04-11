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
    vector<int> preorderTraversal(TreeNode *root) {
        preorderTraversalHelper(root, vi);
		return vi;
    }

private:
	void preorderTraversalHelper(TreeNode *root, vector<int>& vi)
	{
		if (root == NULL)
		{
			return;
		}
		vi.push_back(root->val);
		preorderTraversalHelper(root->left, vi);
		preorderTraversalHelper(root->right, vi);
	}

	vector<int> vi;
};