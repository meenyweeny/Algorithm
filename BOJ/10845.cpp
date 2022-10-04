//
// Created by 이경민 on 2022-06-09.
//
#include<iostream>
#include<deque>
#include<string>
using namespace std;

deque<int> dq;
int n,x;
string cmd;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>cmd;
        if(cmd=="push"){
            cin>>x;
            dq.push_back(x);
        }
        else if(cmd=="pop") {
            if(dq.empty()) cout<<"-1\n";
            else {
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(cmd=="size"){
            cout<<dq.size()<<"\n";
        }
        else if(cmd=="empty"){
            cout<<dq.empty()<<"\n";
        }
        else if(cmd=="front"){
            if(dq.empty()) cout<<"-1\n";
            else {
                cout<<dq.front()<<"\n";
            }
        }
        else if(cmd=="back"){
            if(dq.empty()) cout<<"-1\n";
            else {
                cout<<dq.back()<<"\n";
            }
        }
    }
}
