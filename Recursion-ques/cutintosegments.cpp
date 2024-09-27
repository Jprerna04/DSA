#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(int l, int x, int y, int z){
    if (l==0){
        return 0;
    }
    if (l<0){
        return INT_MIN;
    }

    int ans1=solve(l-x,x,y,z)+1;
    int ans2=solve(l-y,x,y,z)+1;
    int ans3=solve(l-z,x,y,z)+1;
    int ans=max(ans1,max(ans2,ans3));
    return ans;
}

int main(){
    int l=7;
    int x=5;
    int y=2;
    int z=2;
    int ans=solve(l,x,y,z);
    if (ans<0){
        return 0;
    }
    cout<<ans;
}