//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even = NULL;
        Node* odd = new Node(-1);
        odd->next = head;
        while(odd->next&&(odd->next->data)%2==0)
        {
            even = odd->next;
            odd = odd->next;
        }
        if(!odd) return head;
        while(odd->next)
        {
            if((odd->next->data)%2)
            {
                odd = odd->next;
                continue;
            }
            Node* n = odd->next;
            odd->next = odd->next->next;
            if(!even)
            {
                if(n!=head) n->next = head;
                head = n;
                even = n;
            }
            else
            {
                n->next = even->next;
                even->next = n;
                even = even->next;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends