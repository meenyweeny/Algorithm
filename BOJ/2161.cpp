#include<iostream>
#include<deque>
using namespace std;

int n;
deque<int> dq;

void solve() {
    cin>>n;

    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }

    while(dq.size()>1) {
        cout<<dq.front()<<' ';
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout<<dq.front();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
