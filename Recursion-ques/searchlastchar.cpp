#include<iostream>
using namespace std;

void searchlastcharLTR(string&s, char ch, int i, int&ans){
    //base condition
    if (i>=s.size()){
        return;
    }

    //processing
    if (s[i]==ch){
        ans=i;
    }

    //RC
    searchlastcharLTR(s,ch,i+1,ans);
}

int main(){
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    int ans=-1;
    int i=0;
    searchlastcharLTR(s,ch,i,ans);
    cout<<ans;
}