#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node * convertArr2ll(vector<int> &arr){
    if(arr.empty()) return NULL;
    Node * head = new Node(arr[0]);
    Node * mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int checkElementInLL(Node * head, int key){
    Node * temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return 1; // Element found
        }
        temp = temp->next;
    }
    return 0; // Element not found
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node * head = convertArr2ll(arr);
    int key = 8;
    if(checkElementInLL(head, key)){
        cout << "Element " << key << " found in the linked list." << endl;
    } else {
        cout << "Element " << key << " not found in the linked list." << endl;
    }
    return 0;
}