ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp=dummy;
    
    while(a && b)
    {
        if(a->val < b->val)
        {
            dummy->next=a;
            a=a->next;
        }
        else
        {
            dummy->next=b;
            b=b->next;
        }
        dummy=dummy->next;
    }
    
    if(a)
        dummy->next=a;
    if(b)
        dummy->next=b;
    
    
    return temp->next;
}
