//lc-142. Linked List Cycle II

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

//brute force approach (hashing)
//tc=O(n*2*logn)
//sc=O(n)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int>mpp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end())return temp;
            else mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
    }
};

//optimal approach (Floyd's Cycle Detection Algorithm / Tortoise and Hare Algorithm)
//tc=O(n)
//sc=O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};