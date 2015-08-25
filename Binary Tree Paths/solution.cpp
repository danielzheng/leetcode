#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
	    binaryTreePaths(root, string());
	    return vs;
    }
private:
    void binaryTreePaths(TreeNode* root, string path)
    {
	    if (root == NULL)
	    {
		    return;
	    }
	    path += to_string(root->val);
	    path += "->";
	    if (root->left == NULL && root->right == NULL)
	    {
		    path.pop_back();
		    path.pop_back();
		    vs.push_back(path);
		    return;
	    }
	    binaryTreePaths(root->left, path);
	    binaryTreePaths(root->right, path);
    }
    vector<string> vs;
};

int main()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);

	t1.left = &t2;
	t1.right = &t3;

	t2.left = &t4;
	t2.right = &t5;

	t5.left = &t6;

	auto& root = t1;
	Solution s;
	auto v = s.binaryTreePaths(&root);
	for (const auto& p : v)
	{
		cout << p << endl;
	}
	return 0;
}
