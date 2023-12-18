#include<iostream>
#include<queue>
using namespace std;

const int bucketsize = 1e3;
int n,m;
int map[bucketsize][bucketsize];
int dist[bucketsize][bucketsize];
pair<int,int> start;

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
            if(map[i][j]==2) {
                start = {i,j};
                map[i][j]=0;
            }
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void solution() {
    queue<pair<int,int>> q;
    q.push(start);
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';
            if(!check_range(nx,ny)) {
                continue;
            }
            if(!map[nx][ny]) {
                continue;
            }
            if(dist[nx][ny]) {
                continue;
            }
            dist[nx][ny] = dist[fx][fy] + 1;
            q.push({nx,ny});
        }
    }
}

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==1 && !dist[i][j]) {
                cout<<-1<<' ';
            } else {
                cout<<dist[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
}

void solve() {
    input();
    solution();
    print();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
