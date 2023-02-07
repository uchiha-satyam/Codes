class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cl=0, c=0, p=0;
        vector<int> v, f(2,-1);
        int n = fruits.size();
        for(int i=0; i<n; i++)
        {
            int fr = fruits[i];
            if(fr!=f[0]&&fr!=f[1])
            {
                f[p] = fr;
                v.push_back(c);
                c = cl + 1;
                cl = 1;
                p = !p;
            }
            else
            {
                c++;
                cl++;
                if(fr==f[p])
                {
                    cl = 1;
                    p = !p;
                }
            }
        }
        v.push_back(c);
        int ans = 0;
        for(int i=0; i<v.size(); i++)
        ans = max(ans,v[i]);
        return ans;
    }
};