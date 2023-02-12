// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;


int counts(vector<int> arr,int idx,int sum){
    if(sum < 0 && idx > 4 ) return 0;
    
    if(sum == 0) return 1;
        
    return counts(arr, idx, sum-arr[idx]) + 
    counts(arr, idx+1, sum-arr[idx]);
    
}

int main() {
    vector<int> arr = {1,2,3};
    
    cout<<counts(arr, 0,4);
    return 0;
}