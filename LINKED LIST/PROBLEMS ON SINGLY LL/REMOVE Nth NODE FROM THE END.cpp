//lc-19 remove nth node from the end of a linked list
#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//optimal approach- two pointer approach
//tc=O(n)
//sc=O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=0;i<n;i++)fast=fast->next;
        if(fast==NULL){
            ListNode* newHead=head->next;
            delete(head);
            return newHead;
        }
        ListNode* slow=head;
        while(fast->next!=NULL){ //at tail
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* del=slow->next;
        slow->next=slow->next->next;
        delete(del);
        return head;
    }
};