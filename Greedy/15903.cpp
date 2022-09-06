//
// Created by 이경민 on 2022/09/07.
//
#include<iostream>
#include<queue>
using namespace std;

#define ll unsigned long long

int n,m;
priority_queue<ll,vector<ll>, greater<ll>> pq;
ll sum;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    while(n--){
        cin>>sum;
        pq.push(sum);
    }
    while(m--){
        sum=0;
        sum+=pq.top();
        pq.pop();
        sum+=pq.top();
        pq.pop();
        pq.push(sum);
        pq.push(sum);
    }
    sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
}
