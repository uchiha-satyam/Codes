//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL) return head;
        node* temp = head;
        for(int i=1; i<k && temp->next!=NULL; i++)
            temp = temp->next;
        node* prev = head;
        while(head!=NULL)
        {
            vector<node*> vec(k,NULL);
            for(int i=0; i<k && head!=NULL; i++)
            {
                vec[i] = head;
                head = head->next;
            }
            bool flag = true;
            for(int i=k-1; i>=0; i--)
            {
                if(i==0&&flag)
                {
                    prev->next = vec[0];
                    flag = false;
                    break;
                }
                if(vec[i]!=NULL)
                {
                    vec[i]->next = vec[i-1];
                    if(flag&&prev!=NULL)
                    {
                        prev->next = vec[i];
                        flag = false;
                    }
                }
            }
            prev = vec[0];
        }
        if(prev!=NULL) prev->next = NULL;
        return temp;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends