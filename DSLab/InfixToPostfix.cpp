#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int getPrecedence(char chr){
    if(chr == '/' || chr == '*') return 2;
    return 1;
}

void popAll(stack<char> &st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void convertInfixToPostfix(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z') cout<<str[i]<<" ";
        else if(st.empty()) st.push(str[i]);
        else if(getPrecedence(st.top()) >= getPrecedence(str[i])){
            popAll(st);
            st.push(str[i]);
        }        
        else st.push(str[i]);
    }
    popAll(st);
    cout<<endl;
}

int main(){
    string str = "a+b*c";
    cout<<"Conversion of "<<str<<" to postfix expression is\n";
    convertInfixToPostfix(str);
    str = "a*b+c";
    cout<<"Conversion of "<<str<<" to postfix expression is\n";
    convertInfixToPostfix(str);
       str = "a+b*c+d*e";
    cout<<"Conversion of "<<str<<" to postfix expression is\n";
    convertInfixToPostfix(str);
    return 0;
}