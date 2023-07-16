#include<iostream>
#include<deque>
using namespace std;

const char water = '*';
const char stone = 'X';
const char beaver = 'D';
const char dochi = 'S';
int r,c;
char map[51][51];
bool visited[51][51];
pair<int,int> now;
deque<pair<int,int>> waters;

void input() {
    cin>>r>>c;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin>>map[i][j];
            if(map[i][j]==dochi) {
                now = {i,j};
            } else if(map[i][j]==water) {
                waters.push_back({i,j});
            }
        }
    }
}

bool is_in_range(int x,int y) {
    return x>0 && y>0 && x<=r && y<=c;
}

void spread_water() {
    deque<pair<int,int>> tmp;
    for(auto w:waters) {
        for(int i=0; i<4; i++) {
            int nx = w.first + "2011"[i] - '1';
            int ny = w.second + "1120"[i] - '1';
            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]==beaver || map[nx][ny]==stone || map[nx][ny]==water) {
                continue;
            }
            map[nx][ny] = water;
            tmp.push_back({nx,ny});
        }
    }
    waters = tmp;
//    for(auto w:waters) {
//        cout<<w.first<<", "<<w.second<<endl;
//    }
//    cout<<"--------------------\n\n";
}

void process() {
    deque<pair<int,pair<int,int>>> q;
    q.push_back({0,{now.first, now.second}});
    int before = -1;
    visited[now.first][now.second] = true;

    while(!q.empty()) {
        int count = q.front().first;
        int fx = q.front().second.first;
        int fy = q.front().second.second;
        q.pop_front();

        if(map[fx][fy]==beaver) {
            cout<<count;
            return;
        }

        if(count!=before) {
            spread_water();
            before = count;
        }

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';

            if(!is_in_range(nx,ny)) {
                continue;
            }

            if(map[nx][ny]==stone || map[nx][ny]==water) {
                continue;
            }

            if(visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push_back({count+1, {nx,ny}});
        }
    }

    cout<<"KAKTUS";
}

void solve() {
    input();
    process();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
