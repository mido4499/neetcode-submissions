class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> retSet;

        for (int i = 0; i < nums.size(); i++){
            int j = 0, k = nums.size()-1, target = -1*nums[i];

            while (j < k){
                vector<int> thisSum;
                if (j == i) j++;
                if (k == i) k--;
                if (j >= k) break;

                int sum = nums[j] + nums[k];
                if (sum == target){
                    thisSum.push_back(nums[i]);
                    thisSum.push_back(nums[j]);
                    thisSum.push_back(nums[k]);
                    sort(thisSum.begin(), thisSum.end());
                    retSet.insert(thisSum);
                    j++;k--;
                }
                else if (sum < target) j++;
                else k--;
            }
        }


        vector<vector<int>> ret(retSet.begin(), retSet.end());
        return ret;
    }
};
