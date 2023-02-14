class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int rem = 0;
        int p1 = a.size()-1, p2 = b.size()-1;
        while(p1>=0||p2>=0)
        {
            char ac = '0', bc = '0';
            if(p1>=0)
            {
                ac = a[p1];
                p1--;
            }
            if(p2>=0)
            {
                bc = b[p2];
                p2--;
            }
            if(rem)
            {
                if(ac=='1'&&bc=='1')
                {
                    ans = "1" + ans;
                    rem = 1;
                }
                else if(ac=='0'&&bc=='0')
                {
                    ans = '1' + ans;
                    rem = 0;
                }
                else
                {
                    ans = '0' + ans;
                    rem = 1;
                }
            }
            else
            {
                if(ac=='1'&&bc=='1')
                {
                    ans = "0" + ans;
                    rem = 1;
                }
                else if(ac=='0'&&bc=='0')
                {
                    ans = "0" + ans;
                    rem = 0;
                }
                else
                {
                    ans = "1" + ans;
                    rem = 0;
                }
            }
        }
        if(rem) ans = "1" + ans;
        return ans;
    }
};