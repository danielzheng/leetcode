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
	vector<TreeNode *> path1, path2;
	getPath(root, p, path1);
	getPath(root, q, path2);

	int size = min(path1.size(), path2.size());
	TreeNode * result = NULL;
	for (int i = 0; i < size; i++)
	{
	    if (path1[i] == path2[i])
	    {
		result = path1[i];
	    }
	}
	return result;
    }
private:
    bool getPath(TreeNode * root, TreeNode * dest, vector<TreeNode *>& path)
    {
	if (root == NULL)
	{
	    return false;
	}
	path.push_back(root);
	if (root == dest)
	{
	    return true;
	}
	if (getPath(root->left, dest, path) || getPath(root->right, dest, path))
	{
	    return true;
	}
	path.pop_back();
	return false;
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    TreeNode n9(9);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = &n8;
    n4.right = &n9;

    Solution s;

    cout << s.lowestCommonAncestor(&n1, &n4, &n7)->val << endl;
    cout << s.lowestCommonAncestor(&n1, &n8, &n5)->val << endl;
    return 0;
}
