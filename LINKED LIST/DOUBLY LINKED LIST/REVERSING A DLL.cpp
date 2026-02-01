//tc=o(n)
//sc=o(1)
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
Node* reverseDll(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* current=head;
    Node* last=nullptr;
    while(current!=NULL){
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
    return last->prev;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    Node* head = convertArray2dll(arr);
    cout << "Original Doubly Linked List elements: ";
    printLL(head);
    
    head = reverseDll(head);
    cout << "Reversed Doubly Linked List elements: ";
    printLL(head);

    return 0;
}