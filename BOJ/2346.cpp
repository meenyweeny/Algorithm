#include<iostream>
#include<deque>
using namespace std;

int cnt;
deque<pair<int,int>> dq;

void input() {
    int n,k;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>k;
        dq.push_back({i,k});
    }
}

void turn_front(int count) {
    for(int i=1; i<count; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
    }
    cout<<dq.back().first<<' ';
    cnt = dq.back().second;
    dq.pop_back();
}

void turn_back(int count) {
    for(int i=1; i<count; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout<<dq.front().first<<' ';
    cnt = dq.front().second;
    dq.pop_front();
}

void solve() {
    input();
    while(!dq.empty()) {
        if(cnt>=0) {
            turn_back(cnt);
        } else {
            turn_front(-cnt);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
