class MyCalendar {
    map<int,char> mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto low = mp.lower_bound(start);
        auto up = mp.upper_bound(start);
        if(low==up)
        {
            if(up!=mp.end()&&(up->second=='e'||up->first<end)) return false;
            mp[start] = 's';
            mp[end] = 'e';
            if(up!=mp.end()&&end==up->first) mp.erase(end);
            return true;
        }
        else
        {
            if(up!=mp.end()&&(up->second=='e'||up->first<end)) return false;
            mp[end] = 'e';
            mp.erase(start);
            if(up!=mp.end()&&end==up->first) mp.erase(end);
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */