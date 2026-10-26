class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int row = 0; row < matrix.size(); row++){
            if (binarySearch(0, matrix[row].size()-1, matrix[row], target) != -1)return true;
        }
        return false;
    }

    int binarySearch(int start, int end, vector<int>& arr, int target){
        if (start > end) return -1;
        int midpoint = start + (end-start)/2;
        if (arr[midpoint] == target) return midpoint;
        else if(arr[midpoint] < target) return binarySearch(midpoint+1, end, arr, target);
        else return binarySearch(start, midpoint-1, arr, target);
    }
};
