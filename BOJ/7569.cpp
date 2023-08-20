#include<iostream>
#include<queue>
using namespace std;

struct Point {
    int x,y,h;
};

int n,m,h,answer;
int map[100][100][100];
queue<pair<Point,int>> q;

void input() {
    cin>>m>>n>>h;
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>map[i][j][k];
                if(map[i][j][k] == 1) {
                    q.push({{i, j, k},0});
                }
            }
        }
    }
}

bool check_range(int x,int y,int z) {
    return x>=0 && y>=0 && z>=0 && x<n && y<m && z<h;
}

void bfs() {
    while(!q.empty()) {
        int fx = q.front().first.x;
        int fy = q.front().first.y;
        int fh = q.front().first.h;
        int count = q.front().second;
        q.pop();

        answer = count++;

        for(int i=0; i<6; i++) {
            int nx = fx + "021111"[i] - '1';
            int ny = fy + "110211"[i] - '1';
            int nh = fh + "111102"[i] - '1';

            if(!check_range(nx,ny,nh)) {
                continue;
            }
            if(map[nx][ny][nh]!=0) {
                continue;
            }
            map[nx][ny][nh] = 1;
            q.push({{nx,ny,nh},count});
        }
    }
}

void search() {
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j][k]==0) {
                    answer = -1;
                    return;
                }
            }
        }
    }
}

void solution() {
    bfs();
    search();
    cout<<answer;
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
