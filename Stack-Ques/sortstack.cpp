#include<iostream>
#include<stack>

using namespace std;

void insertsorted(stack<int>&s, int& target){
    if (s.empty() || s.top() <= target) { 
        s.push(target);
        return;
    }

    int top=s.top();
    s.pop();

    insertsorted(s, target);

    s.push(top);
}

void sort(stack<int>&s){
    if (s.empty()){
        return;
    }

    int topElement=s.top();
    s.pop();
    sort(s);

    insertsorted(s, topElement);
}

int main(){
    stack<int>s;
    s.push(3);
    s.push(7);
    s.push(9);
    s.push(5);
    s.push(11);

    sort(s);

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}