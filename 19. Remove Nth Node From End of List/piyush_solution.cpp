class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();       //dummy before head for edge cases
        dummy->next=head;   
        
        ListNode* fast=dummy,*slow=dummy;
        
        for(int i=0;i<n+1;i++)          //move fast to n+1 th position from front
            fast=fast->next;
        
        while(fast && slow)             //move slow to node before node to be deleted
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next=slow->next->next;        //remove node
        
        
        return dummy->next;     //return new lis
    }
};
