class Solution {
public:
    int64_t nthUglyNumber(int n) {
        set<int64_t> result;
        result.insert(1);
        int64_t count = 1;
        set<int64_t>::iterator it = result.begin();
        while(count!=n)
        {
            result.insert(*it * 2);
            result.insert(*it * 3);
            result.insert(*it * 5);
            it++;
            count++;
        }
        return *it;
    }
};