/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        queue<Node*> q1, q2;
        unordered_map<int,Node*> m;
        Node* newNode = new Node(node->val);
        m.insert(make_pair(node->val,newNode));
        q1.push(newNode);
        q2.push(node);
        while(!q1.empty())
        {
            Node* n1 = q1.front();
            q1.pop();
            Node* n2 = q2.front();
            q2.pop();
            for(int i=0; i<n2->neighbors.size(); i++)
            {
                if(m.count(n2->neighbors[i]->val))
                {
                    n1->neighbors.push_back(m[n2->neighbors[i]->val]);
                }
                else
                {
                    Node* nn = new Node(n2->neighbors[i]->val);
                    m.insert(make_pair(nn->val,nn));
                    n1->neighbors.push_back(nn);
                    q1.push(m[n2->neighbors[i]->val]);
                    q2.push(n2->neighbors[i]);
                }
            }
        }
        return newNode;
    }
};