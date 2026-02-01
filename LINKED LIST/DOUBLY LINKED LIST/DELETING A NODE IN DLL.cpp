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
Node* deleteHead(Node* head){
    if(head==nullptr || head->next==nullptr)return nullptr;
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr)return nullptr;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
//given k is in range 1 to length of dll
Node* deleteKthNode(Node* head,int k){
    if(head==nullptr || k<=0)return head;
    if(k==1){
        return deleteHead(head);
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k)break;
        temp=temp->next;
    }
    if(temp == nullptr) return head; // k out of range
     
    // deleting tail
    if(temp->next == nullptr) return deleteTail(head);

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
Node* deleteElement(Node* head,int ele){
    if(head==nullptr)return head;
    if(head->data==ele){
        return deleteHead(head);
    }
    Node* temp=head;
    while(temp!=NULL && temp->data!=ele){
        temp=temp->next;
    }
    if(temp == nullptr) return head; // element not found
     
    // deleting tail
    if(temp->next == nullptr) return deleteTail(head);
    
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    Node* head = convertArray2dll(arr);
    cout << "Original Doubly Linked List elements: ";
    printLL(head);
    
    head = deleteHead(head);
    cout << "Doubly Linked List after deleting head: ";
    printLL(head);

    head = deleteTail(head);
    cout << "Doubly Linked List after deleting tail: ";
    printLL(head);

    int k = 2; // Position of the node to be deleted
    head = deleteKthNode(head, k);
    cout << "Doubly Linked List after deleting " << k << "-th node: ";
    printLL(head);

    int ele = 40; // Element to be deleted
    head = deleteElement(head, ele);
    cout << "Doubly Linked List after deleting element " << ele << ": ";
    printLL(head);


    return 0;

}