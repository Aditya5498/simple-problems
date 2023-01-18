#include<iostream>
#include<stack>

using namespace std;

void printToBinary(int num){
    stack<int> bits;
    while(num>0){
        bits.push(num%2);
        num = num >>1;
    }

    while(!bits.empty()){
        cout<<bits.top();
        bits.pop();
    }
}

void removeFirstBit(int num){
    stack<int> bits;
    bool flag = false;
    while(num>0){
        if(num%2 == 1 && !flag){
            bits.push(0);
            flag = true;
        }
        else
            bits.push(num%2);
        num = num >>1;
    }

    while(!bits.empty()){
        cout<<bits.top();
        bits.pop();
    }
}




int main(){
    int num1 = 4, num2 = 6;
    printToBinary(num1);cout<<endl;
    removeFirstBit(num1);cout<<endl;
    printToBinary(num2);cout<<endl;
    removeFirstBit(num2);
    return 0;
}