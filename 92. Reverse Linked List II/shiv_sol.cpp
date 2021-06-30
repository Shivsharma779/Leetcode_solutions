class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        
        int c  = 0 ;
        ListNode * t = head , *pl =  NULL;
        
        while(left > 1){
            pl = t;
            if(++c == left-1){
                break;
            }
            
            t=t->next;
            
        }
        // cout << t -> val << endl;
        if(left > 1) t = t->next;
        ListNode * prev = pl, * curr = t , * nxt = t->next;
        while(curr != NULL && c!= right){
            // cout << curr->val << endl;;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt)nxt = nxt->next;
            c++;
        }
        
        t->next = curr;
        if(pl) pl->next = prev;
        else head = prev;
        return head;
        
    }
};
