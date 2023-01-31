// https://leetcode.com/problems/integer-to-roman/
#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void printVec(vector<int> &arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}

vector<int> convertToDigits(int num){
    stack<int> st;
        int place = 1;
        while(num>0){
            int rem = num%10;
            st.push(rem * place);
            num/=10;
            place*=10;
        }
        vector<int> nums;
        while(!st.empty()){
            nums.push_back(st.top());
            st.pop();
        }
        printVec(nums);
        return nums;
}

void printRoman(int &num){
    // hash map
    map<int,string> hm;
    map<int,string> hm1;
    hm[4] = "IV";
    hm[9] = "IX";
    hm[40] = "XL";
    hm[90] = "XC";
    hm[400] = "CD";
    hm[900] = "CM";
    
    hm1[1] = 'I';
    hm1[5] = 'V';
    hm1[10] = 'X';
    hm1[50] = 'L';
    hm1[100] = 'C';
    hm1[500] = 'D';
    hm1[1000] = 'M';
    //
    vector<int> nums = {1,5,10,50,100,500,1000};
    while(num>0){
        if(hm.find(num) == hm.end()){
            cout<<hm[num]<<" ";
            num-= num;
        }
        else{
            for(int i=6;i>=0;i--){
            if(num - nums[i] > 0) continue;
            else{
                cout<<"At index "<<i<<" "<<nums[i]<<endl;
                cout<<hm1[nums[i]]<<" ";
                num -= nums[i];
                break;
            }
        }
        }
    }
}

void convertToRoman(int num){
    //hashmap
    map<int,string> hm;
    map<int,string> hm1;
    hm[4] = "IV";
    hm[9] = "IX";
    hm[40] = "XL";
    hm[90] = "XC";
    hm[400] = "CD";
    hm[900] = "CM";
    
    hm1[1] = 'I';
    hm1[5] = 'V';
    hm1[10] = 'X';
    hm1[50] = 'L';
    hm1[100] = 'C';
    hm1[500] = 'D';
    hm1[1000] = 'M';
    //
    vector<int> sep = convertToDigits(num);
    
    
    for(int i=0;i<sep.size();i++){
        if(hm.find(sep[i]) == hm.end())
            cout<<hm[sep[i]]<<" ";
        else
            printRoman(sep[i]);
    }
    cout<<endl;
}

int main() {
        vector<int> nums {3,58,298,1994,1998};
        for(int i=0;i<nums.size();i++){
            convertToDigits(nums[i]);
        }
        convertToRoman(3);
        
    return 0;
}