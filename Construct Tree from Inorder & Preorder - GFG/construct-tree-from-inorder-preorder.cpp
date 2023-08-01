//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    Node* build(int in[], int pre[], int& pi, int str, int end, int& n)
    {
        if(pi>=n||str>end) return NULL;
        pi++;
        Node* node = new Node(pre[pi]);
        int idx = str;
        for(; idx<=end; idx++)
        if(in[idx]==pre[pi]) break;
        node->left = build(in,pre,pi,str,idx-1,n);
        node->right = build(in,pre,pi,idx+1,end,n);
        return node;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int pi = -1;
        return build(in,pre,pi,0,n-1,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends