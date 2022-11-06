#include<iostream>
#include<stack>

using namespace std;

int getPrecedence(char a)
{
    if(a=='*' || a=='/') return 2;
    return 1;
}

void push(stack<char> &output,stack<char> &prefix){
    while(!prefix.empty()){
        output.push(prefix.top());
        prefix.pop();
    }
}

void printAll(stack<char> output){
    while(!output.empty()){
        cout<<output.top()<<" ";
        output.pop();
    }
    cout<<endl;
}

void InfixToPrefix(string str){
stack<char> prefix;
stack<char> output;
for(int i=str.size()-1;i>=0;i--){
    if(str[i] >='a' && str[i] <= 'z') output.push(str[i]);
    else if(prefix.empty()) prefix.push(str[i]);
    else if(getPrecedence(str[i])<=getPrecedence(prefix.top())) {
        push(output,prefix);
        output.push(str[i]);
    }
    else prefix.push(str[i]);
}
push(output,prefix);
printAll(output);
}

int main(){
    string s="a*b+c";
    InfixToPrefix(s);
    
    return 0;
}