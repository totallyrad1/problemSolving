class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int size = 1;
        int left = 0;
        int right = 1;
        set<char> wayeh;
        wayeh.insert(s[left]);
        int res = 0;
        while(right < s.size()){
            if(wayeh.count(s[right])){
                if(right - left > res)
                    res = right - left;
                wayeh.erase(s[left]);
                left++;
            }else{
                wayeh.insert(s[right]);
                right++;
            }
        }
        if(right - left > res)
            res = right-left;
        return res; 
    }
};