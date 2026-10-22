class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNums(nums.begin(), nums.end());
        int curr = 1, maxLength = 0;
        for (int num: setNums){
            curr = 1;
            if (setNums.find(num-1) == setNums.end()){
                while (setNums.find(num+curr) != setNums.end()){
                    curr++;
                }
                maxLength = max(curr, maxLength); 
            }
        }

        return maxLength;

    }
};
