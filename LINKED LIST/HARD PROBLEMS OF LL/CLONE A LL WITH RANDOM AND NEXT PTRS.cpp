//lc-138 Copy List with Random Pointer

//time complexity: O(3n)
//space complexity: O(n) (for creating the new linked list)

#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertCopyInBw(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* cnode=new Node(temp->val);
            cnode->next=temp->next;
            temp->next=cnode;
            temp=temp->next->next;
        }
    }
    void connectRandomP(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* cnode=temp->next;
            if(temp->random){
                cnode->random=temp->random->next;
            }
            temp=temp->next->next;
        }
    }
    Node* getDeepCopyList(Node* head){
        Node* dnode=new Node(-1);
        Node* res=dnode;
        Node* temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;

        }
        return dnode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBw(head);
        connectRandomP(head);
        return getDeepCopyList(head);
    }
};