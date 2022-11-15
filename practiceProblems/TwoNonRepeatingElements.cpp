#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> find2NonRepeatingelements(vector<int> arr){
vector<int> arr1;

map<int,int> hm;

for(int i=0;i<arr.size();i++)
    hm[arr[i]]++;

for(auto it=hm.begin();it!=hm.end();it++)
    if(it->second !=2) arr1.push_back(it->first);

return arr1;

}

void nonRepeatingElements(vector<int> arr){
    vector<int> arr1 = find2NonRepeatingelements(arr);
    cout<<arr1[0]<<" "<<arr1[1];
}



int main(){

    vector<int> arr = {1,1,2,3,3,4,5,5};
    nonRepeatingElements(arr);

    return 0;
}