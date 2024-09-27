#include<iostream>
using namespace std;

int print(int n){
    if (n==1){
        return 1;
    }
    cout<<n<<" ";
    return print(n-1);
}

int main(){
    int n;
    cin>>n;
    int ans=print(n);
    cout<<ans;
    return 0;
}