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
    void get(vector<Node*> &vec, Node* root)
    {
        if(root==NULL) return;
        get(vec,root->left);
        vec.push_back(root);
        get(vec,root->right);
    }
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        vector<Node*> vec;
        get(vec,root);
        int pos=0;
        while(vec.size())
        {
            if(pos+2<vec.size())
            {
                vec[pos]->next = vec[pos+2];
                vec.erase(vec.begin()+pos);
                pos++;
            }
            else
            {
                vec.erase(vec.begin()+pos);
                pos = 0;
            }
        }
        return root;
    }
};