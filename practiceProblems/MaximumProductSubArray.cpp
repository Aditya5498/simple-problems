#include <iostream>

using namespace std;

int main() {
    int arr[] = {-1,2,3};
    int currMax = 1, currMin = 1, maxProd = 0;
    for(int i=0;i<3;i++){
        int n = arr[i];
        if(n == 0) {
            currMax = 1;
            currMin = 1;
            continue;
        }
        int temp = currMax;
        currMax = max(arr[i],max(currMax*n, currMin*n));
        currMin = min(arr[i],min(temp*n, currMin*n));
        maxProd = max(currMax, maxProd);
    }
    cout<<maxProd<<endl;
    return 0;
}