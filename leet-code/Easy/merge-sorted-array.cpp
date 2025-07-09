class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i < m || j < n){
            if(i < m && j < n){
                if(nums1[i] > nums2[j]){
                    res.push_back(nums2[j]);
                    j++;
                }else{
                    res.push_back(nums1[i]);
                    i++;
                }
            }else{
                if(i < m){
                    res.push_back(nums1[i]);
                    i++;
                }else{
                    res.push_back(nums2[j]);
                    j++;
                }
            }
        }
        nums1 = res;
    }
};