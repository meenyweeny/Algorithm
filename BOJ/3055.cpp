#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const string kaktus = "KAKTUS";
const char stone = 'X';
const char water = '*';
const char emp = '.';
const char endpoint = 'D';
int r,c;
char map[50][50];
bool visited[50][50];
pair<int,int> start;
vector<pair<int,int>> waters;

void input() {
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>map[i][j];
            if(map[i][j]=='S') {
                map[i][j]=emp;
                start = {i,j};
            } else if(map[i][j]==water) {
                waters.push_back({i,j});
            }
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<r && y>=0 && y<c;
}

void spread_water() {
    int length = waters.size();
    for(int i=0; i<length; i++) {
        pair<int,int > w = waters[i];
        for(int i=0; i<4; i++) {
            int nx = w.first + "2011"[i] - '1';
            int ny = w.second + "1120"[i] - '1';
            if(!check_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]==water || map[nx][ny]==stone || map[nx][ny]==endpoint) {
                continue;
            }
            map[nx][ny] = water;
            waters.push_back({nx,ny});
        }
    }
}

string solution() {
    queue<pair<pair<int,int>,int>> q;
    q.push({start,0});
    visited[start.first][start.second] = true;
    int before = -1;
    while(!q.empty()) {
        int fx = q.front().first.first;
        int fy = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if(map[fx][fy]==endpoint) {
            return to_string(count);
        }
        if(before!=count) {
            spread_water();
            before = count;
        }
        ++count;
        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';

            if(!check_range(nx,ny)) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            if(map[nx][ny]==water || map[nx][ny]==stone) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({{nx,ny},count});
        }
    }
    return kaktus;
}

void solve() {
    input();
    cout<<solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
