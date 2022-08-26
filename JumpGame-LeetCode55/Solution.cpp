#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
        int goal=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i + nums[i]>=goal) goal=i;
        }
        if(goal==0) return true;
        return false;
    }

int main(){
vector<int> arr1 ={2,3,0,1,4};
cout<<canJump(arr1)<<endl;
vector<int> arr2 = {3,2,1,0,4};
cout<<canJump(arr2);
}