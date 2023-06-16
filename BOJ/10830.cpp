#include<iostream>
using namespace std;

const int mod = 1e3;
unsigned long long n,b;
unsigned long long map[6][6];
unsigned long long answer[6][6];
unsigned long long tmp[6][6];

void input() {
    cin>>n>>b;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
        answer[i][i] = 1;
    }
}

void mul(unsigned long long a[6][6], unsigned long long c[6][6]) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            tmp[i][j] = 0;
            for(int k=1; k<=n; k++) {
                tmp[i][j] += (a[i][k] * c[k][j]);
            }
            tmp[i][j]%=mod;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

void solution() {
    while(b>0) {
        if(b%2) {
            mul(answer,map);
        }
        mul(map,map);
        b/=2;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }
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
