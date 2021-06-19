bool hasCycle(ListNode *head) {
        
        ListNode * s = head, * f = head;
        while( f && f->next){
            s = s->next, f = f->next->next;
            if (s == f) return true;
        }
        // if(s && f && f->next && s->next == f->next->next) return true;
        return false;
    }
