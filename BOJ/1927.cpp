//
// Created by 이경민 on 2022/09/01.
//
#include<iostream>
#include<queue>
using namespace std;

int n,x;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>x;
        if(x==0){
            if(pq.empty()) {
                cout<<"0\n";
                continue;
            }
            cout<<pq.top()<<"\n";
            pq.pop();
        }
        else pq.push(x);
    }
}
