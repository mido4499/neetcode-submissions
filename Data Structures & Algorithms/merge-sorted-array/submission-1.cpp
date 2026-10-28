class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(nums1.begin(), nums1.end());
        int i = 0, j = 0, k = 0;

        while (i < m && j < n){
            if (nums[i] <= nums2[j]){
                nums1[k] = nums[i];
                i++;
            }else{
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m){
            nums1[k] = nums[i];
            i++;k++;
        }
        while (j < n){
            nums1[k] = nums2[j];
            j++;k++;
        }
        
    }
};