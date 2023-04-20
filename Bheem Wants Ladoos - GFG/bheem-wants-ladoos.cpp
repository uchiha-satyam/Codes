//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
    void get(Node* root, Node* p, unordered_map<Node*,Node*>& parent, Node*& h, int& home)
    {
        if(root==NULL) return;
        parent[root] = p;
        if(root->data == home) h = root;
        get(root->left,root,parent,h,home);
        get(root->right,root,parent,h,home);
    }
    public:
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
        Node* h = NULL;
        get(root,NULL,parent,h,home);
        int ans = 0;
        queue<Node*> q;
        int c = 0;
        q.push(h);
        q.push(NULL);
        unordered_map<Node*,bool> visited;
        while(!q.empty())
        {
            Node* n = q.front();
            q.pop();
            if(n==NULL)
            {
                c++;
                if(q.empty()||c>k) break;
                q.push(NULL);
                continue;
            }
            visited[n] = true;
            ans += n->data;
            if(n->left&&!visited[n->left]) q.push(n->left);
            if(n->right&&!visited[n->right]) q.push(n->right);
            if(parent[n]&&!visited[parent[n]]) q.push(parent[n]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends