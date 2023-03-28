//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node* p1=head1, * p2=head2;
    Node* head = NULL;
    Node* temp = head;
    while(p1&&p2)
    {
        if(p1->data==p2->data)
        {
            Node* n = new Node(p1->data);
            if(temp==NULL)
            {
                head = temp = n;
            }
            else
            {
                temp->next = n;
                temp = temp->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->data<p2->data)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
    return head;
}