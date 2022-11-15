#include<iostream>

using namespace std;

int countSetBits(int num){
    int count = 0;
    while(num){
     bool set = num & 1;
     count +=set;
     num = num>>1;   
    }
    return count;
}

int countBitsToBeFlipped(int num1, int num2){
    return countSetBits(num1 ^ num2);
}


int main(){
    int a = 3, b=2, c=a^b;
    cout<<c<<endl;
    cout<<countBitsToBeFlipped(a,b);
    return 0;
}