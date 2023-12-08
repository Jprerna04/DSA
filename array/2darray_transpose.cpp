#include<iostream>
using namespace std;
void traverse(int arr[][3], int rows, int cols, int trarray[3][3]){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            trarray[j][i]=arr[i][j];
        }
    }
}
void printarr(int arr[][3], int rows, int cols){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[3][3];
    int trarray[3][3];
    int rows=3;
    int cols=3;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Before traverse array is: "<<endl;
    printarr(arr, rows, cols);
    traverse(arr,3,3,trarray);
    cout<<"After traverse array is: "<<endl;
    printarr(trarray,rows,cols);
}