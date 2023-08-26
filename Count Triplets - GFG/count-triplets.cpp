//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    int ans = 0;
    vector<int> vec;
    while(head&&head->data>=x) head = head->next;
    while(head)
    {
        vec.push_back(head->data);
        // cout<<vec.back()<<" ";
        head = head->next;
    }
    // cout<<endl;
    int n = vec.size();
    for(int i=0; i<n; i++)
    {
        int l = i+1, r = n-1;
        while(l<r)
        {
            int sum = vec[i] + vec[l] + vec[r];
            // cout<<i<<" "<<l<<" "<<r<<" "<<sum<<endl;
            if(sum==x)
            {
                ans++;
                l++;
                r--;
            }
            else if(sum>x) r--;
            else l++;
        }
    }
    return ans;
} 