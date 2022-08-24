// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
void printL(T &arr){
    int Erow=arr.size(),Scol=arr[0].size();
while(Erow>0 && Scol>0){
    for(int i=0;i<Erow;i++){
        cout<<arr[i][Scol-1]<<" ";
    }
    Scol--;
    for(int i=Scol-1;i>=0;i--){
        cout<<arr[Erow-1][i]<<" ";
    }
    cout<<endl;
    Erow--;
}
}

template <typename T>
void print(T &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DPapproach(vector<vector<char>> &arr,vector<vector<int>> &dp){
       int Erow=arr.size(),Scol=arr[0].size();
while(Erow>0 && Scol>0){
    for(int i=0;i<Erow;i++){
      //  cout<<arr[i][Scol-1]<<" ";
        if(arr[i][Scol-1]=='1'){
            dp[i][Scol-1] = min(dp[i][Scol], min(dp[i+1][Scol-1],dp[i+1][Scol])) +1;
        }
        else{
            dp[i][Scol-1]=0;
        }
    }
    Scol--;
    for(int i=Scol-1;i>=0;i--){
      //  cout<<arr[Erow-1][i]<<" ";
        if(arr[Erow-1][i]=='1'){
            dp[Erow-1][i] = min(dp[Erow-1][i+1], min(dp[Erow][i],dp[Erow][i+1])) +1;
        }
        else{
        dp[Erow-1][i]=0;
        }
    }
    cout<<endl;
    Erow--;
}
}

//Find max in a 2d array
int findMax(vector<vector<int>> &arr){
    int max=INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            max=arr[i][j]>max?arr[i][j]:max;
        }
    }
    return max;
}

int main() {
    // Write C++ code here
   vector<vector<char>> arr={
     {'1','0','1','0','0'},
     {'1','0','1','1','1'},
     {'1','1','1','1','1'},
     {'1','0','0','1','0'}
   };
printL(arr);
print(arr);
vector<vector<int>> maximalSquare(arr.size()+1, vector<int> (arr[0].size()+1));

// add 0 in all cells of last row and column
for(int i=0;i<arr.size();i++) maximalSquare[i][arr[0].size()]=0;
for (int i=0;i<arr[0].size();i++) maximalSquare[arr.size()][i]=0;
maximalSquare[arr.size()][arr[0].size()]=0;

// compare with each cell in array and with right cell, 
//bottom cell and diagonal cell. 
//Add 1 if the present cell in array has '1' else keep it '0'
DPapproach(arr,maximalSquare);

// find maximum int in maximalSquare 2d matrix which is the side of the square
int max=findMax(maximalSquare);
cout<<"Maximimum side of the square = "<<max<<" \n=> Area of the square = "<<max*max<<endl;

// printL(maximalSquare);
// print(maximalSquare);

    return 0;
}