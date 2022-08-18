class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(m.count(s[i]))
            {
                if(m[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                if(st.count(t[i])) return false;
                m.insert(make_pair(s[i],t[i]));
                st.insert(t[i]);
            }
        }
        return true;
    }
};