class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> sol;
        int s = 1, e = numbers.size();
        while(s<e)
        {
            int sum = numbers[s-1]+numbers[e-1];
            if(sum==target)
            {
                sol.push_back(s);
                sol.push_back(e);
                break;
            }
            else if(sum<target) s++;
            else e--;
        }
        return sol;
    }
};