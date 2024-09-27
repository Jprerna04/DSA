#include<iostream>
#include<vector>
using namespace std;

int findkey(vector<int>&arr, int s, int e, int& key){
    //base condition1
    if (s>e){
        return -1;
    }
    //base condition2
    int mid=(s+e)/2;
    if (arr[mid]==key){
        return mid;
    }

    //processing and rr
    if (arr[mid]<key){
        return findkey(arr,mid+1,e,key);
    }
    else{
        return findkey(arr,s,mid-1,key);
    }
}

int main(){
    vector<int>v{10,20,30,40,50,60};
    int n=v.size();
    int s=0;
    int e=n-1;
    int key=50;
    cout<<findkey(v,s,e,key);
    return 0;
}