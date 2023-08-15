#include<iostream>
#include<set>
using namespace std;

const int sz = 1e5 + 1;
int n,answer;
int train[sz];
set<int> galaxy;

void solve() {
    int m;
    cin>>n>>m;
    int c,i,x;
    while(m--) {
        cin>>c>>i;
        if(c==1) {
            cin>>x;
            train[i] |= (1<<x);
        } else if(c==2) {
            cin>>x;
            train[i] &= ~(1<<x);
        } else if(c==3) {
            train[i] <<= 1;
            train[i] &= ((1<<21) - 1);
        } else if(c==4) {
            train[i] >>= 1;
            train[i] &= ~1;
        }
    }
    for(int i=1; i<=n; i++) {
        answer += galaxy.insert(train[i]).second;
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
