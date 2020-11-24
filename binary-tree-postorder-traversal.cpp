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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> depth;
        vector<int> ret;
        
        auto ptr = root;
        
        while ((depth.size() > 0) || (ptr != NULL)) {
            while (ptr != nullptr) {
                if (ptr->right != nullptr)
                    depth.push(ptr->right);
                
                depth.push(ptr);
                
                ptr = ptr->left;
            }
​
            // Reached the end of a chain
            // At this point the stack has the parent and parent->right nodes
            ptr = depth.top();
            depth.pop();
​
            if ((depth.size() > 0) && (depth.top() == ptr->right)) {
                // If needed, process right hand tree
                auto tmp = ptr;
                ptr = ptr->right;
​
                depth.pop(); // Remove right - we are processing it
                depth.push(tmp); // And return to this node later
            } else {
                ret.push_back(ptr->val);
                ptr = nullptr;
            }
        }
        
        return ret;
    }
};
