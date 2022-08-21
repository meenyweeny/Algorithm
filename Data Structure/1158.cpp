//
// Created by 이경민 on 2022/08/22.
//
#include<iostream>
#include<queue>
using namespace std;

int n,k;
queue<int> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    cout<<"<";
    for(int i=1; i<=n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        for(int i=1; i<k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();
        if(!q.empty()) cout<<", ";
    }

    cout<<">";
}
