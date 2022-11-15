#include<iostream>
#include<vector>
using namespace std;

struct sparseNode{
    int row;
    int col;
    int value;
};

void display(vector<sparseNode> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i].row<<" "<<arr[i].col<<" "<<arr[i].value<<endl;
    cout<<endl;
}

int main(){
    int arr[4][4] = {
        {0,1,2,0},
        {1,0,0,5},
        {6,0,0,0},
        {-1,0,0,0}
    };

    vector<sparseNode> arr1;
    int count=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) {
            if(arr[i][j]!=0) count++;
        }
    }

    struct sparseNode a;
    a.row = 4;
    a.col = 4;
    a.value = count;
    arr1.push_back(a);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j] != 0){
                struct sparseNode n;
                n.row = i;
                n.col = j;
                n.value = arr[i][j];
                arr1.push_back(n);
            }
        }
    }

    display(arr1);
    return 0;
}