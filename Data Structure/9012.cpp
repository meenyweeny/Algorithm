//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
using namespace std;

int n,sz;
string cmd;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>cmd;
        for(auto i:cmd){
            if(i=='(') ++sz;
            else {
                --sz;
                if(sz==-1) break;
            }
        }
        sz == 0 ? cout<<"YES\n" : cout<<"NO\n";
        sz=0;
    }
}
