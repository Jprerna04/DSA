#include<iostream>
using namespace std;

void searchlastcharRTL(string&s, char ch, int i, int&ans){
    //base condition
    if (i<0){
        return;
    }

    //processing
    if (s[i]==ch){
        ans=i;
        return;
    }

    //RC
    searchlastcharRTL(s,ch,i-1,ans);
}

int main(){
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    int ans=-1;
    int i=s.size()-1;
    searchlastcharRTL(s,ch,i,ans);
    cout<<ans;
}