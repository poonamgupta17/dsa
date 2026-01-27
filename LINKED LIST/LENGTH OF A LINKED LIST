//to find length of linked list 

#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
  
    int getCount(Node* head) {
        // Code here
        int cnt=0;
        Node* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};
