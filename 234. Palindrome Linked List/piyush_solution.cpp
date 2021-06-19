/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reversell(ListNode* head)
    {
        if(head==0)
            return 0;
        ListNode *prev=0,*cur=head,*next=head->next;
        
        while(cur)
        {
            cur->next=prev;
            prev=cur;
            cur=next;
            if(next)
                next=next->next;
        }
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) 
    {
        if(head==0 || head->next==0)
            return true;
        
        ListNode* slow = head,*fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        slow=reversell(slow);
        
        while( fast && slow )
        {
            if(slow->val != fast->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
