class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode * head, *temp = NULL;
        if(l1->val < l2->val){
            head = l1; l1 = l1->next;   
        }else{
            head = l2; l2 = l2->next;
        }
        temp = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next=l1;
                l1 = l1->next;   
            }
            else{
                temp->next = l2;
                l2 = l2->next;
                
            }
            temp=temp->next;
        }
        while(l1){
            temp->next=l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2){
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        return head;
    }
};
