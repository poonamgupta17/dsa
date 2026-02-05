//lc-2095 delete the middle node of a linked list
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
//brute force approach-double pass
//tc=O(2n)
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)return NULL;
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int res=cnt/2;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0){
                ListNode* mid=temp->next;
                temp->next=temp->next->next;
                delete(mid);
            }
            temp=temp->next;
        }
        return head;
    }
};
//optimal approach- single pass using two pointers
//tc=O(n)
//sc=O(1)
