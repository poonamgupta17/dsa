//a flattening a linked list is to convert a linked list of linked lists into a single sorted linked list.
//tc: O(2*N*M) where N is the number of linked lists and M is the average number of nodes(child nodes) in each linked list
//sc: O(1) for merging 2 linked lists and O(N) for recursive stack space where N is the number of linked lists
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
class Solution {
  public:
    Node* merge2ll(Node* head1,Node* head2){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        while(head1!=NULL && head2!=NULL){
            if(head1->data<=head2->data){
                res->bottom=head1;
                res=head1;
                head1=head1->bottom;
            }
            else{
                res->bottom=head2;
                res=head2;
                head2=head2->bottom;
            }
            res->next=NULL;
        }
        if(head1)res->bottom=head1;
        else res->bottom=head2;
        
        if(dummyNode->bottom)dummyNode->next=NULL;
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==NULL || root->next==NULL)return root;
        Node* mergeHead=flatten(root->next);
        return merge2ll(root,mergeHead);
    }
};