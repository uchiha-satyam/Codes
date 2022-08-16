class Solution {
public:
    void reverseString(vector<char>& st) {
        int s = 0, e = st.size()-1;
        while(s<e)
        {
            swap(st[s],st[e]);
            s++;
            e--;
        }
    }
};