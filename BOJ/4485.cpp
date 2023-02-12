//
// Created by 이경민 on 2023/02/13.
//
#include<iostream>
#include<queue>
using namespace std;

struct point {
    int x,y;
    int weight;

    bool operator<(const point & b) const {
        return weight > b.weight;
    }
};

int map[126][126];
int n;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int dist[126][126];
const int inf = 2e9;

bool is_in_range(int x,int y) {
    return x>0 && x<=n && y>0 && y<=n;
}

void solution() {
    fill(&dist[0][0], &dist[125][126], inf);
    dist[1][1] = map[1][1];
    priority_queue<point> pq;
    pq.push({1,1, dist[1][1]});

    while(!pq.empty()) {
        point top = pq.top();
        pq.pop();

        if(dist[top.x][top.y] < top.weight) {
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = top.x + dx[i];
            int ny = top.y + dy[i];

            if(!is_in_range(nx,ny)) {
                continue;
            }

            if(dist[nx][ny] > map[nx][ny] + top.weight) {
                dist[nx][ny] = map[nx][ny] + top.weight;
                pq.push({nx,ny,dist[nx][ny]});
            }
        }
    }
}

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }
}

void solve() {
    int t=1;
    while(1) {
        input();
        if(n==0) {
            break;
        }
        solution();
        cout<<"Problem "<<t<<": "<<dist[n][n]<<'\n';
        ++t;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
