#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

void printArray(vector<pair<int,int>> arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i].first<<" "<<arr[i].second<<" "<<endl;
    cout<<endl;
}

void printArray(vector<int> arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}

bool check(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int main() {
    vector<int> arr1 {1,2,3,4};
    vector<int> arr2 {40,30,20,10};
    vector<pair<int,int>> arr3;
    
    for(int i=0;i<arr1.size();i++){
        pair<int,int> p(arr1[i],arr2[i]);
        arr3.push_back(p);
    }
    printArray(arr1);
    printArray(arr2);
    printArray(arr3);
    sort(arr3.begin(), arr3.end(), check);
    printArray(arr3);
    return 0;
}