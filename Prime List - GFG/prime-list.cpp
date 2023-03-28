//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
    public:
    vector<bool> prime;
    vector<int> lp, rp;
    Solution()
    {
        prime.resize(20001);
        for(int i=0; i<20001; i++) prime[i] = true;
        lp.resize(20001);
        rp.resize(20001);
    }
    void sieve()
    {
        for(int i=2; i<=140; i++)
        {
            for(int j=i; i*j<20001; j++)
            {
                prime[i*j] = false;
            }
        }
        prime[0] = false;
        prime[1] = false;
    }
    void set()
    {
        int l = INT_MIN + 10;
        for(int i=0; i<20001; i++)
        {
            if(prime[i]) l = i;
            lp[i] = l;
        }
        int r = 200007;
        for(int i=20000; i>=0; i--)
        {
            if(prime[i]) r = i;
            rp[i] = r;
        }
    }
public:
    Node *primeList(Node *head){
        sieve();
        set();
        Node* temp = head;
        while(temp)
        {
            int val = temp->val;
            // cout<<lp[val]<<" "<<rp[val]<<endl;
            if(abs(rp[val]-val)<abs(lp[val]-val))
            {
                temp->val = rp[val];
            }
            else
            {
                temp->val = lp[val];
            }
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends