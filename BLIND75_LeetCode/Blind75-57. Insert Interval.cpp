https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        
        int newIdx=0, iIdx = 0;

        for(int i=0;i<intervals.size();i++){

            if(newInterval[1] < intervals[i][0]) {
                output.push_back(newInterval);
                for(int j=i;j<intervals.size();j++) output.push_back(intervals[j]);
                return output;
            }

            else if(newInterval[0] > intervals[i][1]) output.push_back(intervals[i]);

            else{
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        output.push_back(newInterval);
        return output;
    }
};

