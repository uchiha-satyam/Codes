class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length()) return ans;
        vector<int> occ(26,0);
        for(int i=0; i<p.length(); i++)
        {
            occ[p[i]-'a']++;
        }
        int flag = 0;
        int si = 0, ei = p.length()-1;
        for(int i=0; i<p.length(); i++)
        {
            occ[s[i]-'a']--;
            if(occ[s[i]-'a']!=0)
            flag = flag|(1<<(s[i]-'a'));
            else
            flag = flag&(~(1<<(s[i]-'a')));
            // cout<<flag<<endl;
        }
        if(flag==0) ans.push_back(si);
        si++;
        ei++;
        while(ei<s.length())
        {
            occ[s[si-1]-'a']++;
            if(occ[s[si-1]-'a']!=0)
            flag = flag|(1<<(s[si-1]-'a'));
            else
            flag = flag&(~(1<<(s[si-1]-'a')));
            occ[s[ei]-'a']--;
            if(occ[s[ei]-'a']!=0)
            flag = flag|(1<<(s[ei]-'a'));
            else
            flag = flag&(~(1<<(s[ei]-'a')));
            if(flag==0) ans.push_back(si);
            si++;
            ei++;
        }
        return ans;
    }
};