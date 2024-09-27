#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

    vector<int>prices;
    prices.push_back(8);
    prices.push_back(4);
    prices.push_back(6);
    prices.push_back(2);
    prices.push_back(3);
    stack<int>st;
    vector<int>ans(prices.size());
    st.push(-1);

    for (int i=prices.size()-1;i>=0;i--){
        int val=prices[i];
        while (st.top()>=val){
            st.pop();
        }
        ans[i]=st.top();
        st.push(val);
    }
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}