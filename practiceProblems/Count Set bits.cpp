#include<iostream>

using namespace std;

int countSetBits(int num){
    int count = 0;
    while(num){
        bool set = num%2;
        count +=set;
        num = num>>1;
    }
    return count;
}

int main(){
    int num = 4,num1 = 5, num2 = 7;
    cout<<countSetBits(num)<<endl;
    cout<<countSetBits(num2)<<endl;
    cout<<countSetBits(num1);
}