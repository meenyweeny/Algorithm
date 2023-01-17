//
// Created by 이경민 on 2023/01/17.
//
#include<iostream>
using namespace std;

int n,m;
int dist[101][101];
const int inf = 1e9;

void init() {
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            dist[i][j] = (i == j) ? 0 : inf;
        }
    }
}

void input() {
    cin>>n>>m;
    int a,b,c;
    while(m--) {
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
    }
}

void floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dist[i][j] == inf) {
                cout<<0;
            } else {
                cout<<dist[i][j];
            }
            cout<<' ';
        }
        cout<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();
    input();
    floyd();
}
