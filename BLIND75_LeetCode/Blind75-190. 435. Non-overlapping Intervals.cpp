https://leetcode.com/problems/non-overlapping-intervals/description/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int> &arr1, vector<int> &arr2){return arr1[0] <arr2[0];});

        int count = 0, prevEnd = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= prevEnd) prevEnd = intervals[i][1];
            else{
                count++;
                prevEnd = min(intervals[i][1] , prevEnd);
            }
        }
        return count;

    }
};