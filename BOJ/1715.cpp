//
// Created by 이경민 on 2022/09/07.
//
#include<iostream>
#include<queue>
using namespace std;

int n,x;
int sum,tmp;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;

    for(int i=0; i<n; i++) {
        cin >> x;
        pq.push(x);
    }
    while(pq.size()>1){
        tmp=pq.top();
        sum += pq.top();
        pq.pop();
        tmp+=pq.top();
        sum += pq.top();
        pq.pop();
        pq.push(tmp);
    }
    cout<<sum;
}
