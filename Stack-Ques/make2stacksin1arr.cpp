#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }

    void push1(int data){
        if (top2-top1==1){
            cout<<"OVERFLOW"<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }

    void pop1(){
        if (top1==-1){
            cout<<"UNDERFLOW";
        }
        else{
            top1--;
        }
    }

    void push2(int data){
        if (top2-top1==1){
            cout<<"OVERFLOW"<<endl;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }

    void pop2(){
        if (top2==size){
            cout<<"UNDERFLOW";
        }
        else{
            top2++;
        }
    }

    void print(){
        for (int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Stack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.print();
    cout<<endl;

    s.push2(50);
    s.push2(60);
    s.push2(70);
    s.print();
    return 0;
}