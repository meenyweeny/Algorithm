//
// Created by 이경민 on 2022/10/04.
//
#include<iostream>
#include<queue>
using namespace std;

int n,m;
string str;
bool map[101][101];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool visited[101][101];

bool isInRange(int x,int y) {
    return x>=1 && x<=n && y>=1 && y<=m;
}

int bfs() {
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},1});
    visited[1][1] = true;

    int nx,ny;

    while(!q.empty()) {

        int front_x = q.front().first.first;
        int front_y = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if(front_x == n && front_y == m) {
            return count;
        }

        for(int i=0; i<4; i++) {
            nx = front_x + dx[i];
            ny = front_y + dy[i];

            if(!isInRange(nx,ny)) {
                continue;
            }

            if(!map[nx][ny]) {
                continue;
            }

            if(visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;

            q.push({{nx,ny},count+1});
        }
    }

    return -1;
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>str;
        for(int k=1; k<=m; k++) {
            map[i][k] = (str[k-1] == '1');
        }
    }

    cout<<bfs();
}
