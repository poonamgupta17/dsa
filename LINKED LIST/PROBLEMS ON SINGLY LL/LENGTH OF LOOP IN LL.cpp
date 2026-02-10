//Function to find the length of a loop in the linked list.
//tc=O(n)
//sc=O(1)

#include <bits/stdc++.h>
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
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int cnt=1;
                fast=fast->next;
                while(fast!=slow){
                    cnt++;
                    fast=fast->next;
                }
                return cnt;
            }
        }
        return 0;
    }
};