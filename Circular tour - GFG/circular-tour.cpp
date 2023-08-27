//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        //Your code here
        int total = 0, sum = 0, pos = 0;
        for(int i=0; i<2*n; i++)
        {
            if(i<n) total += p[i].petrol - p[i].distance;
            sum += p[i%n].petrol - p[i%n].distance;
            if(sum<0)
            {
                pos = (i+1)%n;
                sum = 0;
            }
        }
        if(total>=0&&sum>=total) return pos;
        return -1;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends