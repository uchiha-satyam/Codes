//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    vector<int> rn;
    unordered_set<string> s;
    for(int i=0; i<row; i++)
    {
        string str = "";
        for(int j=0; j<col; j++)
        {
            str += '0'+M[i][j];
        }
        if(!s.count(str))
        {
            s.insert(str);
            rn.push_back(i);
        }
    }
    vector<vector<int>> ans(rn.size());
    for(int i=0; i<rn.size(); i++)
    {
        ans[i] = vector<int>(M[rn[i]],M[rn[i]]+col);
    }
    return ans;
}