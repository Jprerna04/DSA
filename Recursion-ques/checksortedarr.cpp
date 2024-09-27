#include<iostream>
#include<vector>
using namespace std;

bool checksorted(vector<int>& arr, int& n, int i){
    //BC
    if (i==n-1){
        return true;
    }

    //Processing
    if (arr[i+1]<arr[i]){
        return false;
    }

    //RR
    checksorted(arr,n,i+1);
}

int main(){
    vector<int>v{10,20,30,40,50};
    int n=v.size();
    int i=0;
    cout<<checksorted(v,n,i);
    return 0;
}