#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int count = 0;

    pair<int, int> postOrder(TreeNode* root) {

        if (root == NULL) {
            return {0, 0};
        }

        // Left subtree
        pair<int, int> left = postOrder(root->left);

        // Right subtree
        pair<int, int> right = postOrder(root->right);

        // Sum of current subtree
        int nodeSum = left.first + right.first + root->val;

        // Number of nodes in current subtree
        int nodeCount = left.second + right.second + 1;

        // Check average
        if (root->val == nodeSum / nodeCount) {
            count++;
        }

        return {nodeSum, nodeCount};
    }

    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return count;
    }
};

int main() {

    // Example tree:
    //        4
    //       / \
    //      8   5
    //     / \   \
    //    0   1   6

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(6);

    Solution obj;

    cout << obj.averageOfSubtree(root);

    return 0;
}