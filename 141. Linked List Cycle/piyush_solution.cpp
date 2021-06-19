/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int x=100001;
        
        while(head)
        {
            if(head->val==x)
                return true;
            head->val=x;
            head=head->next;
        }
        return false;
    }
};
