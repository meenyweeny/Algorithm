#include<iostream>
using namespace std;

int n,m,k;
int mata[101][101];
int matb[101][101];

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>mata[i][j];
        }
    }
    cin>>m>>k;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=k; j++) {
            cin>>matb[i][j];
        }
    }
}

void solution() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            int sum = 0;
            for(int q=1; q<=m; q++) {
                sum += (mata[i][q]*matb[q][j]);
            }
            cout<<sum<<' ';
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
