class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode * temp = head;
        int count = 0;
        while(temp){
            count++;
            temp= temp->next;
        }
        ListNode * ans = mergesort(head, count);
        temp = ans;

        return ans;
        
    }
    ListNode * mergesort(ListNode * head, int size){
        if(size>1){
            
            ListNode * temp = head, *noode;
            int x= size/2;
            while(x--){
                noode =temp;
                temp = temp->next;
             
            }
            noode->next = NULL;
            // temp = temp ->next;
            ListNode * left = mergesort(head, size/2);
            ListNode * right = mergesort(temp, size - size/2);
            
            ListNode * ans =  merge(left, right , size/2, size - size/2);
            
            return ans;
        }
        if(size == 1)return head;
        return NULL;
    }
    ListNode * merge(ListNode * l1 , ListNode * l2, int n1 , int n2){
        if(!l1) return l2;
        if(!l2) return l1;
        int x = n1 + n2;
        ListNode* temp1 = l1, *temp2 = l2;
        ListNode * head=NULL, * temp=NULL;
        if (l1->val < l2-> val) {
            head = l1;
            l1 = l1->next;
            n1--;
        }
        else{
            head = l2;
            l2 =l2 -> next;
            n2--;
        }
        
        temp = head;
        while(n1 && n2){
            if (l1->val < l2-> val) {
            temp->next = l1;
            l1 = l1->next; n1--; temp=temp->next;
            }
            else{
                temp->next= l2;
                l2 =l2 -> next; n2--; temp=temp->next;
            }
            
        }
        if(n1){
            temp->next= l1;
        }
        if(n2){
            temp->next = l2;
        }
        temp = head;

        return head;
    }
};
