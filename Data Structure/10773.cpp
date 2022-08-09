//
// Created by 이경민 on 2022/08/10.
//
#include<iostream>
#include<stack>
using namespace std;

int k,sum,x;
stack<int> st;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>k;
    while(k--){
        cin>>x;
        if(x==0) {
            sum-=st.top();
            st.pop();
            continue;
        }
        sum+=x;
        st.push(x);
    }
    cout<<sum;
}
