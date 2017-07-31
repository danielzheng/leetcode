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
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return value;        
    }
private:
    void inorderTraversal(TreeNode* root, int& k)
    {
        if (root == NULL || k == 0)
        {
            return;
        }        
        inorderTraversal(root->left, k);
        --k;
        if (k == 0)
        {
            value = root->val;
        }
        inorderTraversal(root->right, k);
    }
    int value;
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);

    node2.left = &node1;
    node2.right = &node3;

    node6.left = &node5;
    node6.right = &node7;

    node4.left = &node2;
    node4.right = &node6;

    TreeNode& root = node4;

    Solution s;

    cout << "5th smallest number from Tree is " << s.kthSmallest(&root, 3) << endl;

    return 0;
}
