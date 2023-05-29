#include<iostream>
#include<queue>
using namespace std;

int n,m;
char map[1001][1001];
int answer = 1e9;
const int inf = 1e9;
int dist_f[1001][1001];
int dist_b[1001][1001];

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>map[i][j];
        }
    }
}

bool is_in_range(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=m;
}

void front_bfs() {
    queue<pair<int,int>> q;
    q.push({1,1});
    dist_f[1][1] = 1;
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';

            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]=='1') {
                continue;
            }
            if(dist_f[nx][ny]!=0) {
                continue;
            }
            q.push({nx,ny});
            dist_f[nx][ny] = dist_f[fx][fy] + 1;
        }
    }
}

void back_bfs() {
    queue<pair<int,int>> q;
    q.push({n,m});
    dist_b[n][m] = 1;
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';

            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]=='1') {
                continue;
            }
            if(dist_b[nx][ny]!=0) {
                continue;
            }
            q.push({nx,ny});
            dist_b[nx][ny] = dist_b[fx][fy] + 1;
        }
    }
}

void find_min_path() {
    if(dist_f[n][m]!=0) {
        answer = dist_f[n][m];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(map[i][j]=='0') {
                continue;
            }
            int ans_f, ans_b;
            ans_f = ans_b = inf;
            for(int k=0; k<4; k++) {
                int nx = i + "2011"[k] - '1';
                int ny = j + "1120"[k] - '1';

                if(!is_in_range(nx,ny)) {
                    continue;
                }
                if(dist_f[nx][ny]>0) {
                    ans_f = min(ans_f, dist_f[nx][ny]);
                }
                if(dist_b[nx][ny]>0) {
                    ans_b = min(ans_b, dist_b[nx][ny]);
                }
            }
            answer = min(answer, ans_f+ans_b+1);
        }
    }
    if(answer==inf) {
        answer = -1;
    }
    cout<<answer;
}

void solution() {
    front_bfs();
    back_bfs();
    find_min_path();
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
