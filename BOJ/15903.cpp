#include<iostream>
#include<queue>
using namespace std;

int n,m;
long long answer;
priority_queue<long long> pq;

void solve() {
    cin>>n>>m;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        pq.push(-k);
    }
    long long a,b;
    while(m--) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    while(!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    cout<<-answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
