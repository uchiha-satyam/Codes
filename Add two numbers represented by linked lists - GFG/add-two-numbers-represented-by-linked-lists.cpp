//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* prev = NULL;
        while(first)
        {
            Node* n = first->next;
            first->next = prev;
            prev = first;
            first = n;
        }
        first = prev;
        prev = NULL;
        while(second)
        {
            Node* n = second->next;
            second->next = prev;
            prev = second;
            second = n;
        }
        second = prev;
        prev = NULL;
        int rem = 0;
        while(first||second||rem)
        {
            int sum = rem;
            if(first)
            {
                sum += first->data;
                first = first->next;
            }
            if(second)
            {
                sum += second->data;
                second = second->next;
            }
            rem = sum/10;
            sum = sum%10;
            Node* n = new Node(sum);
            n->next = prev;
            prev = n;
        }
        return prev;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends