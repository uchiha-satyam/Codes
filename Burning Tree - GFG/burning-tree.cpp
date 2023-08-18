//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    int getDist(Node* root, unordered_map<Node*,int>& mp, int& target, bool& flag)
    {
        if(root==NULL) return 0;
        if(root->data==target)
        {
            flag = true;
            mp[root] = 0;
            return 1;
        }
        int d = getDist(root->left,mp,target,flag);
        if(flag)
        {
            mp[root] = d;
            return d+1;
        }
        d = getDist(root->right,mp,target,flag);
        if(flag)
        {
            mp[root] = d;
            return d+1;
        }
        return 0;
    }
    void traverse(Node* root, unordered_map<Node*,int>& mp, int count, int& ans)
    {
        if(root==NULL) return;
        if(mp.count(root)) count = mp[root];
        else count++;
        mp[root] = count;
        ans = max(ans,count);
        traverse(root->left,mp,count,ans);
        traverse(root->right,mp,count,ans);
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,int> mp;
        bool flag = false;
        int ans = 0;
        getDist(root,mp,target,flag);
        traverse(root,mp,0,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends