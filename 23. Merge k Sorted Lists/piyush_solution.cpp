class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>>,  greater<pair<int,ListNode*>>> heap;
        
        for(int i=0;i<lists.size();i++)
            if(lists[i])
                heap.push({lists[i]->val , lists[i]});
                
        
        ListNode *res=NULL,*ptr=NULL;
        
        while(!heap.empty())
        {
            pair<int,ListNode*> x = heap.top();
            heap.pop();
            ListNode *temp = new ListNode(x.first);
            
            //insert smallest element in result list
            if(res == NULL)     //first element in list
            {
                res = ptr = temp;
               //ptr->next=NULL;
            }
            else
            {
                ptr->next = temp;
                ptr=ptr->next;
                //ptr->next=NULL;
            }
            
            if(x.second && (x.second)->next)        //more elemments in list
                heap.push({(x.second)->next->val , (x.second)->next});
            }
        
        return res;
        
    }
};
