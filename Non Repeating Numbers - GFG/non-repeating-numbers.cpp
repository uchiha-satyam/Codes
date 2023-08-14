//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int o=0, e=0;
        int mask = 1;
        while(e==0||o==0)
        {
            e=0, o=0;
            for(auto& n : nums)
            {
                if(n&mask) o = o^n;
                else e = e^n;
            }
            mask *= 2;
        }
        vector<int> ans(2);
        ans[0] = min(o,e);
        ans[1] = max(o,e);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends