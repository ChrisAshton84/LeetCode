/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> depth;
        depth.push(root);
        
        vector<int> ret;
        
        if (root == nullptr)
            return ret;
​
        while (depth.size() != 0) {
            auto current = depth.top();
            depth.pop();
            ret.push_back(current->val);
​
            if (current->right != nullptr)
                depth.push(current->right);
            
            if (current->left != nullptr)
                depth.push(current->left);
        }
        
        return ret;
    }
};
