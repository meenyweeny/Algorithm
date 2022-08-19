//
// Created by 이경민 on 2022/08/19.
//
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int n,x;
stack<pair<int,int>> st;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x;
        while(!st.empty()) {
            if(x<st.top().first) {
                cout<<st.top().second<<" ";
                break;
            }
            st.pop();
        }
        if(st.empty()) cout<<"0 ";
        st.push({x,i+1});
    }

}