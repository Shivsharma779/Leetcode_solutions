/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node * t = head;
        Node * cp = new Node(t->val);
        
        Node *tcp = cp ;
        tcp->next = t->next;
        t->next = tcp;
       while(t->next->next){
            
            t = t->next->next;
            tcp = new Node(t->val);
            tcp->next = t->next;
            t->next = tcp;
        }
        t = head;

        tcp = cp;
        t= head;
        while(t){
            if(t->random != NULL) t->next->random = t->random->next;
            else t->next->random = NULL;
            Node * x = t->next->next;

            t = x;
        }
        t=head;
        while(t){

            Node * x = t->next->next;
            t->next->next = (x)?x->next:x;
            t->next = x;
            t = x;
        }

        return cp;
    }
};
