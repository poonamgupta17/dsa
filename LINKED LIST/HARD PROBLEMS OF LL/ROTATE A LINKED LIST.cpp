//lc-61 to rotate a linked list to the right by k places, where k is non-negative number.

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//TC: O(2N) where N is the number of nodes in the linked list. We traverse the linked list twice, once to find its length and once to perform the rotation.
//SC: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        k=k%len;
        if(k==0)return head;
        tail->next=head;

        int steps=len-k;
        ListNode* newTail=head;

        for(int i=1;i<steps;i++){
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        newTail->next=NULL;
                
        return newHead;
    }
};

//more optimized code

//tc: O(2N)
//sc: O(1)
class Solution {
public:
    ListNode* findKthNode(ListNode* temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k)return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        k=k%len;
        if(k==0)return head;
        tail->next=head;

        ListNode* newTail=findKthNode(head,len-k);
        head=newTail->next;
        newTail->next=NULL;
                
        return head;
    }
};