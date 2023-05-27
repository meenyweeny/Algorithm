#include<iostream>
#include<queue>
using namespace std;

int n;
char map[51][51];
const int inf = 1e9;
int visited[51][51];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }
}

bool is_in_range(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=n;
}

void solution() {
    fill(&visited[0][0], &visited[50][51], inf);
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},0});
    visited[1][1] = 0;

    while(!q.empty()) {
        pair<int,int> top = q.front().first;
        int count = q.front().second;
        q.pop();

        if(count > visited[top.first][top.second]) {
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = top.first + ("0211"[i] - '1');
            int ny = top.second + ("1102"[i] - '1');

            if(!is_in_range(nx,ny)) {
                continue;
            }

            bool is_black = (map[nx][ny] == '0');
            if(visited[nx][ny] > count + is_black) {
                visited[nx][ny] = count + is_black;
                q.push({{nx,ny},visited[nx][ny]});
            }
        }
    }

    cout<<visited[n][n];
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
