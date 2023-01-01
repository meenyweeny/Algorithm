//
// Created by 이경민 on 2023/01/01.
//
#include<iostream>
#include<queue>
using namespace std;

int n,x;
queue<int> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(1) {
        cin>>x;
        if(x==-1) {
            break;
        }
        if(x==0) {
            q.pop();
        } else {
            if(q.size()<n) {
                q.push(x);
            }
        }
    }
    if(q.empty()) {
        cout<<"empty";
    } else {
        while(!q.empty()) {
            cout<<q.front()<<" ";
            q.pop();
        }
    }
}
