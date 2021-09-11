class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        
        ListNode * even = head->next;
        ListNode * even_crawler = head->next;

        ListNode * odd_crawler = head;
        
        while(even_crawler && even_crawler->next){
            odd_crawler->next = even_crawler->next;
            even_crawler->next = (odd_crawler->next->next);
            odd_crawler = (odd_crawler->next) ;
            even_crawler = even_crawler->next;
        }
        odd_crawler->next = even;
        return head;
    }
};
