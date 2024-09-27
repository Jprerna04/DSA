#include<iostream>
using namespace std;

// bool findvalue(string str, int len, int i, char key){
//     //Base Cond
//     if (i>=len){
//         return false;
//     }
//     //Processing
//     if (str[i]==key){
//         return true;
//     }
//     //RR
//     return findvalue(str,len,i+1,key);
// }

// int main(){
//     string str="prernajha";
//     int len=str.length();
//     int i=0;
//     char key='s';
//     cout<<findvalue(str,len,i,key);
//     return 0;
// }

int findvalue(string str, int len, int i, char key){
    //Base Cond
    if (i>=len){
        return -1;
    }
    //Processing
    if (str[i]==key){
        return i;
    }
    //RR
    return findvalue(str,len,i+1,key);
}

int main(){
    string str="prernajha";
    int len=str.length();
    int i=0;
    char key='j';
    cout<<findvalue(str,len,i,key);
    return 0;
}