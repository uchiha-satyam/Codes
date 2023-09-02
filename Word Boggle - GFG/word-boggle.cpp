//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class trie
{
    public:
    unordered_map<char,trie*> child;
    bool isLeaf;
    trie()
    {
        isLeaf = false;
    }
};

void insert(string s, trie* root)
{
    if(s.empty())
    {
        root->isLeaf = true;
        return;
    }
    if(!root->child.count(s[0])) root->child[s[0]] = new trie();
    root = root->child[s[0]];
    insert(s.substr(1),root);
}

void search(string& s, trie* root, int moves[8][2], int x, int y, int& n, int& m, vector<vector<char>>& board, vector<vector<bool>>& visited, unordered_set<string>& ans)
{
    if(root->isLeaf) ans.insert(s);
    if(x<0||y<0||x>=n||y>=m||visited[x][y]||!root->child.count(board[x][y])) return;
    visited[x][y] = true;
    s.push_back(board[x][y]);
    root = root->child[board[x][y]];
    for(int i=0; i<8; i++)
    {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        search(s,root,moves,nx,ny,n,m,board,visited,ans);
    }
    s.pop_back();
    visited[x][y] = false;
}

class Solution {
public:
	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
	    trie* root = new trie();
	    for(auto& x : dictionary) insert(x,root);
	    int n = board.size(), m = board[0].size();
	    int moves[8][2] = {
	        {0,1},
	        {1,0},
	        {0,-1},
	        {-1,0},
	        {1,1},
	        {-1,-1},
	        {1,-1},
	        {-1,1}
	    };
	    vector<vector<bool>> visited(n,vector<bool>(m,false));
	    unordered_set<string> ans;
	    string s = "";
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            search(s,root,moves,i,j,n,m,board,visited,ans);
	        }
	    }
	    vector<string> res(ans.begin(),ans.end());
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends