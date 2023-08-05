//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
    public:
    Node* traverse(string& s, int& i)
    {
        if(i>=s.size()) return NULL;
        if(s[i]==')')
        {
            i++;
            return NULL;
        }
        int x = 0;
        while(s[i]-'0'>=0&&s[i]-'0'<=9)
        {
            x = x*10 + (s[i]-'0');
            i++;
        }
        Node* node = new Node(x);
        if(s[i]=='(')
        {
            i++;
            node->left = traverse(s,i);
        }
        if(s[i]==')')
        {
          i++;
          return node;
        }
        if(s[i]=='(')
        {
            i++;
            node->right = traverse(s,i);
        }
        if(s[i]==')')
        {
            i++;
            return node;
        }
        return node;
    }
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        int i=0;
        return traverse(str,i);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends