#include<iostream>
using namespace std;

int findLongestCommonSubstring(string s1,string s2){
int arr[s1.size()+1][s2.size()+1],maxi=0;

//initialize all the values of matrix to 0
for(int i=0;i<s1.size()+1;i++){
    for(int j=0;j<s2.size()+1;j++){
       arr[i][j]=0;
    }   
}

//algorithm
for(int i=1;i<s1.size()+1;i++){
    for(int j=1;j<s2.size()+1;j++){
        if(s1[i-1]==s2[j-1]){
            arr[i][j]=arr[i-1][j-1]+1;
            maxi=max(arr[i][j],maxi);
        }
        else arr[i][j]=0;
    }
}

return maxi;
}

int main(){
    string X = "abcdxyz", y = "xyzabcd" ;
    cout<<findLongestCommonSubstring(X,y);
    return 0;
}