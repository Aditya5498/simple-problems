#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;

//Solution using backtracking - consider the element and next time don't consider the element
void dfs(vector<int>& candidates, vector<int>& curr,int idx, int target){
    if(target==0){
        ans.push_back(curr);
        return;
    }

    if(target<0 || idx>candidates.size()) return;

    curr.push_back(candidates[idx]);
    dfs(candidates, curr, idx, target-candidates[idx]);

    curr.pop_back();
    dfs(candidates, curr, idx+1, target);
}

//calling function for dfs
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        
        dfs(candidates,curr,0,target);
        
        return ans;
    }

// printing the output
void print(vector<vector<int>> ans){
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1) cout<<", ";
        }
        cout<<" ]";
        if(i<ans.size()-1) cout<<", ";
    }
    cout<<endl;
}

//main driver
int main(){
    vector<int> candidates={2,3,6,7};
vector<vector<int>> outs=combinationSum(candidates,7);
print(outs);
    return 0;
}