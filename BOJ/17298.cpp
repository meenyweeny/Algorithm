#include<iostream>
#include<deque>
using namespace std;

const int sz = 1e6 + 2;
int n;
deque<pair<int,int>> dq;
int answer[sz];

void solve() {
    fill(answer,answer+sz,-1);
    cin>>n;
    int k,top;
    for(int i=1; i<=n; i++) {
        cin>>k;
        top = dq.empty() ? -1 : dq.back().first;
        while(!dq.empty() && k > top) {
            answer[dq.back().second] = k;
            dq.pop_back();
            top = dq.empty() ? -1 : dq.back().first;
        }
        dq.push_back({k, i});
    }
    for(int i=1; i<=n; i++) {
        cout<<answer[i]<<' ';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
