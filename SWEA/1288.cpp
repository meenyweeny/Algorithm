#include<iostream>
using namespace std;

int n, k;
int full = (1<<10) - 1;
int check = 0;

void init() {
    k = 1;
    check = 0;
}

bool solution() {
    unsigned long long now = n*(k++);
    while(now>0) {
        check |= (1<<(now%10));
        now/=10;
    }
    return check!=full;
}

void solve() {
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        init();
        cin>>n;
        while(solution());
        cout<<'#'<<tc<<' '<<n*(k-1)<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
