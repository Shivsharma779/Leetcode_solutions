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
    //assign all nodes' next to dummy node and check if seen before
    
    bool hasCycle(ListNode *head) {
        ListNode *dummy = new ListNode(0) , *temp=head;
        while(temp)
        {
            if(temp->next == dummy)
                return true;  
            
            ListNode *temp_next = temp->next;
            temp->next = dummy;
            temp = temp_next;
        }
        
        return false;
    }
};
