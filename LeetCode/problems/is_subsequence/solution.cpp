class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si=0, ti=0;
        while(ti<t.length()&&si<s.length())
        {
            if(t[ti]==s[si])
            {
                si++;
            }
            ti++;
        }
        if(si==s.length()) return true;
        else return false;
    }
};