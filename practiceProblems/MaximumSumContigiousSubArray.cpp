#include <iostream>

using namespace std;

int main() {
    int maxSum = -2, currSum = -2;
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    
    for(int i=1;i<9;i++){
        if(currSum < 0) currSum = 0;
        if(currSum > maxSum) maxSum = currSum;
        currSum += arr[i];
    }
    cout<<maxSum<<endl;

    return 0;
}