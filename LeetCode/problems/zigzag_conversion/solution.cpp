class Solution {
public:
    string convert(string s, int r) {
        string newS = "";
        if(r==1) return s;
        int a = 1, b = 0, pos = 0;
        for(int i=0; i<=(r-1)/2; i++)
        {
            pos = i;
            while(pos<s.size())
            {
                newS.push_back(s[pos]);
                // cout<<pos<<" ";
                pos += 2*(r-a);
                if(b!=0 && pos<s.size())
                {
                    newS.push_back(s[pos]);
                    // cout<<pos<<" ";
                    pos += b;
                }
            }
            // cout<<endl;
            b += 2;
            a += 1;
        }
        // cout<<2 + 2*(r%2!=0)<<endl;
        b -= 2 + 2*(r%2!=0);
        a -= 1 + 1*(r%2!=0);
        for(int i=(r+1)/2; i<r; i++)
        {
            pos = i;
            // cout<<endl<<"A = "<<a<<endl;
            while(pos<s.size())
            {
                if(b!=0)
                {
                    newS.push_back(s[pos]);
                    // cout<<pos<<"/";
                    pos += b;
                }
                if(pos<s.size())
                {
                    // cout<<pos<<" ";
                    newS.push_back(s[pos]);
                }
                pos += 2*(r-a);
            }
            // cout<<endl;
            b -= 2;
            a -= 1;
        }
        return newS;
    }
};