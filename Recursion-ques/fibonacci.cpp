#include<iostream>
using namespace std;

int fibonacci(int n){
    //Base Condition
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }

    //Recursive Relation
    int ans=fibonacci(n-1)+fibonacci(n-2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=fibonacci(n);
    cout<<ans;
    return 0;
}