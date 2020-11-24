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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * ret = new ListNode();
        ListNode * curNode = ret;
​
        while (l1 || l2 || carry) {
            int val1 = (l1 ? l1->val : 0);
            int val2 = (l2 ? l2->val : 0);
            int sum = val1 + val2 + carry;
​
            if (sum < 10) {
                curNode->val = sum;
                carry = 0;
            } else {
                curNode->val = sum - 10;
                carry = 1;
            }
​
            l1 = (l1 ? l1->next : 0);
            l2 = (l2 ? l2->next : 0);
​
            if (l1 || l2  || carry) {
                curNode->next = new ListNode();
                curNode = curNode->next;
            }
        }
        return ret;
    }
};
