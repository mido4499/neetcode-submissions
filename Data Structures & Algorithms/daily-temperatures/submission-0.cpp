class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> counts(n, 0);
        stack<int> theStack;

        for (int i = 0; i < n; i++){
            if (theStack.empty()){
                theStack.push(i);
                continue;
            }
            while (!theStack.empty() && temperatures[theStack.top()] < temperatures[i]){
                counts[theStack.top()] = i - theStack.top();
                theStack.pop();
            }
            theStack.push(i);
        }

        return counts;

    }
};
