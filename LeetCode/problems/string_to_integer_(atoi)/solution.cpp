class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        bool neg = false;
        int pos = 0;
        while(pos<s.length() && s[pos]==' ')
        {
            pos++;
        }
        if(pos<s.length() && (s[pos]=='+' || s[pos]=='-'))
        {
            neg = (s[pos]=='-') ? true : false;
            pos++;
        }
        while(pos<s.length() && s[pos]=='0')
        pos++;
        int temp = pos;
        while(temp<s.length() && s[temp]-'0'<10 && s[temp]-'0'>=0)
        temp++;
        int len = temp - pos;
        if(len>10)
        {
            return (neg)?INT_MIN:INT_MAX;
        }
        if(len<10)
        {
            while(pos<s.length() && s[pos]-'0'<10 && s[pos]-'0'>=0)
            {
                ans = ans*10 + (s[pos]-'0');
                pos++;
            }
        }
        else
        {
            vector<int> lim;
            string limit = "2147483647";
            for(int i=0; i<9; i++)
            lim.push_back(limit[i]-'0');
            if(neg)
            lim.push_back(8);
            else
            lim.push_back(7);
            bool flag = true;
            for(int i=0; i<10; i++)
            {
                int digit = s[pos] - '0';
                if(digit<lim[i])
                flag = false;
                if(digit>lim[i] && flag)
                {
                    if(neg)
                    ans = -2147483648;
                    else
                    ans = 2147483647;
                    return ans;
                }
                else
                {
                    if(i==9 && digit==8 && flag) return INT_MIN;
                    ans = ans*10 + digit;
                }
                pos++;
            }
        }
        return (neg)?-1*ans:ans;
    }
};