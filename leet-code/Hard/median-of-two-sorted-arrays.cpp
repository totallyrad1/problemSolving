class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        int mid = (size) / 2;
        if(size % 2 != 0)
            return nums1[mid];
        else
            return (nums1[mid-1] + nums1[mid]) / 2.0;
    }
};