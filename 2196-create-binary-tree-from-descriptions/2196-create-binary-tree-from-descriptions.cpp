/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> isChild;
        for (auto &d : descriptions) 
        {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];
            if (!mp.count(parent)) 
            {
                mp[parent] = new TreeNode(parent);
            }
            if (!mp.count(child)) 
            {
                mp[child] = new TreeNode(child);
            }

            if (isLeft == 1) 
            {
                mp[parent]->left = mp[child];
            } 
            else 
            {
                mp[parent]->right = mp[child];
            }

            isChild.insert(child);
        }
        for (auto &it : mp) 
        {
            if (!isChild.count(it.first)) 
            {
                return it.second;
            }
        }
        return nullptr;
    }
};