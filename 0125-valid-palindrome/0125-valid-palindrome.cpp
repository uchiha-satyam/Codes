class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto& ch : s)
        {
            if((ch>=48&&ch<=57)||(ch>=97&&ch<=122))
                str += ch;
            else if(ch>=65&&ch<=90)
                str += ch + 32;
        }
        string rev = str;
        reverse(str.begin(),str.end());
        if(str==rev) return true;
        return false;
    }
};