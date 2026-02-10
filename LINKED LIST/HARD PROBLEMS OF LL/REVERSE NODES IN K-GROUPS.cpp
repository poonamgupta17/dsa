//lc-25 to reverse the nodes of a linked list k at a time and return its modified list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is. You may not alter the values in the list's nodes, only nodes itself may be changed.
//TC: O(N)
//SC: O(1)

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL)return head;
    ListNode*newhead=reverseList(head->next);
    ListNode*front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
ListNode* findkthnode( ListNode* temp,int k){
    k=k-1;
    while(k>0&&temp!=NULL){
        k--;
        temp=temp->next;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL){
        ListNode* knode=findkthnode(temp,k);
             
        if(knode==NULL){
            if(prev){
                prev->next=temp;
            }
            break;
        }
        ListNode* nextnode=knode->next;
        knode->next=NULL;
        reverseList(temp);
        if(temp==head){
            head=knode;
        }
        else prev->next=knode;
        prev=temp;
        temp=nextnode;
    }
    return head;
}
};