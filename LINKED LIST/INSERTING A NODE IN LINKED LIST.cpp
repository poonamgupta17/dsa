#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
Node* convertArr2LL(vector<int>& arr){
    if(arr.empty())return NULL;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return head;
}
Node* insertAtHead(Node* head, int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
    return head;
}
Node* insertAtTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}
Node* insertAtPositionK(Node* head,int k,int val){
    if(k==1){
        return insertAtHead(head,val);
    }
    Node* temp=head;
    int count=0;
    while(temp->next!=NULL){
        count++;
        if(count==k-1){
            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
    }
}
Node* insertBeforeValue(Node* head, int data,int val){
    if(head==NULL)return head;
    if(head->data==data){
        return insertAtHead(head,val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==data){
            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
    }
}
int main(){
    vector<int> arr={2,3,4,5};
    Node* head=convertArr2LL(arr);
    cout<<"Original Linked List: ";
    printLL(head);
    
    int val=1; // Value to be inserted at head
    head=insertAtHead(head, val);
    
    cout<<"Linked List after inserting "<<val<<" at head: ";
    printLL(head);

    val=6;   // Value to be inserted at tail
    head=insertAtTail(head, val);
    cout<<"Linked List after inserting "<<val<<" at tail: ";
    printLL(head);

    int k=4; // Position to insert the new value
    val=10;  // Value to be inserted at position k
    head=insertAtPositionK(head, k, val);
    cout<<"Linked List after inserting "<<val<<" at position "<<k<<": ";
    printLL(head);

    int data=4; // Value before which new value is to be inserted
    val=8;     // Value to be inserted before 'data'
    head=insertBeforeValue(head, data, val);
    cout<<"Linked List after inserting "<<val<<" before value "<<data<<": ";    
    printLL(head);

    return 0;
}   