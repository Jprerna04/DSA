#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int>&s, int &target){
    //base condition
    if (s.empty()){
        s.push(target);
        return;
    }

    int temp=s.top();
    s.pop();

    //recursive call
    solve(s,target);

    //BT
    s.push(temp);
}

void findTarget(stack<int>&s){
    if (s.top()==-1){
        cout<<"UNDERFLOW IN STACK";
    }
    else{
        int target=s.top();
        s.pop();
        solve(s,target);
    }
    return;
}

void print(stack<int>&st){
    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    findTarget(st);

    print(st);
}