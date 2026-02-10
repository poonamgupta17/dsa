//LC-206. Reverse Linked List

#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//changing links
//TC: O(N)
//SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};
//reversing in terms of values
//TC: O(2N)
//SC: O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        stack<int>st;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};