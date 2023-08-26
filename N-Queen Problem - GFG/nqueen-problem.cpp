//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void putQueen(vector<bool>& ls, vector<bool>& lu, vector<bool>& ld, int r, int c, int n)
    {
        ls[r] = false;
        lu[r+n-1-c] = false;
        ld[r+c] = false;
    }
    void popQueen(vector<bool>& ls, vector<bool>& lu, vector<bool>& ld, int r, int c, int n)
    {
        ls[r] = true;
        lu[r+n-1-c] = true;
        ld[r+c] = true;
    }
    bool checkQueen(vector<bool>& ls, vector<bool>& lu, vector<bool>& ld, int r, int c, int n)
    {
        return ls[r] && lu[r+n-1-c] && ld[r+c];
    }
    void traverse(vector<vector<int>>& ans, vector<int>& vec, int& n, vector<bool>& ls, vector<bool>& lu, vector<bool>& ld, int c)
    {
        if(c==n)
        {
            ans.push_back(vec);
            return;
        }
        for(int r=0; r<n; r++)
        {
            if(checkQueen(ls,lu,ld,r,c,n))
            {
                putQueen(ls,lu,ld,r,c,n);
                vec.push_back(r+1);
                traverse(ans,vec,n,ls,lu,ld,c+1);
                vec.pop_back();
                popQueen(ls,lu,ld,r,c,n);
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<bool> ls(n,true), lu(2*n-1,true), ld(2*n-1,true);
        vector<vector<int>> ans;
        vector<int> vec;
        traverse(ans,vec,n,ls,lu,ld,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends