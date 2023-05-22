#include<iostream>
#include<queue>
using namespace std;

struct Point {
    int x,y,count;
};

int m,n;
int map[1001][1001];
bool visited[1001][1001];

void input() {
    cin>>m>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>map[i][j];
        }
    }
}

bool is_in_range(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=m;
}

int bfs() {
    queue<Point> q;
    int count=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(map[i][j]==1) {
                visited[i][j] = true;
                q.push({i,j,0});
            }
        }
    }
    while(!q.empty()) {
        Point front = q.front();
        q.pop();
        count = front.count;
        for(int i=0; i<4; i++) {
            int nx = front.x + "2011"[i] - '1';
            int ny = front.y + "1120"[i] - '1';

            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            if(map[nx][ny]!=0) {
                continue;
            }
            map[nx][ny] = 1;
            visited[nx][ny] = true;
            q.push({nx,ny,front.count+1});
        }
    }
    return count;
}

void solution() {
    int count = bfs();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            count = (map[i][j] == 0) ? -1 : count;
        }
    }
    cout<<count;
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
