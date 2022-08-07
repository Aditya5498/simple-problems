#include<iostream>
#include<deque>
using namespace std;

//This solution is based on brute force way. Time :- O(N), Space O(N)
// // Method:-
// Use a queue, for each and every get, update the element accessed and put it to the end -> O(N)
// For every put call, update the queue with the latest element


//                                   Design 
// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// using dequeue as to store elements
deque<int> queue;

int capacity=3;

deque<int>::iterator find(int num){
    auto itr=queue.begin();
    while(itr!=queue.end()){
        if(*itr==num){
            return itr;
        }
        itr++;
    }
    return queue.end();
}

int get(int key){
auto idx=find(key);
if(idx==queue.end()) return -1;
 queue.erase(idx);
queue.push_back(key);
return *idx;
}

void put(int key){
    auto idx=find(key);

    if(idx==queue.end()){
        if(queue.size()<capacity){
            queue.push_back(key);
        }
        else{
            queue.pop_front();
            queue.push_back(key);
        }
    }

    else{
         queue.erase(idx);
         queue.push_back(key);
    }

}


void print(){
    auto itr=queue.begin();
    while(itr!=queue.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl;
}

int main(){
capacity=2;
put(1);
put(2);
cout<<get(1)<<endl;
put(3);
print();
get(2);
put(4);
print();
cout<<get(1)<<endl;
get(3);
print();
get(4);
    return 0;
}