#include<iostream>
using namespace std;

const int inf = 2e9;
const int range = 5e5 + 1;
int n, answer;
bool usable[10];

void input() {
    cin>>n;
    int m,k;
    cin>>m;
    while(m--) {
        cin>>k;
        usable[k] = false;
    }
}

void process(int dest) {
    int ret = 0;
    int tmp = dest;
    while(tmp>0) {
        if(!usable[tmp%10]) {
            ret = inf;
            break;
        }
        ++ret;
        tmp/=10;
    }
    answer = min(answer,ret+abs(n-dest));
}

void solution() {
    answer = abs(n-100);
    if(answer==0) {
        cout<<answer;
        return;
    }
    answer = min(answer,usable[0] ? n+1 : inf);
    for(int i=1; i<=range*2; i++) {
        process(i);
    }
    cout<<answer;
}

void solve() {
    fill(usable,usable+10,true);
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
