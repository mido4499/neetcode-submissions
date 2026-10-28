class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res;

        for (int num: nums){
            count[num]++;
        }

        while (k > 0){
            int mostFrequent = 0;
            int maxFrequency = 0;
            for (auto c: count){
                if (c.second > maxFrequency){
                    maxFrequency = c.second;
                    mostFrequent = c.first;
                }
            }
            count[mostFrequent] = 0;
            res.push_back(mostFrequent);
            k--;
        }

        return res;
    }
};
