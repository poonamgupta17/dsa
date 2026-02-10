//lc-160 intersection point of Y LL
#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//optimized approach: we will use 2 pointers and traverse both the lists, if any of the pointer reaches NULL then we will point it to the head of other list, if there is an intersection then both the pointers will meet at the intersection point, if there is no intersection then both the pointers will reach NULL at the end
//tc: O(n1+n2) sc: O(1)
 class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2)return t1;
            if(t1==NULL)t1=headB;
            if(t2==NULL)t2=headA;
        }
        return t1;
    }
};