
#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class FreqStack {
public:
    map<int,int> hm;
    map<int, stack<int>> st_mp;
    int maxi;
    
    FreqStack() {
    maxi=0;    
    }
    
    void push(int val) {
        // incrementing the count
        hm[val]++;
        //keeping track of the maximum frequency
        maxi=max(maxi,hm[val]);
        // storing the variable in the stack with it's corresponding value of count
        st_mp[hm[val]].push(val);
    }
    
    int pop() {
        //getting the last element from the stack
        int value = st_mp[maxi].top();
        // decrementing the frequency of the variable
        hm[value]--;
        // removing the variable from the stack
        st_mp[maxi].pop();
        
        // checking if stack is empty and decrementing the maximum count
        if(st_mp[maxi].empty()){
            st_mp.erase(maxi);
            maxi--;
        }
        return value;
    }
};

int main() {
    // Write C++ code here
FreqStack *freqStack = new FreqStack();
freqStack->push(5); // The stack is [5]
freqStack->push(7); // The stack is [5,7]
freqStack->push(5); // The stack is [5,7,5]
freqStack->push(7); // The stack is [5,7,5,7]
freqStack->push(4); // The stack is [5,7,5,7,4]
freqStack->push(5); // The stack is [5,7,5,7,4,5]
cout<<freqStack->pop()<<endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
cout<<freqStack->pop()<<endl;   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
cout<<freqStack->pop()<<endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
cout<<freqStack->pop()<<endl;   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].

    return 0;
}