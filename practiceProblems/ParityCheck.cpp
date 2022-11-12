//Parity of a number refers to whether 
//it contains an odd or even number of 1-bits. 
//The number has “odd parity” if it contains an odd number of 1-bits 
//and is “even parity” if it contains an even number of 1-bits. 

#include <iostream>
using namespace std;

int main() {
   int a = 7, count=0;
   while(a){
       if(a%2) count++;
       a = a>>1;
   }
    if(count%2) cout<<"Odd parity";
    else cout<<"Even parity";
    return 0;
}