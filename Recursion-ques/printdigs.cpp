#include<iostream>
using namespace std;

void printdig(int n){
    if (n==0){
        return;
    }
    
    int newval=n/10;
    printdig(newval);

    int k=n%10;
    cout<<k<<" ";
}

int main(){
    int n;
    cin>>n;
    printdig(n);
    return 0;
}