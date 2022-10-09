class Solution {
public:

    // bool b(unordered_set<string>& dict, string s)
    // {
    //     if(dict.count(s)) return true;
    //     int n = s.length();
    //     for(int i=1; i<n; i++)
    //     {
    //         bool flag = b(dict,s.substr(0,i)) && b(dict,s.substr(i,n-i));
    //         if(flag) return true;
    //     }
    //     return false;
    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_set<string> dict;
        for(int i=0; i<n; i++)
        dict.insert(wordDict[i]);
        n = s.size();
        bool dp[n+1];
        memset(dp,false,n);
        dp[n] = true;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=1; j<=n-i; j++)
            {
                if(dict.count(s.substr(i,j)) && dp[i+j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
        // return b(dict,s);
    }
};