class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> arr1;
        set<int> arr2;
        for(auto &n: nums1){
            arr1.insert(n);
        }
        for(auto &n: nums2){
            arr2.insert(n);
        }
        vector<int> res;

        for(auto &n : arr1){
            if(arr2.count(n) > 0) res.push_back(n);
        }

        return res;

    }
};