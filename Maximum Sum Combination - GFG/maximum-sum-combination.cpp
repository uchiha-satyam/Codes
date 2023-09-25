//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<pair<int,pair<int,int>>> p_q;
        vector<int> ans;
        p_q.push({a[n-1]+b[n-1],{n-1,n-1}});
        set<pair<int,int>> s;
        s.insert({n-1,n-1});
        while(k--){
            pair<int,pair<int,int>> p;
            p=p_q.top();
            p_q.pop();
            ans.push_back(p.first);
            int i=p.second.first,j=p.second.second;
            if(i-1>=0){
                if((s.find(make_pair(i-1,j)))==s.end()){
                    s.insert({i-1,j});
                    p_q.push({a[i-1]+b[j],{i-1,j}});
                }
            }
            if(j-1>=0){
                if((s.find(make_pair(i,j-1)))==s.end()){
                    s.insert({i,j-1});
                    p_q.push({a[i]+b[j-1],{i,j-1}});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends