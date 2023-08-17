//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> pos(k,0);
        int maxVal = 0;
        for(int i=0; i<k; i++)
        {
            pq.push({KSortedArray[i][0],i});
            maxVal = max(maxVal,KSortedArray[i][0]);
        }
        int minRange = INT_MAX;
        pair<int,int> ans;
        while(true)
        {
            int minVal = pq.top().first;
            int listNum = pq.top().second;
            if(maxVal-minVal<minRange)
            {
                minRange = maxVal - minVal;
                ans = {minVal,maxVal};
            }
            pq.pop();
            pos[listNum]++;
            if(pos[listNum]>=n) break;
            pq.push({KSortedArray[listNum][pos[listNum]],listNum});
            maxVal = max(maxVal,KSortedArray[listNum][pos[listNum]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends