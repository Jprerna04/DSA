//ques: PERMUTATION COMBINATION OF STRING

#include<iostream>
using namespace std;

void permuation_string(string& str, int i){
    //base
    if (i>=str.size()){
        cout<<str<<" ";
        return;
    }

    //process
    for (int j=i;j<str.size();j++){
        //swap ith and jth index
        swap(str[i],str[j]);

        //RE
        permuation_string(str,i+1);

        //str back to normal
        swap(str[i],str[j]);
    }
}

int main(){
    string str="abc";
    int i=0;
    permuation_string(str,i);
    return 0;
}