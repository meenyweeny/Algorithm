#include<iostream>
using namespace std;

int n;
int t[16];
int p[16];
int answer = -1;

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>t[i]>>p[i];
    }
}

void run(int day,int price) {
    if(day-1>n) {
        return;
    }
    answer = max(answer, price);
    for(int i=day; i<=n; i++) {
        run(i+t[i],price+p[i]);
    }
}

void solution() {
    for(int i=1; i<=n; i++) {
        run(i,0);
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
