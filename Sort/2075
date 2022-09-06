//
// Created by 이경민 on 2022/09/06.
//
#include<iostream>
#include<queue>
using namespace std;

int n,t;
priority_queue<int,vector<int>, greater<int>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        pq.push(t);
    }
    for(int i=1; i<n; i++){
        for(int k=0; k<n; k++){
            cin>>t;
            if(pq.top()<t){
                pq.push(t);
                pq.pop();
            }
        }
    }
    cout<<pq.top();
}
