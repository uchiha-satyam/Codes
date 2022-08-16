class Solution {
public:
    string reverseWords(string str) {
        int s=0, e=-1, pos=0;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]!=' ')
            {
                e++;
            }
            else
            {
                int l=s, r=e;
                while(l<r)
                {
                    swap(str[l],str[r]);
                    l++;
                    r--;
                }
                s = e+2;
                e++;
            }
        }
        int l=s, r=e;
        while(l<r)
        {
            swap(str[l],str[r]);
            l++;
            r--;
        }
        return str;
    }
};