#include <iostream>
using namespace std;

 bool checkValidString(string s) {
       int left=0,aux=0;
        for (int i=0;i<s.size();i++){
            if(s[i] == '('){
                left++;aux++;
            }
            else if(s[i] == ')'){
                left--;aux--;
            }
            else{
                left--;
                aux++;
            }
            if(aux<0) return false;
            if(left<0) left=0;
        }
        return left==0;
    }

int main(){

    string s = "(*))";
    cout<<checkValidString(s);
    return 0;
}