class TimeMap {
public:
    map<string, vector<pair<int, string>>> db;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        auto &mp = db[key];
        int left = 0, right =  mp.size() - 1, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (mp[mid].first <= timestamp) {
                ans = mp[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (ans);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */