/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    forward_list<TreeNode *> * findNode(TreeNode *root, TreeNode *node) {
        if (root == nullptr)
            return nullptr;
​
        if (root == node)
            return new forward_list<TreeNode *>(1, root);
        
        forward_list<TreeNode *> * ptr = findNode(root->left, node);
        if (ptr != nullptr) {
            ptr->push_front(root);
            return ptr;
        }
        
        ptr = findNode(root->right, node);
        if (ptr != nullptr) {
            ptr->push_front(root);
            return ptr;
        }
        
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        forward_list<TreeNode *> *p_order = findNode(root, p);
        forward_list<TreeNode *> *q_order = findNode(root, q);
        
        TreeNode * lastMatch;
​
        while (!(p_order->empty()) && !(q_order->empty()) && (p_order->front() == q_order->front())) {
            lastMatch = p_order->front();
            p_order->pop_front();
            q_order->pop_front();
        }
        
        return lastMatch;
    }
};
