class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * x  = new ListNode();
        x->next = head;
        ListNode * s  = x, *f = x;
        while(n--) f = f->next;
        while(f->next) s= s->next , f = f->next;
        
        s->next = s->next->next;
        return x->next;
        
    }
};
