#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Shark {
    int x,y,eat;
    int size=2;
};

int n,answer;
int map[20][20];
bool visited[20][20];
Shark shark;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
            if(map[i][j]==9) {
                map[i][j] = 0;
                shark.x = i;
                shark.y = j;
            }
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

pair<int,pair<int,int>> find_fish() {
    fill(&visited[0][0],&visited[19][20],false);
    queue<pair<pair<int,int>,int>> q;
    q.push({{shark.x,shark.y},0});
    visited[shark.x][shark.y] = true;
    vector<pair<int,int>> pivot;
    int before;
    while(!q.empty()) {
        int fx = q.front().first.first;
        int fy = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if(map[fx][fy]>0 && map[fx][fy]<shark.size) {
            if(pivot.empty()) {
                pivot.push_back({fx,fy});
                before = count;
            } else {
                if(count>before) {
                    break;
                } else {
                    pivot.push_back({fx,fy});
                }
            }
        }

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';

            if(!check_range(nx,ny)) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            if(map[nx][ny]>shark.size) {
                continue;
            }
            q.push({{nx,ny},count+1});
            visited[nx][ny] = true;
        }
    }
    if(pivot.empty()) {
        return {0,{-1,-1}};
    } else {
        sort(pivot.begin(), pivot.end());
        return {before,pivot[0]};
    }
}

void solution() {
    while(1) {
        pair<int,pair<int,int>> fish = find_fish();
        if(fish.first <= 0) {
            break;
        }
        ++shark.eat;
        map[fish.second.first][fish.second.second] = 0;
        shark.x = fish.second.first;
        shark.y = fish.second.second;
        if(shark.size==shark.eat) {
            shark.eat = 0;
            ++shark.size;
        }
        answer += fish.first;
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
