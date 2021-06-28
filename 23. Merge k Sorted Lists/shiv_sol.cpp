class comparator{
    public:
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
        return p1.first > p2.first;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        ListNode * head = new ListNode(INT_MIN);
        ListNode * crawl = head;
        for(int i = 0 ; i < n ; i++){
            if(lists[i]){
                pq.push({(lists[i])->val,i});
                lists[i] = (lists[i]) -> next;
            }
        }
        int i = 0;
        while(!pq.empty()){
            pair<int,int> x = pq.top();
            pq.pop();
            crawl->val = x.first;
            
            if(lists[x.second]){
                int new_val = (lists[x.second])->val;
                pq.push({new_val,x.second});
                lists[x.second] = (lists[x.second]) -> next;
            }

            if(pq.empty()) break;
            
            crawl->next = new ListNode();
            crawl = crawl->next;
        }
        if (head->val == INT_MIN) return NULL;
        return head;
        
    }
};
