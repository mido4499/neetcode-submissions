class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        priority_queue<int> maxheap; // Keeps track of the tasks that are ready
        queue<pair<int, int>> q; // Keeps track of the tasks that need cooldown

        int time = 0;

        for (char task: tasks){
            counts[task-'A']++;
        }
        for (int count: counts){
            if (count > 0) maxheap.push(count);
        }

        while (!maxheap.empty() || !q.empty()){
            time++;

            if (maxheap.empty()){ // All tasks need cooldown
                time = q.front().second;
            }else{
                int thisTask = maxheap.top();
                maxheap.pop();
                thisTask--;
                if (thisTask > 0) q.push({thisTask, time+n}); // A task is in need of cooldown, move to queue
            }

            if (!q.empty() && q.front().second == time){ // A task is ready now, move to maxheap
                maxheap.push(q.front().first);
                q.pop();
            }
        }

        return time;


    }
};
