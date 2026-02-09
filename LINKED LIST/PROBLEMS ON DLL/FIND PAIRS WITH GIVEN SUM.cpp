//function to find pairs with given sum in a sorted doubly linked list

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
//brute force approach- using two nested loops to find pairs with given sum
//tc:O(N^2) where N is the number of nodes in the linked list
//sc:O(1)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>>v;
        Node* temp1=head;
        while(temp1!=NULL){
            Node* temp2=temp1->next;
            while(temp2!=NULL && (temp1->data+temp2->data)<=target){
                if((temp1->data+temp2->data)==target)v.push_back({temp1->data,temp2->data});
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return v;
    }
};

//optimal approach- using two pointers to find pairs with given sum
//tc:O(N) where N is the number of nodes in the linked list
//sc:O(1)
class Solution {
  public:
    Node* findTail(Node* head){
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>>v;
        Node* left=head;
        Node* right=findTail(head);
        while(left!=right && right->next!=left){
            if((left->data+right->data)==target){
                v.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if((left->data+right->data)<target) left=left->next;
            else right=right->prev;
        }
        return v;
    }
};