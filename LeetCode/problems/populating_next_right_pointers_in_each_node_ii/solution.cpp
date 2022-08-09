/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void get(queue<Node*> &q, vector<Node*>&v)
    {
        if(q.empty()) return;
        Node* root = q.front();
        v.push_back(root);
        if(root==NULL)
        {
            q.pop();
            if(q.empty()) return;
            q.push(NULL);
            get(q,v);
            return;
        }
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        q.pop();
        get(q,v);
    }
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        vector<Node*> v;
        q.push(root);
        q.push(NULL);
        get(q,v);
        Node* prev = v[0];
        // for(int i=0; i<v.size(); i++)
        // {
        //     if(v[i])
        //         cout<<v[i]->val<<" ";
        //     else
        //         cout<<"NULL ";
        // }
        // cout<<endl;
        for(int i=1; i<v.size(); i++)
        {
            prev->next = v[i];
            if(v[i])
                prev = v[i];
            else
            {
                prev = v[i+1];
                i = i+1;
            }
        }
        return root;
    }
};