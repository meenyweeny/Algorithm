//
// Created by 이경민 on 2022/08/22.
//
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int t,n,m,x,answer;
priority_queue<int> pq;
queue<pair<int,int>> q;

void clear() {
    while(!q.empty()) q.pop();
    while(!pq.empty()) pq.pop();
    answer = 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;

    while(t--) {
        cin>>n>>m;
        for(int i=0; i<n; i++) {
            cin>>x;
            pq.push(x);
            q.push({i,x});
        }
        while(!q.empty()) {
            if (q.front().second == pq.top()) {
                ++answer;
                if (q.front().first == m) {
                    cout<<answer<<"\n";
                    break;
                }
                pq.pop();
                q.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        clear();
    }
}
