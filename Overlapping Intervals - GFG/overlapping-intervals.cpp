//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> s(n), e(n);
        for(int i=0; i<n; i++)
        {
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int c=0, p1=0, p2=0, p=0;
        vector<vector<int>> ans;
        ans.push_back(vector<int>(1,s[p1]));
        p1++;
        c++;
        while(p1<n)
        {
            int mv, is;
            if(s[p1]<e[p2])
            {
                mv = s[p1];
                is = 1;
                p1++;
            }
            else if(s[p1]>e[p2])
            {
                mv = e[p2];
                is = -1;
                p2++;
            }
            else
            {
                mv = s[p1];
                is = 0;
                p1++;
                p2++;
            }
            c += is;
            // if(p1>n-4) cout<<c<<" "<<mv<<" "<<is<<endl;
            if(c==0)
            {
                if(is!=0)
                {
                    ans.back().push_back(mv);
                    p=1;
                }
                else
                {
                    if(ans.back()[0]==mv&&ans.back()[1]==mv) continue;
                    ans.push_back(vector<int>(2,mv));
                    p=1;
                }
            }
            if(c==1&&is==1)
            {
                if(ans.back()[0]==mv)
                {
                    ans.back().pop_back();
                }
                else
                ans.push_back(vector<int>(1,mv));
                p=0;
            }
        }
        if(p) ans.back()[1] = e.back();
        else ans.back().push_back(e.back());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends