#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string str="prerna";
    stack<char>st;
    for (char i: str){
        st.push(i);
    }
    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}