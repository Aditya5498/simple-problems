// Converting negative number to absolute value.
// internally, c++ stores the negative number as 2's compliment
// to convert it into positive integer, use 1's compliment and add 1 to it.


#include <iostream>
using namespace std;

void printBits( int b){
    while(b){
    bool flag = b%2;
    b = b>>1;
    cout<<flag;
}
cout<<endl;
}

void printNegatedNumber(int b){
    cout<<"1's compliment of "<<b<<" is ->";
    b = ~b;
    printBits(b);
    cout<<"Adding 1 to 1's complment will give "<<b+1<<endl;
}

int main() {

int a =-3, b =1;
cout<<a<<" "<<b<<endl;
printNegatedNumber(-2);
printNegatedNumber(a);
printNegatedNumber(-4);
printNegatedNumber(-5);
    return 0;
}