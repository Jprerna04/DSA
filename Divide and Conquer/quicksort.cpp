#include<iostream>
using namespace std;

int partioning(int arr[], int s, int e){
    //find pivot element
    int pivotIndex=s;
    int pivotElement=arr[pivotIndex];

    //change psoition of pivot element
    int count=0;
    for (int i=s+1;i<=e;i++){
        if (arr[i]<=pivotElement){
            count++;
        }
    }
    int rightIndex=s+count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex=rightIndex;

    //check all left subarray is less that pivot
    //check right subarray is greater than pivot
    int i=s;
    int j=e;
    while (i<pivotIndex && j>pivotIndex){
        while (arr[i]<=pivotElement){
            i++;
        }
        while (arr[j]>pivotElement){
            j--;
        }
        if (i<pivotIndex && j>pivotIndex){
        swap(arr[i], arr[j]);
    }
}
    return pivotIndex;
}

void quicksort(int arr[], int s, int e){
    //base condition
    if (s>=e){
        return;
    }

    //partioning condition
    int p=partioning(arr,s,e);

    //recursive calls
    //left
    quicksort(arr,s,p-1);

    //right
    quicksort(arr,p+1,e);
}

int main(){
    int arr[]={8,1,20,30,6,5,60,5};
    int n=8;
    int s=0;
    int e=n-1;
    quicksort(arr,s,e);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}