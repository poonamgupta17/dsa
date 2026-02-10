//to add 1 to a number represented by linked list

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

//approach 1 - reverse the linked list and add 1 to the first node and then reverse it again
//tc: O(3n) 
//sc: O(1)
class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL)return head;
        Node* newHead=reverseList(head->next);
        Node* front=head->next;
        front->next=head;
        head->next=NULL;
        
        return newHead;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head=reverseList(head);
        Node* temp=head;
        int carry=1;
        while(temp!=NULL){
            temp->data=temp->data+carry;
            if(temp->data<10){
                carry=0;
            }
            else{
                temp->data=0;
                carry=1;
            }
            temp=temp->next;
        }
        head=reverseList(head);
        if(carry==1){
            Node* newHead=new Node(1);
            newHead->next=head;
            return newHead;
        }
        // return head of list after adding one
        return head;
    }
};

//approach 2- recursive approach(backtracking) 
//tc: O(n) 
//sc: O(n)
class Solution {
  public:
    int helper(Node* temp){
        if(temp==NULL)return 1;
        int carry=helper(temp->next);
        temp->data=temp->data+carry;
        if(temp->data<10){
            return 0;
        }
        temp->data=0;
        return 1;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry=helper(head);
        if(carry==1){
            Node* newHead=new Node(1);
            newHead->next=head;
            return newHead;
        }
        // return head of list after adding one
        return head;
    }
};