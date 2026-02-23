//to reverse a stack using recursion we will use two functions one is to reverse the stack and another is to insert the element at the bottom of the stack
//tc: O(n^2) due to two recursive calls one for reverse and another for insertAtBottom
//sc: O(n) due to recursion stack space used in reverse function
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
     void insertAtBottom(int x,stack<int> &s){
        if(s.size()==0){
            s.push(x);
        }
        else{
            int a=s.top();
            s.pop();
            insertAtBottom(x,s);
            s.push(a);
        }
     }
    void reverse(stack<int> &s){
        if(s.size()>0){
            int x=s.top();
            s.pop();
            reverse(s);
            insertAtBottom(x,s);
        }
    }
    void reverseStack(stack<int> &st) {
        // code here
        reverse(st);
    }
};