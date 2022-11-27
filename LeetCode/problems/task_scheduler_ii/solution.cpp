class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n = tasks.size();
        unordered_map<int,int> m;
        vector<long long> pp(n,-1);
        long long count=0;
        for(int i=0; i<n; i++)
        {
            if(m.count(tasks[i]))
            {
                if(count-pp[m[tasks[i]]]>=space) count++;
                else count += space - count + pp[m[tasks[i]]] + 1;
                pp[i] = count;
                m[tasks[i]] = i;
            }
            else
            {
                count++;
                pp[i] = count;
                m[tasks[i]] = i;
            }
        }
        return count;
    }
};