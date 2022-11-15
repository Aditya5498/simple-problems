class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[] (vector<int>& a, vector<int>& b){ return a[0] < b[0]; });
      vector<vector<int>> out;
        out.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            int lastEnd = out[out.size() -1][1];

            if(intervals[i][0] <= lastEnd) 
            out[out.size() - 1][1] = max(lastEnd, intervals[i][1]);
            else out.push_back(intervals[i]);
         }
         return out;;
    }
};