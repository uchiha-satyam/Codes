//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    unordered_map<int,int> data, qnum;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> lru;
    int q;
    int size;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        size = cap;
        q = 0;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(!data.count(key)) return -1;
        q++;
        lru.push({q,key});
        qnum[key] = q;
        return data[key];
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        q++;
        lru.push({q,key});
        qnum[key] = q;
        data[key] = value;
        if(data.size()>size)
        {
            while(qnum[lru.top().second]>lru.top().first) lru.pop();
            int lrKey = lru.top().second;
            data.erase(lrKey);
            lru.pop();
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends