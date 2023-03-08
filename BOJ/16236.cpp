#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n;
int map[21][21];
bool visited[21][21];
int shark_eat;
pair<int,int> shark_position;
int answer,shark_size;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int,pair<int,int>>> fish;

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
            if(map[i][j]==9) {
                shark_position.first = i;
                shark_position.second = j;
            }
        }
    }
}

bool is_in_range(int x,int y) {
    return x>0 && y>0 && x<=n && y<=n;
}

void bfs() {
    fish.clear();
    queue<pair<pair<int,int>,int>> q;
    q.push({{shark_position.first,shark_position.second},0});
    memset(visited,false,sizeof(visited));
    visited[shark_position.first][shark_position.second] = true;

    while(!q.empty()) {
        int fx = q.front().first.first;
        int fy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]>shark_size) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({{nx,ny},cnt+1});
            if(map[nx][ny]<shark_size && map[nx][ny]!=0) {
                fish.push_back({cnt+1,{nx,ny}});
            }
        }
    }
}

void solution() {
    shark_size = 2;
    while(1) {
        bfs();
        if(fish.empty()) {
            break;
        }
        sort(fish.begin(), fish.end());
        map[fish.front().second.first][fish.front().second.second] = 0;
        ++shark_eat;
        answer += fish.front().first;
        map[shark_position.first][shark_position.second] = 0;
        shark_position.first = fish.front().second.first;
        shark_position.second = fish.front().second.second;
        map[shark_position.first][shark_position.second] = 9;
        if(shark_eat==shark_size) {
            ++shark_size;
            shark_eat = 0;
        }
    }
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
