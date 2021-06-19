 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * p1 ,* p2 ;
        p1 = headA, p2 = headB;
        int la = 0 , lb = 0, diff;
        while(p1){la++; p1 = p1->next;}
        while(p2){lb++; p2 = p2->next;}
        
        p1 = headA, p2 = headB;
        if(la > lb){
            diff = la - lb;
            for(int i = 0 ; i < diff ; i++) p1 = p1->next;
            
        }
        if(la < lb){
            diff = lb - la;
            for(int i = 0 ; i < diff ; i++) p2 = p2 ->next;
        }
        while(p1!=p2){
            p1 = p1 ->next;
            p2 = p2 ->next;
        }
        return p1;
    }
