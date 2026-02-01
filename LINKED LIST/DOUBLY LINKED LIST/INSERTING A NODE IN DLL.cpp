#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
    public:
    Node(int data1,Node* prev1,Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};
Node* convertArray2dll(vector<int>& arr) {
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],prev,nullptr);
        prev->next=temp;
        prev=temp;
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
Node* insertBeforeHead(Node* head,int val){
    Node* newNode=new Node(val,nullptr,head);
    head->prev=newNode; 
    head=newNode;
    return head;
}
Node* insertBeforeTail(Node* head,int val){
    if(head->next==nullptr){
        return insertBeforeHead(head,val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val,temp->prev,temp);
    temp->prev->next=newNode;
    temp->prev=newNode;
    return head;
}
Node* insertBeforeKthNode(Node* head,int k,int val){
    if(k==1){
        return insertBeforeHead(head,val);
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL ){
        count++;
        if(count==k)break;
        temp=temp->next;
    }
    if(temp==nullptr){
        return head; // k is greater than length of dll
    }
    Node* newNode=new Node(val,temp->prev,temp);
    temp->prev->next=newNode;
    temp->prev=newNode;
    return head;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertArray2dll(arr);
    cout << "Original Doubly Linked List elements: ";
    printLL(head);
    
    head = insertBeforeHead(head, 5);
    cout << "After inserting 5 before head: ";
    printLL(head);
    
    head = insertBeforeTail(head, 45);
    cout << "After inserting 45 before tail: ";
    printLL(head);

    head = insertBeforeKthNode(head, 4, 25);
    cout << "After inserting 25 before 4th node: "; 
    printLL(head);
    
    return 0;
}