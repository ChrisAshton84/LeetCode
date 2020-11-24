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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        if (root == nullptr)
            return ret;
        
        stack<TreeNode *> depth;
        
        auto current = root;
​
        while ((depth.size() != 0) || (current != nullptr)) {
            if (current != nullptr) {
                depth.push(current);
                current = current->left;
            } else {
                // Backed up a level, finish processing this node
                current = depth.top();
                depth.pop();
​
                ret.push_back(current->val);
                
                current = current->right;
            }
        }
        
        return ret;
    }
};
