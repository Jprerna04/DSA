#include<iostream>
using namespace std;

int factorial(int n){
    if (n==1){
        return 1;
    }
    int ans=n*factorial(n-1);
    return ans;
}

int main(){
    int n;
    cout<<"Enter number to be used: "<<endl;
    cin>>n;
    int ans=factorial(n);
    cout<<ans;
    return 0;
}


