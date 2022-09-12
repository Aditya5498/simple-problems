#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int getLargestKElement(vector<int> arr, int k){
    priority_queue<int> q;
    for(int i=0;i<arr.size();i++){
        q.push(arr[i]);
        if(q.size()>k) q.pop();
    }
    return q.top();
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    int k = 2;
    cout<<getLargestKElement(arr, k);
    return 0;
}