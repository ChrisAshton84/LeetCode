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
private:
    TreeNode *buildSubtree(vector<int> &inorder, vector<int> &postorder, int node_post_idx, vector<int>::iterator in_begin, vector<int>::iterator in_end) {
        TreeNode *ret = new TreeNode(postorder[node_post_idx]);
        
        if (node_post_idx == 0) // If has no children we've reached last node
            return ret;
        
        if ((in_end - in_begin) == 1)
            return ret;
        
        auto in_node = find(in_begin, in_end, postorder[node_post_idx]);
        int lhs = in_node - in_begin;
        int rhs = in_end - in_node - 1;
                
        if (rhs > 0) {
            ret->right = buildSubtree(inorder, postorder, node_post_idx - 1, in_node + 1, in_end);
        }
        
        if (lhs > 0) {
            ret->left = buildSubtree(inorder, postorder, node_post_idx - 1 - rhs, in_begin, in_node);
        }
​
        return ret;
    }
public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int mapped = 0;
​
        if (inorder.size() == 0)
            return nullptr;
        
        return buildSubtree(inorder, postorder, postorder.size() - 1, inorder.begin(), inorder.end());
    }
};
