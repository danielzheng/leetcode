#include <iostream>
#include <list>

using namespace std;

/**
* Definition for binary tree
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        buildNextList(root);
        it = lt.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (it != lt.end());
    }

    /** @return the next smallest number */
    int next() {
        return (*it++)->val;
    }
private:
    void buildNextList(TreeNode * root)
    {
        if (root == NULL)
        {
            return;
        }
        buildNextList(root->left);
        lt.push_back(root);
        buildNextList(root->right);
    }
    list<TreeNode *> lt;
    list<TreeNode *>::iterator it;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

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

    node4.left = &node2;
    node4.right = &node6;

    node6.left = &node5;
    node6.right = &node7;

    BSTIterator it(&node4);
    while (it.hasNext())
    {
        cout << it.next() << " ";
    }
    cout << endl;
    return 0;
}
