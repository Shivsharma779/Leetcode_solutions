class Solution {
public:
    int carry = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * curr = new ListNode(),  *ans = curr;
        
        int c = 0;
        while(curr){
            
            curr->val = ((l1)?l1->val:0) + ((l2)?l2->val:0) + c;

            c = curr->val/10;
            curr->val %= 10;

            l1=(l1)?l1->next:l1;
            l2=(l2)?l2->next:l2;

            curr->next = (l1 || l2 || c)? new ListNode(): NULL;
            curr = curr->next;
        }
        
        return ans;
    }
};
