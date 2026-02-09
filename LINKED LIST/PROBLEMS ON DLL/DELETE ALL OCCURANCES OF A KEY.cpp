//function to delete all occurrences of a key in a doubly linked list
//tc:O(N)
//sc:O(1)

#include <bits/stdc++.h>
using namespace std;
// a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here

        Node* temp=*head_ref;
        //head_ref → (stores address of head)
        //*head_ref → actual head node
        while(temp!=NULL){
            if(temp->data==x){
                
                if(temp==*head_ref){
                    *head_ref=temp->next;
                    (*head_ref)->prev=NULL;
                }
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                if(nextNode!=NULL)nextNode->prev=prevNode;
                if(prevNode!=NULL)prevNode->next=nextNode;
                
                delete(temp);
                temp=nextNode;
            }
            else temp=temp->next;
        }
    }
};