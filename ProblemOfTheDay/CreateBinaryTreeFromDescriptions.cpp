/*
Approach:
1. Use a hashmap to store value -> TreeNode* so that each node is created only once.
2. For every description [parent, child, isLeft]:
   - Create parent/child nodes if they do not exist.
   - Connect child as the left or right child of parent.
   - Store the child value in a set.
3. After processing all descriptions, every node except the root appears as a child.
4. Traverse the hashmap and find the node whose value is not present in the child set.
   That node is the root of the binary tree.
5. Return the root node.

Time Complexity: O(n)
Space Complexity: O(n)

where n = descriptions.size()
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childNodes;

        for (auto &d : descriptions) {

            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (!mp.count(child))
                mp[child] = new TreeNode(child);

            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            childNodes.insert(child);
        }

 for (auto &it : mp) {
    if (!childNodes.count(it.first))
        return it.second;
}

        return nullptr;
    }
};