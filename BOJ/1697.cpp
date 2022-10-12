//
// Created by 이경민 on 2022/10/13.
//
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,k;
int counts[100001];

bool is_in_range(int x) {
    return x>=0 && x<=100000;
}

int bfs() {
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now==k) {
            return counts[now];
        }
        if(is_in_range(now-1)) {
            if(counts[now-1]==0) {
                q.push(now-1);
                counts[now-1] = counts[now]+1;
            }
        }
        if(is_in_range(now+1)) {
            if(counts[now+1]==0) {
                q.push(now+1);
                counts[now+1] = counts[now]+1;
            }
        }
        if(is_in_range(now*2)) {
            if(counts[now*2]==0) {
                q.push(now*2);
                counts[now*2] = counts[now]+1;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    cout<<bfs();
}
