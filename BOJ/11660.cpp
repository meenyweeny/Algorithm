//
// Created by 이경민 on 2023/01/19.
//
#include<iostream>
using namespace std;

int n,m;
int map[1025][1025];

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }
}

void solution() {
    int x,xx,y,yy;

    for(int i=1; i<=n; i++) {
        for(int j=2; j<=n; j++) {
            map[i][j] += map[i][j-1];
        }
    }

    for(int i=2; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            map[i][j] += map[i-1][j];
        }
    }

    while(m--) {
        cin>>x>>y>>xx>>yy;
        cout<<map[xx][yy] - map[x-1][yy] - map[xx][y-1] + map[x-1][y-1]<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
