#include<iostream>
using namespace std;

int count=0;

void swap(char *x,char *y)
{
    char temp=*x;
    *x=*y;
    *y=temp;
}

void permute(char *a,int l,int r){
    if(l==r) cout<<a<<endl;
    else{
        for(int i=l;i<=r;i++){
            swap(a+l,a+i);
            permute(a,l+1,r);
            swap(a+l,a+i);
        }
    }
    count++;
}

int main(){
    char str[]="ABC";
    permute(str,0,2);
    cout<<"Count :- O(n) = "<<count<<endl;
    return 0;
}