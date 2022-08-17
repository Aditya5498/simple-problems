#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

//structure of a node
struct Node{
    int data;
    Node *next;
    Node(int data){
        data=data;
        next=NULL;
    }
    Node(int data,Node *next){
        data=data;
        next=next;
    }
};

// Finding the triple :-
// This method uses sorting to increase the efficiency of the code. 

// Approach: By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find if there is a pair whose sum is equal to x – array[i]. Two pointers algorithm take linear time so it is better than a nested loop.
// Algorithm : 
// 1)Sort the given array.
// 2)Loop over the array and fix the first element of the possible triplet, arr[i].
// 3)Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
//      -If the sum is smaller than the required sum, increment the first pointer.
//      -Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
//      -Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.

bool find3Numbers(vector<int> array, int sum)
{
    int l, r;
    
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < array.size()-2; i++) {
  
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements
        r = array.size(); // index of the last element
        while (l < r) {
            if (array[i] + array[l] + array[r] == sum) {
                printf("Triplet is %d, %d, %d", array[i], array[l],array[r]);
                return true;
            }
            else if (array[i] + array[l] + array[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}
  


//Driver program
int main(){
    Node *ll1=new Node(12);
    ll1->next=new Node(6);
    ll1->next->next=new Node(29);

    Node *ll2=new Node(23);
    ll2->next=new Node(5);
    ll2->next->next=new Node(8);

    Node *ll3=new Node(90);
    ll3->next=new Node(20);
    ll3->next->next=new Node(59);

    // Now Create an array to store all the elements of the 3 linked lists 👍🤟👊
    vector<int> array;
    Node *temp=ll1;
    while(temp){
        array.push_back(temp->data);
        temp=temp->next;
    }
    temp=ll2;
    while(temp){
        array.push_back(temp->data);
        temp=temp->next;
    }
    temp=ll3;
    while(temp){
        array.push_back(temp->data);
        temp=temp->next;
    }

    // Now sort the array in ascending/ descending order which ever you prefer😉🙂↓. 
    // I'll be going ahead and sorting the array in ascending order
    sort(array.begin(),array.end());

    cout<<find3Numbers(array,101);
    return 0;
}