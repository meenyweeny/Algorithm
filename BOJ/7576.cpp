//
// Created by 이경민 on 2022/10/05.
//
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,x;
queue<pair<pair<int,int>,int>> q;
bool visited[1001][1001];
int map[1001][1001];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool is_in_range(int a,int b) {
    return a>=1 && a<=n && b>=1 && b<=m;
}

int bfs() {
    int answer = -1;

    while(!q.empty()) {
        int fx = q.front().first.first;
        int fy = q.front().first.second;
        int count = q.front().second;
        q.pop();

        answer = max(answer, count);

        for(int i=0; i<4; i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];

            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]==-1) {
                continue;
            }
            if(map[nx][ny]==1) {
                continue;
            }
            map[nx][ny] = 1;
            q.push({{nx,ny},count+1});
        }
    }

    for(int i=1; i<=n; i++) {
        for(int k=1; k<=m; k++) {
            if(map[i][k]==0) {
                return -1;
            }
        }
    }

    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>m>>n;

    for(int i=1; i<=n; i++) {
        for(int k=1; k<=m; k++) {
            cin>>x;
            map[i][k] = x;
            if(x==1) {
                q.push({{i,k},0});
            }
        }
    }

    cout<<bfs();
}
