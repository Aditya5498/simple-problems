#include <iostream>
#include <vector>
using namespace std;


   int LongestIncreasingSub(vector<int> arr){
       vector<int> LIS(arr.size(),1);
       int largest = 0;
       
       for(int i=arr.size()-1;i>=0;i--){
          
           for(int j=i+1;j<arr.size();j++)
           {
               if(arr[i] < arr[j])
               LIS[i] = max(LIS[i], 1 + LIS[j]);
           }
           largest = max(largest, LIS[i]);
           
       }
       cout<<endl;
       return largest;
   }


int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};   
    cout<<LongestIncreasingSub(arr);
    
    return 0;
}