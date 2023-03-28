//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    int sm(Node* root)
    {
        if(root==NULL) return 0;
        int d1 = sm(root->left);
        int d2 = sm(root->right);
        if(d1==0) return d2 + root->data;
        if(d2==0) return d1 + root->data;
        return min(d1,d2) + root->data;
    }
    int b(Node* root,int& target, int& sum)
    {
        if(root==NULL) return -1;
        if(root->data==target)
        {
            // int d1 = abs(sum-(sm(root)-root->data));
            // int d2 = abs(sum-(sM(root)-root->data));
            // cout<<sm(root)<<endl;
            return sum-(sm(root)-root->data);
        }
        sum += root->data;
        int d1 = b(root->left,target,sum);
        int d2 = b(root->right,target,sum);
        if(d1!=-1) return d1;
        if(d2!=-1) return d2;
        sum -= root->data;
        return -1;
    }
public:
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum = 0;
        return b(root,target,sum);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends