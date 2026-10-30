class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compareDistance> heap;
        int distance;

        for (int i = 0; i < points.size(); i++){
            pair<int, int> thisPoint;
            thisPoint.first = points[i][0];
            thisPoint.second = points[i][1];

            heap.push(thisPoint);
            if (heap.size() > k) heap.pop();
        }

        while (!heap.empty()){
            pair<int, int> point = heap.top();
            heap.pop();
            vector<int> newPoint;
            newPoint.push_back(point.first);
            newPoint.push_back(point.second);
            res.push_back(newPoint);
        }

        return res;
    }

    struct compareDistance{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            double distA = sqrt((a.first*a.first) + (a.second*a.second));
            double distB = sqrt((b.first*b.first) + (b.second*b.second));

            if (distA > distB) return false;
            return true;
        }
    };
};
