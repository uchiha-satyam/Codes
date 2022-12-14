class Solution {
public:
    int reverse(int x) {
        bool neg = (x<0)?true:false;
        string s = to_string(abs(x));
        std::reverse(s.begin(),s.end());
        if(s.length()<10 || s[0] == '0')
        {
            int ans = stoi(s);
            if(neg) ans *= -1;
            return ans;
        }
        else
        {
            vector<int> lim;
            lim.push_back(2);
            lim.push_back(1);
            lim.push_back(4);
            lim.push_back(7);
            lim.push_back(4);
            lim.push_back(8);
            lim.push_back(3);
            lim.push_back(6);
            lim.push_back(4);
            if(neg)
            lim.push_back(8);
            else
            lim.push_back(7);
            int ans = 0;
            bool flag = true;
            for(int i=0; i<10; i++)
            {
                int digit = s[i] - '0';
                if(digit<lim[i]) flag = false;
                if(digit>lim[i] && flag)
                {
                    return 0;
                }
                else
                {
                    ans = 10*ans + digit;
                }
            }
            if(neg) ans *= -1;
            return ans;
        }
    }
};