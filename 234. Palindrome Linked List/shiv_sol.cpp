ListNode * mid(ListNode * head){
        ListNode * temp = head;
        while(temp->next && temp->next->next) head = head->next, temp = temp->next->next;
        return head;
    }
    ListNode * reverse(ListNode * head){
        if(head == NULL) return NULL;
        ListNode * p = NULL, * c = head , *n = head->next;
        while(c){
            c->next = p;
            p = c;
            c = n;
            if(c) n = c->next;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode * m = mid(head);
        ListNode * t = reverse(m->next);
        while(head && t){
            if(head->val != t->val) return false;
            head = head->next , t = t->next;
        }
        return true;
        
    }
