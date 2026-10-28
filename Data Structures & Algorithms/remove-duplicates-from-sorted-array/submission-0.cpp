class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> sorted(nums.begin(), nums.end());
        int i = 0;
        for (int num: sorted){
            nums[i] = num;
            i++;
        }

        return sorted.size();
    }
};