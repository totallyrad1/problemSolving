class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        vector<vector<string>> res;
        for(auto &str: strs){
            string cp = str;
            sort(cp.begin(), cp.end());
            anagrams.insert({cp, {}});
        }
        for(auto &str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(anagrams.find(tmp) != anagrams.end())
                anagrams[tmp].push_back(str);
        }
        for(auto &[key,value]: anagrams){
            res.push_back(value);
        }
        return res;
    }
};