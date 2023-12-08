#include<iostream>
#include<limits.h>
using namespace std;
int findmax(int arr[][3], int rows, int cols){
    int max=INT_MIN;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if (arr[i][j]>max){
                max=arr[i][j];
            }
        }
    }
    return max;
}
int main(){
    int arr[3][3];
    int rows=3;
    int cols=3;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout<< arr[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<findmax(arr,rows,cols);

    return 0;
}