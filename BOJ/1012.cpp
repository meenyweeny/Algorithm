//
// Created by 이경민 on 2022/10/04.
//
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool map[50][50];
bool visited[50][50];
int n,m,t,k,a,b,answer;

bool is_in_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(int x,int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!is_in_range(nx,ny)) {
                continue;
            }

            if(visited[nx][ny]) {
                continue;
            }

            if(!map[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;

    while(t--) {

        cin>>m>>n>>k;

        while(k--) {
            cin>>a>>b;
            map[b][a]= true;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && map[i][j]) {
                    ++answer;
                    bfs(i,j);
                }
            }
        }

        cout<<answer<<"\n";

        answer = 0;
        memset(map,false,sizeof(map));
        memset(visited,false,sizeof(visited));
    }
}
