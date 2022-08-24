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
for(int i=0;i<arr.size();i++) maximalSquare[i][arr[0].size()-1]=0;

printL(maximalSquare);
print(maximalSquare);

    return 0;
}