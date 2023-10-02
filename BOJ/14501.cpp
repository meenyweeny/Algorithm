#include<iostream>
using namespace std;

int n, answer;
int t[15],p[15];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>t[i]>>p[i];
    }
}

void process(int day, int earn) {
    if(day<=n) {
        answer = max(answer,earn);
    }
    if(day>=n) {
        return;
    }
    process(day+t[day],earn+p[day]);
    process(day+1,earn);
}

void solve() {
    input();
    process(0,0);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
