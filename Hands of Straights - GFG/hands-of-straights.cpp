//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize!=0) return false;
        if(groupSize==1) return true;
        vector<pair<int,int>> vec;
        int pos = -1, start = 0;
        sort(hand.begin(),hand.end());
        for(int i=0; i<N; i++)
        {
            if(vec.size()==start)
            {
                vec.push_back(make_pair(hand[i],1));
            }
            else
            {
                if(vec[pos].first==hand[i])
                {
                    vec.push_back(make_pair(hand[i],1));
                }
                else if(vec[pos].first+1!=hand[i])
                {
                    return false;
                }
                else
                {
                    vec[pos].first = hand[i];
                    vec[pos].second++;
                    if(vec[pos].second==groupSize) start++;
                }
            }
            pos++;
            if(pos==vec.size()) pos = start;
        }
        if(vec.size()==start) return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends