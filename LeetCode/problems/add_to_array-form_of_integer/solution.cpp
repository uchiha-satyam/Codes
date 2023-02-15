class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int r = 0, p = 1, t=num.size()-1;
        while(k>0||r>0||t>=0)
        {
            int a = k%10;
            int b = 0;
            if(t>=0) b = num[t];
            r = (r + b + a);
            if(t>=0)
            num[t] = r%10;
            else
            num.insert(num.begin(),r%10);
            r /= 10;
            t--;
            k /= 10;
        }
        return num;
    }
};