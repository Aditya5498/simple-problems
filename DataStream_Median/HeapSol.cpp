#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
    // Max heap tracks the elements on left of median
    // Max heap can have at most 1 extra element than the min heap when 
    // total no. of terms is odd
    priority_queue<int, vector<int>,less<>> max_heap;
    // Min heap tracks the elements on right of median 
    priority_queue<int, vector<int>, greater<>> min_heap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_heap.empty() || num <= max_heap.top())
            max_heap.emplace(num);
        else 
            min_heap.emplace(num);

        // check if rebalancing is needed or not
        if(max_heap.size() > min_heap.size() + 1) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size() < min_heap.size()) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        // If both sides have the same size, means there are even no. of elements
        if(max_heap.size() == min_heap.size())
            return (double)(max_heap.top() + min_heap.top()) / 2;
        // Odd number of elements present
        return max_heap.top();
    }
};

int main(){
    cout<<"Main\n";
    MedianFinder sol;
    sol.addNum(1);
    sol.addNum(2);
    cout<<sol.findMedian();
    //sol.print();
    return 0;
}