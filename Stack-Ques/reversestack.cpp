#include<iostream>
#include<stack>

using namespace std;

void insertAtBotton(stack<int>&s, int &target){
    //base condition
    if (s.empty()){
        s.push(target);
        return;
    }

    int temp=s.top();
    s.pop();

    //recursive call
    insertAtBotton(s,target);

    //BT
    s.push(temp);
}


void reverse(stack<int>&s){
    //base
    if (s.empty()){
        return;
    }

    int top=s.top();
    s.pop();

    reverse(s);

    insertAtBotton(s,top);
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    reverse(s);

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}