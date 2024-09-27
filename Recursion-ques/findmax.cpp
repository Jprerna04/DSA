#include<iostream>
#include<limits.h>
using namespace std;

void findmax(int arr[], int n, int i, int& maxi){
    if (i>=n){
        return;
    }
    maxi=max(INT_MIN, arr[i]);
    findmax(arr,n,i+1,maxi);
}

int main(){
    int arr[]={10,20,30,40};
    int n=4;
    int i=0;
    int k=INT_MIN;
    findmax(arr,n,i,k);
    cout<<k;
    return 0;
}