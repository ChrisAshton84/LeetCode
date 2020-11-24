/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
​
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
​
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        int level = 0;
        int levelNodes = 0;
        queue<Node *> nodes;
        nodes.push(root);
        
        // This is basically a BFS - queue up next level in order
        while (nodes.size() > 0) {
            int curLevelSize = nodes.size();
            
            if (nodes.front()->left != nullptr) {
                // If there is a next level, do first N-1 nodes pointing to next
                for (int i = 0; i < curLevelSize; i++) {
                    Node * n = nodes.front();
                    nodes.pop();
​
                    nodes.push(n->left);
                    nodes.push(n->right);
                    if (i != curLevelSize - 1)
                        n->next = nodes.front();
                }
            } else
                for (int i = 0; i < curLevelSize; i++) {
                    Node *n = nodes.front();
                    nodes.pop();
                    
                    if (i  != curLevelSize - 1)
                        n->next = nodes.front();
                }
            
        }
        
        return root;
    }
};
