#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    //new left and right sub array
    int* left=new int[len1];
    int* right=new int[len2];

    //insert into left subarray
    int k=s;
    for (int i=0;i<len1;i++){
        left[i]=arr[k];
        k++;
    }

    //insert into right subarray
    k=mid+1;
    for (int i=0;i<len2;i++){
        right[i]=arr[k];
        k++;
    }

    int leftPointer=0;
    int rightPointer=0;
    int currPointer=s;

    //insert smallest elemet of both array in main array
    while (leftPointer<len1 && rightPointer<len2){
        if (left[leftPointer]<right[rightPointer]){
            arr[currPointer++]=left[leftPointer++];
        }
        else{
            arr[currPointer++]=right[rightPointer++];
        }
    }

    //left subarray is left then
    while (leftPointer<len1){
        arr[currPointer++]=left[leftPointer++];
    }

    //right subarray is left then
    while (rightPointer<len2){
        arr[currPointer++]=right[rightPointer++];
    }
}

void mergesort(int* arr, int s, int e){
    //base condition
    //if s<e-->invalid
    //if s==e-->single element 
    if (s>=e){
        return;
    }

    int mid=(s+e)/2;

    //leftmergesort
    mergesort(arr,s,mid);

    //rightmergesort
    mergesort(arr,mid+1,e);

    //merge both sub arrays
    merge(arr,s,e);
}

int main(){
    int arr[]={7,9,5,8,1,4};
    int n=6;
    int s=0;
    int e=n-1;
    mergesort(arr,s,e);

    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}