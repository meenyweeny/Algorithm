//
// Created by 이경민 on 2022/06/18.
//
#include<iostream>
#include<string>
using namespace std;

int t,x;
string cmd;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;
    while(t--){
        cin>>x;
        cin>>cmd;
        for(auto i:cmd){
            for(int k=0; k<x; k++) cout<<i;
        }
        cout<<"\n";
    }
}
