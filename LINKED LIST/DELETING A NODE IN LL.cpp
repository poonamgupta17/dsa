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
Node* deleteHead(Node* head){
    if(head==NULL)return NULL; // Empty list
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* deleteTail(Node* head){
    if(head==NULL)return NULL; // Empty list
    if(head->next==NULL){
        delete head;
        return NULL; // Single node list
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
// Function to delete the k-th node from the linked list
Node* deleteNode(Node* head, int k){
    if(head==NULL || k<=0)return head; // Invalid case
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    
    Node* temp=head;
    int count=1;
    Node* prev=NULL;
    while(temp!=NULL){
        if(count==k){
            prev->next=prev->next->next;
            delete temp;
            return head;
        }
        prev=temp;
        temp=temp->next;
        count++;
    }
    return head; // If k is greater than the length of the list, return the original head
}
Node* deleteEl(Node* head, int el){
    if(head==NULL)return head; // Invalid case
    if(head->data==el){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=prev->next->next;
            delete temp;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head; // If el is not found in the list, return the original head
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2LL(arr);
    cout<<"Original Linked List: ";
    printLL(head);
    
    // int k=3; // Position of the node to be deleted
    // head=deleteNode(head,k);
    
    // cout<<"Linked List after deleting "<<k<<"-th node: ";
    // printLL(head);
    
    int el=4; // Element to be deleted
    head=deleteEl(head,el);

    cout<<"Linked List after deleting element "<<el<<" : ";
    printLL(head);

    return 0;
}

