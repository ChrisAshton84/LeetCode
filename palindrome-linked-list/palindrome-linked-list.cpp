/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> vals;
        
        auto ptr = head;
        while (ptr != nullptr) {
            vals.push(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        while (ptr != nullptr) {
            if (ptr->val != vals.top())
                return false;
            vals.pop();
            ptr = ptr->next;
        }
        
        return true;
    }
};
