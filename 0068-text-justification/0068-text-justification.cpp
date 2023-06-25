class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> sentence, ans;
        int curr = 0, pos = 0, n = words.size();
        while(pos<n)
        {
            sentence.push_back(words[pos]);
            if(curr!=0) curr += 1;
            curr += words[pos].length();
            pos++;
            if(curr>maxWidth||pos==n)
            {
                if(curr>maxWidth)
                {
                    sentence.pop_back();
                    pos--;
                    curr -= words[pos].length() + 1;
                }
                int extra = maxWidth - curr;
                if(sentence.size()==1||pos==n)
                {
                    string str = "";
                    for(int i=0; i<sentence.size(); i++)
                        str += sentence[i] + " ";
                    str.pop_back();
                    for(int i=0; i<extra; i++)
                        str += " ";
                    ans.push_back(str);
                }
                else
                {
                    string str = "";
                    int d = extra/(sentence.size()-1), r = extra%(sentence.size()-1);
                    for(int i=0; i<sentence.size(); i++)
                    {
                        str += sentence[i];
                        if(i==sentence.size()-1) continue;
                        for(int j=0; j<=d; j++)
                            str += " ";
                        if(i<r) str += " ";
                    }
                    ans.push_back(str);
                }
                sentence.clear();
                curr = 0;
            }
        }
        return ans;
    }
};