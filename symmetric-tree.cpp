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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        auto isNull = [](TreeNode * x)->bool {
            if (x == nullptr)
                return true;
            return false;
        };
​
        vector<TreeNode *> levelNodes;
        
        levelNodes.push_back(root);
        
        while (levelNodes.size()) {
            vector<TreeNode *> nextLevelNodes;
            
            int l = 0;
            int r = levelNodes.size() - 1;
            
            while (l < r) {
                auto l_node = levelNodes[l];
                auto r_node = levelNodes[r];
                if ((isNull(l_node->left) != isNull(r_node->right)) ||
                    (isNull(l_node->right) != isNull(r_node->left)))
                    return false;
                if (l_node->val != r_node->val)
                    return false;
                l++;
                r--;
            }
            
            if (l == r)
                if (isNull(levelNodes[l]->left) != isNull(levelNodes[l]->right))
                    return false;
            
            for (auto& x: levelNodes) {
                if (!isNull(x->left))
                    nextLevelNodes.push_back(x->left);
                if (!isNull(x->right))
                    nextLevelNodes.push_back(x->right);
            }
            
            levelNodes = nextLevelNodes;
        }
        
        return true;
    }
};
