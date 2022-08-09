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
        vector<Node*> vec;
        unordered_map<Node*,int> m;
        if(head==NULL) return NULL;
        Node* temp = head;
        int c=0;
        while(temp)
        {
            Node* n = new Node(temp->val);
            vec.push_back(n);
            m.insert(make_pair(temp,c));
            temp = temp->next;
            c++;
        }
        temp = head;
        for(int i=0; i<vec.size()-1; i++)
        {
            vec[i]->next = vec[i+1];
        }
        Node* temp2 = vec[0];
        while(temp)
        {
            if(temp->random)
            temp2->random = vec[m[temp->random]];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return vec[0];
    }
};