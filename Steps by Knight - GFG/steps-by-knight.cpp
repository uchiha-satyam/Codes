//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int moves[8][2] = {
	        {-2,1},
	        {-1,2},
	        {1,2},
	        {2,1},
	        {2,-1},
	        {1,-2},
	        {-1,-2},
	        {-2,-1}
	    };
	    TargetPos[0] -= 1;
	    TargetPos[1] -= 1;
	    KnightPos[0] -= 1;
	    KnightPos[1] -= 1;
	    vector<vector<int>> data(N,vector<int>(N,INT_MAX));
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    q.push({-1,-1});
	    int c = 0;
	    while(!q.empty())
	    {
	        pair<int,int> node = q.front();
	        q.pop();
	        if(node.first==-1)
	        {
	            if(q.empty()) break;
	            q.push({-1,-1});
	            c++;
	            continue;
	        }
	        if(data[node.first][node.second]!=INT_MAX) continue;
	        data[node.first][node.second] = c;
	        for(int i=0; i<8; i++)
	        {
	            int ni = node.first + moves[i][0];
	            int ny = node.second + moves[i][1];
	            if(ni>=0&&ni<N&&ny>=0&&ny<N)
	            q.push({ni,ny});
	        }
	    }
	    return (data[TargetPos[0]][TargetPos[1]]==INT_MAX) ? -1 : data[TargetPos[0]][TargetPos[1]];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends