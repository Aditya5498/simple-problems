#include<iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void calculate(int arr[], int size){
    for(int i=0;i<size;i++) arr[i] = arr[i] * 5;
    print(arr,size);
}


int main(){
    int arr[] = {1,2,3,4,5};
    calculate(arr,5);
    cout<<arr[0]<<endl;
    print(arr,5);
    return 0;
}