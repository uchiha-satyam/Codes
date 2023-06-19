class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool flag = !s.count(val);
        s.insert(val);
        return flag;
    }
    
    bool remove(int val) {
        bool flag = s.count(val);
        s.erase(val);
        return flag;
    }
    
    int getRandom() {
        int r = rand()%s.size();
        auto it = s.begin();
        advance(it,r);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */