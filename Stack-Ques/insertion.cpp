#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // st.pop();

    // cout<<"Element at top is: "<<st.top()<<endl;

    // if (st.empty()){
    //     cout<<"Stack is empty";
    // }
    // else{
    //     cout<<"Stack is not empty";
    // }

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}