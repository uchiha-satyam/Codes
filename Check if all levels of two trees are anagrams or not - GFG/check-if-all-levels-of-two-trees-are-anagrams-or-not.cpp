//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*> q;
        q.push(root1);
        q.push(NULL);
        vector<unordered_map<int,int>> v1(1), v2(1);
        while(!q.empty())
        {
            Node* n = q.front();
            q.pop();
            if(n==NULL)
            {
                if(q.empty()) break;
                q.push(NULL);
                v1.push_back(unordered_map<int,int>());
                continue;
            }
            v1.back()[n->data]++;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        q = queue<Node*>();
        q.push(root2);
        q.push(NULL);
        while(!q.empty())
        {
            Node* n = q.front();
            q.pop();
            if(n==NULL)
            {
                if(q.empty()) break;
                q.push(NULL);
                v2.push_back(unordered_map<int,int>());
                continue;
            }
            v2.back()[n->data]++;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        if(v1.size()!=v2.size()) return false;
        for(int i=0; i<v1.size(); i++)
        {
            for(auto& x : v1[i])
            {
                if(x.second!=v2[i][x.first]) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends