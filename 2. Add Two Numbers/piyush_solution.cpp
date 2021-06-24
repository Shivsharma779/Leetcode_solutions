/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   //int addlist()
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ln1=0,ln2=0;
        ListNode *t1=l1,*t2=l2;
        //find length of lists
        while(t1)
        {
            ln1++;
            t1=t1->next;
        }
        while(t2)
        {
            ln2++;
            t2=t2->next;
        }
        t1=l1;
        t2=l2;
            
        // add list when l1 is longer
        if(ln1>=ln2)
        {   int c=0;
            while(t1&&t2)
            {
                t1->val=t1->val + t2->val + c;
                c=t1->val/10;
                t1->val=(t1->val)%10;  
                t1=t1->next;
                t2=t2->next;
            }
            while(t1)
            {
                t1->val=t1->val + c;
                c=t1->val/10;
                t1->val=(t1->val)%10;   
                t1=t1->next;
            }
            if(c)
            {
               //ListNode* temp=(ListNode *)malloc(sizeof(ListNode));
               ListNode *x= new ListNode(1);        //x inew node
                t1=l1;
                while(t1->next!= 0)
                    t1=t1->next;
                t1->next=x;
            }
         return l1;
        }
        
        //add lists when l2 longer
        else
        {
            int c=0;
            while(t1&&t2)
            {
                t2->val=t1->val + t2->val + c;
                c=t2->val/10;
                t2->val=(t2->val)%10;  
                t1=t1->next;
                t2=t2->next;
            }
            while(t2)
            {
                t2->val=t2->val + c;
                c=t2->val/10;
                t2->val=(t2->val)%10;   
                t2=t2->next;
            }
            if(c)
            {
                //ListNode* temp=(ListNode *)malloc(sizeof(ListNode));
                ListNode *x= new ListNode(1);
                t2=l2;
                while(t2->next!= 0)
                    t2=t2->next;
                t2->next=x;
            }
         return l2;
        }
        
    }
};
