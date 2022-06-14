//
// Created by 이경민 on 2022-06-14.
//
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n,k;
string cmd;
stack<int> st;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>cmd;
        if(cmd=="push"){
            cin>>k;
            st.push(k);
        }
        else if(cmd=="pop"){
            if(st.empty()) cout<<"-1\n";
            else {
                cout<<st.top()<<"\n";
                st.pop();
            }
        }
        else if(cmd == "size") {
            cout<<st.size()<<"\n";
        }
        else if(cmd=="empty"){
            cout<<st.empty()<<"\n";
        }
        else {
            st.empty() ? cout<<"-1\n" : cout<<st.top()<<"\n";
        }
    }
}
