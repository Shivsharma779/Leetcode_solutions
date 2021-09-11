/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)           //empty list
            return 0;
        
        ListNode *odd=head, *even=head->next , *evenHead = head->next;
        
        while(even && even->next)
        {           
            //link to next even/odd index resp.
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            //shift pointers to next even/odd nodes
            odd = odd->next;
            even = even->next;
        }
        
        //join even nodes after odd indices
        odd->next = evenHead;
        
        return head;
        
    }
};
