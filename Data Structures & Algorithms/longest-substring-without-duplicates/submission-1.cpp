class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_set<char> unique;
        for (int r = 0; r < s.length(); r++){
            while(unique.find(s[r]) != unique.end()){
                unique.erase(s[l]);
                l++;
            }
            unique.insert(s[r]);
            res = max(res, r-l+1);

        }

        return res;
    }
};
