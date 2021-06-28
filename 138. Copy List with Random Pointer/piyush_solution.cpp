class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==0)
            return 0;
        
        Node *dummy1=new Node(0);
        Node *dummy2=new Node(0);
        dummy1->next=head;
        
        Node *temp1=dummy1->next;
        Node *temp2=dummy2->next;
        
        Node *prev1=dummy1;
        Node *prev2=dummy2;
        
        unordered_map<Node *,Node *> mp;
        mp[NULL]=NULL;
        while(temp1)
        {
            Node *temp=new Node(temp1->val);
            mp[temp1]=temp;
            temp1=temp1->next;
        }
        
        
        temp1=dummy1->next;
        temp2=dummy2->next;
        
        while(temp1)
        {
            mp[temp1]->next=mp[temp1->next];
            mp[temp1]->random=mp[temp1->random];
            temp1=temp1->next;
        }
    
        return mp[head];
    }
};
