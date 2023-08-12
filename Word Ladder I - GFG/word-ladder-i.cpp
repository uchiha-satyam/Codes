//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st;
        for(auto& x : wordList)
        st.insert(x);
        if(!st.count(targetWord)) return 0;
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> dist;
        for(auto& x : st)
        {
            dist[x] = INT_MAX;
            for(int i=0; i<x.size(); i++)
            {
                char org = x[i];
                for(char ch = 'a'; ch<='z'; ch++)
                {
                    if(ch==org) continue;
                    string n = x.substr(0,i)+ch+x.substr(i+1);
                    if(st.count(n)) adj[x].push_back(n);
                }
            }
        }
        if(!st.count(startWord))
        {
            string& x = startWord;
            for(int i=0; i<x.size(); i++)
            {
                char org = x[i];
                for(char ch = 'a'; ch<='z'; ch++)
                {
                    if(ch==org) continue;
                    string n = x.substr(0,i)+ch+x.substr(i+1);
                    if(st.count(n)) adj[x].push_back(n);
                }
            }
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        st.clear();
        dist[startWord] = 1;
        pq.push({1,startWord});
        while(!pq.empty())
        {
            string s = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            if(st.count(s)) continue;
            st.insert(s);
            for(auto& x : adj[s])
            {
                if(st.count(x)) continue;
                if(val+1<dist[x])
                {
                    dist[x] = val+1;
                    pq.push({dist[x],x});
                }
            }
        }
        return (dist[targetWord]==INT_MAX) ? 0 : dist[targetWord];
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends