#include<iostream>
using namespace std;

int n,m;
int k,i,j,x,y;
int map[301][301];

void input() {
    cin>>n>>m;
    for(int q=1; q <= n; q++) {
        for(int w=1; w <= m; w++) {
            cin>>map[q][w];
            map[q][w] += map[q][w - 1];
        }
    }
}

int solution() {
    int sum = 0;
    for(int q=i; q<=x; q++) {
        sum += map[q][y];
        sum -= map[q][j-1];
    }
    return sum;
}

void solve() {
    input();
    cin>>k;
    while(k--) {
        cin>>i>>j>>x>>y;
        cout<<solution()<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
