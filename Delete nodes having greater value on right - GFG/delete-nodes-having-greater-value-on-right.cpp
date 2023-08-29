//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        while(head)
        {
            Node* t = head->next;
            head->next = prev;
            prev = head;
            head = t;
        }
        return prev;
    }
    void print(Node* head)
    {
        while(head)
        {
            cout<<head->data<<"->";
            head = head->next;
        }
        cout<<"END"<<endl;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        int val = INT_MIN;
        Node* prev = NULL;
        Node* org = head;
        while(head)
        {
            if(head->data<val)
            {
                Node* t = head;
                prev->next = head->next;
                head = prev;
                delete t;
            }
            val = max(val,head->data);
            prev = head;
            head = head->next;
        }
        org = reverse(org);
        return org;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends