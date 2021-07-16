class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL, *c = head, *n = (c)?c->next:NULL;
        while(c){
            c->next = p;
            p=c;
            c=n;
            n=(c)?c->next:NULL;
        }
        return p;
    }
    
};
