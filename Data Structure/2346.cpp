//
// Created by 이경민 on 2022/08/30.
//
#include<iostream>
#include<deque>
using namespace std;

int n,x,nxt;
deque<pair<int,int>> dq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>x;
        dq.push_back({i,x});
    }
    nxt = dq.front().second;
    cout<<dq.front().first<<" ";
    dq.pop_front();

    while(!dq.empty()){
        if(nxt < 0) {
            nxt *= -1;
            for(int i=1; i < nxt; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout<<dq.back().first<<" ";
            nxt = dq.back().second;
            dq.pop_back();
        }
        else {
            for (int i = 1; i < nxt; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout<<dq.front().first<<" ";
            nxt = dq.front().second;
            dq.pop_front();
        }
    }
}
