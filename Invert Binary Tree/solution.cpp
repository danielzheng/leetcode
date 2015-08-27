#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		postOrderTraverse(root);
		return root;
	}
private:
	void postOrderTraverse(TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		swap(root->left, root->right);
	}
};


void postOrderVisit(TreeNode * root)
{
	if (root == NULL)
	{
		return;
	}
	postOrderVisit(root->left);
	postOrderVisit(root->right);
	cout << root->val << endl;
}
int main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;

	Solution s;
	auto r = s.invertTree(&n1);
	postOrderVisit(r);

	return 0;
}
