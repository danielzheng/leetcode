#include <iostream>
#include <vector>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL)
	{
		return NULL;
	}
	//find path from root to p and q	
	TreeNode * tmpNode = root;
	while (tmpNode != NULL)
	{
		pathP.push_back(tmpNode);
		if (p->val == tmpNode->val)
		{
			break;
		}
		else if (p->val < tmpNode->val)
		{
			tmpNode = tmpNode->left;
		}
		else
		{
			tmpNode = tmpNode->right;
		}
	}
	tmpNode = root;
	while (tmpNode != NULL)
	{
		pathQ.push_back(tmpNode);
		if (q->val == tmpNode->val)
		{
			break;
		}
		else if (q->val < tmpNode->val)
		{
			tmpNode = tmpNode->left;
		}
		else
		{
			tmpNode = tmpNode->right;
		}
	}
	TreeNode * result = NULL;
	int size = min(pathP.size(), pathQ.size());
	for (int i = 0; i < size; i++)
	{
		if (pathP[i] == pathQ[i])
		{
			result = pathP[i];
		}
	}
	return result;
    }
private:
    vector<TreeNode *> pathP;
    vector<TreeNode *> pathQ;
};

int main()
{
	TreeNode n6(6);
	TreeNode n2(2);
	TreeNode n8(8);
	TreeNode n0(0);
	TreeNode n4(4);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n3(3);
	TreeNode n5(5);

	n6.left = &n2;
	n6.right = &n8;
	n2.left = &n0;
	n2.right = &n4;
	n8.left = &n7;
	n8.right = &n9;
	n4.left = &n3;
	n4.right = &n5;

	Solution s;
	cout << s.lowestCommonAncestor(&n6, &n2, &n8)->val << endl;
	cout << s.lowestCommonAncestor(&n6, &n2, &n4)->val << endl;
	return 0;
}
