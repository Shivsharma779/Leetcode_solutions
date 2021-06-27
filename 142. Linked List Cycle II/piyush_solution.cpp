class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head;
        
        ListNode *slow=head,*fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)          //this is because initially both are at head
                break;
        }
        
        if(!fast || !(fast->next))      //no cycle
            return 0;
        
        fast=head;
        
        while(slow != fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return fast;
        
    }
};
