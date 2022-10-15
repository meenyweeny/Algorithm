#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
int map[8][8];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
vector<pair<int,int>> safe_area;
vector<pair<int,int>> virus;
int max_area = -1;

bool is_in_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs() {
    queue<pair<int,int>> q;

    int tmp_map[8][8];

    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            tmp_map[i][k] = map[i][k];
        }
    }

    for(auto i:virus) {
        q.push({i.first, i.second});
    }

    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];

            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny] == 1 || map[nx][ny] == 2) {
                continue;
            }

            map[nx][ny] = 2;
            q.push({nx,ny});
        }
    }

    int count = 0;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            if(map[i][k] == 0) {
                ++count;
            }
        }
    }

    max_area = max(max_area, count);

    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            map[i][k] = tmp_map[i][k];
        }
    }
}

void dfs(int count, int start) {
    if(count == 3) {
        bfs();
        return;
    }

    for(int i=start; i<safe_area.size(); i++) {
        if(map[safe_area[i].first][safe_area[i].second] != 0) {
            continue;
        }
        if(count==0 && start >= safe_area.size()-2) {
            break;
        }
        map[safe_area[i].first][safe_area[i].second] = 1;
        dfs(count+1, start+1);
        map[safe_area[i].first][safe_area[i].second] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            cin>>map[i][k];
            if(map[i][k] == 0) {
                safe_area.push_back({i, k});
            }
            else if(map[i][k] == 2) {
                virus.push_back({i,k});
            }
        }
    }

    dfs(0,0);
    cout<<max_area;
}
