class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int s=0, e=0, p=1;
        if(str=="") return 0;
        int ml = 1;
        while(p<str.length())
        {
            string ss = str.substr(s,e-s+1);
            int pos = ss.find(str[p]);
            if(pos!=-1)
            {
                s+=pos+1;
            }
            e++;
            ml = max(ml,e-s+1);
            p++;
        }
        return ml;
    }
};