#include<iostream>
using namespace std;

int n,m;
int package = 1001;
int singles = 1001;
int answer;

void input() {
    cin>>n>>m;
    int a,b;
    while(m--) {
        cin>>a>>b;
        package = min(package,a);
        singles = min(singles,b);
    }
}

void solution() {
    package = min(package, singles*6);
    while(n>=6) {
        answer += package;
        n-=6;
    }
    if(n*singles>package) {
        answer+=package;
    } else {
        answer+=(n*singles);
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
