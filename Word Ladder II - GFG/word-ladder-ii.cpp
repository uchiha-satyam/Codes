//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void traverse(int ew, int& bw, vector<int>& st, vector<vector<int>>& par, vector<vector<string>>& ans, vector<string>& wl)
    {
        st.push_back(ew);
        if(ew==bw)
        {
            vector<string> vec;
            for(int i=st.size()-1; i>=0; i--) vec.push_back(wl[st[i]]);
            ans.push_back(vec);
        }
        else
        {
            for(auto& x : par[ew]) traverse(x,bw,st,par,ans,wl);
        }
        st.pop_back();
    }
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        map<string,int> mp;
        int n = wordList.size(), m = wordList[0].size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                char ch = wordList[i][j];
                for(char rp='a'; rp<='z'; rp++)
                {
                    wordList[i][j] = rp;
                    if(mp.count(wordList[i]))
                    {
                        adj[i].push_back(mp[wordList[i]]);
                        adj[mp[wordList[i]]].push_back(i);
                    }
                }
                wordList[i][j] = ch;
            }
            mp[wordList[i]] = i;
        }
        if(!mp.count(beginWord))
        {
            wordList.push_back(beginWord);
            adj.push_back(vector<int>());
            int i = n;
            n++;
            for(int j=0; j<m; j++)
            {
                char ch = wordList[i][j];
                for(char rp='a'; rp<='z'; rp++)
                {
                    wordList[i][j] = rp;
                    if(mp.count(wordList[i]))
                    {
                        adj[i].push_back(mp[wordList[i]]);
                        adj[mp[wordList[i]]].push_back(i);
                    }
                }
                wordList[i][j] = ch;
            }
            mp[wordList[i]] = i;
        }
        vector<int> dist(n,INT_MAX);
        dist[mp[beginWord]] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,mp[beginWord]});
        vector<bool> vis(n,false);
        vector<vector<int>> par(n);
        while(!pq.empty())
        {
            int node = pq.top().second;
            int val = dist[node];
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            for(auto& x : adj[node])
            {
                if(vis[x]||dist[x]<val+1) continue;
                if(dist[x]>val+1) par[x].clear();
                par[x].push_back(node);
                dist[x] = val+1;
                pq.push({dist[x],x});
            }
        }
        // cout<<dist[0]<<" "<<par[0].size()<<" "<<dist[1]<<" "<<par[1].size()<<endl;
        vector<int> st;
        vector<vector<string>> ans;
        if(!mp.count(endWord)) return ans;
        traverse(mp[endWord],mp[beginWord],st,par,ans,wordList);
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends