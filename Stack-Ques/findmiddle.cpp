#include<iostream>
#include<stack>

using namespace std;

void findMiddle(stack<int>&s, int &totalSize){
    //base condition
    if (s.size()==totalSize/2+1){
        cout<<s.top();
    }

    int temp=s.top();
    s.pop();

    //RE
    findMiddle(s, totalSize);

    s.push(temp);
}

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    int totalSize=st.size();
    findMiddle(st, totalSize);
    return 0;
}