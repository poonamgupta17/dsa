#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
    public:
    Node(int data1, Node* prev1, Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
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
int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertArray2dll(arr);
    Node* temp = head;
    cout << "Doubly Linked List elements: ";
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}