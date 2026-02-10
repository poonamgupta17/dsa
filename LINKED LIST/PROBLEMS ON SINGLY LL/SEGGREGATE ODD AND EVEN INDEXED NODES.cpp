//lc-328 Segregate Odd and Even indexed nodes in a singly linked list
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
//brute force using array(replacing values)
//tc=O(2n)   
//sc=O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;

        vector<int> array;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            array.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)array.push_back(temp->val);

        temp=head->next;
        while(temp!=NULL && temp->next!=NULL){
            array.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)array.push_back(temp->val);

        int i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=array[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};
//optimal approach- rearranging links
//tc=O(n)
//sc=O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};