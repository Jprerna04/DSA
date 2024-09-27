#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int top;
    int size;

    Stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }

    void push(int data){
        if (size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if (top==-1){
            cout<<"Stack Underflow";
        }
        else{
            top--;
        }
    }

    void getTop(){
        if (top==-1){
            cout<<"Stack Underflow";
        }
        else{
            cout<<arr[top];
        }
    }

    void getSize(){
        cout<<top+1;
    }
};

int main(){
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);

    return 0;
}