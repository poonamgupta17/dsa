//to sort a linked list of 0's,1's and 2's
#include<bits/stdc++.h>
using namespace std;
//Node is defined as
class Node {
public:
int data;
Node* next;

Node(int x) {
    data = x;
    next = nullptr;
    }
};
//single pass solution
//tc: O(n) sc: O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head==NULL || head->next==NULL)return head;
        Node* zeroHead=new Node(-1);
        Node* oneHead=new Node(-1);
        Node* twoHead=new Node(-1);
        Node* zero=zeroHead;
        Node* one=oneHead;
        Node* two=twoHead;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=temp;
            }
            else if(temp->data==1){
                one->next=temp;
                one=temp; 
            }
            else{
                two->next=temp;
                two=temp;
            }
            temp=temp->next;
        }
        zero->next=(oneHead->next)?oneHead->next:twoHead->next;
        one->next=(twoHead->next);
        two->next=NULL;
        
        Node* newHead=zeroHead->next;
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return newHead;
    }
};