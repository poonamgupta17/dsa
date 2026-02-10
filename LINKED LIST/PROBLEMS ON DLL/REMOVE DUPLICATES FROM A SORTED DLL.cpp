//to remove duplicates from a sorted doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
//tc=O(N) (as the outer loop visits the unique nodes and the inner loop visits the duplicate nodes, which together visit all the nodes in the linked list)
//sc=O(1)
class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head==NULL)return head;
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL ){
            Node* nextNode=temp->next;
            while(nextNode!=NULL && temp->data==nextNode->data ){
                Node* del=nextNode;
                nextNode=nextNode->next;
                delete(del);
            }
            temp->next=nextNode;
            if(nextNode)nextNode->prev=temp;
            temp=nextNode;
        }
        return head;
    }
};