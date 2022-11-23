#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* reverseList(ListNode* head) {
        if(! head->next || !head) return head;
        ListNode *prev = nullptr, *next = head -> next, *curr = head;

        while(curr){
            next = curr -> next;
            curr ->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }

void printList(ListNode *head){
    ListNode *curr = head;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }

}

int main(){

    ListNode *node = new ListNode(1);
    node -> next = new ListNode(2);
    node -> next -> next = new ListNode(3);
    node -> next -> next -> next = new ListNode(4);

    printList(node);

    cout<<endl;

    printList(reverseList(node));
    return 0;
}