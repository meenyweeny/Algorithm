#include<iostream>
#include<vector>
using namespace std;

int map[9][9];
vector<pair<int,int>> block;
bool flag;

void input() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>map[i][j];
            if(!map[i][j]) {
                block.push_back({i, j});
            }
        }
    }
}

bool check(int x,int y,int num) {
    for(int i=0; i<9; i++) {
        if(map[i][y] == num) {
            return false;
        }
        if(map[x][i] == num) {
            return false;
        }
    }
    int px = (x/3)*3;
    int py = (y/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(map[px + i][py + j] == num) {
                return false;
            }
        }
    }
    return true;
}

void process(int count) {
    if(flag) {
        return;
    }
    if(count == block.size()) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout<<map[i][j]<<' ';
            }
            cout<<'\n';
        }
        flag = true;
        return;
    }
    int nx = block[count].first;
    int ny = block[count].second;
    for(int i=1; i<=9; i++) {
        if(check(nx,ny,i)) {
            map[nx][ny] = i;
            process(count+1);
            map[nx][ny] = 0;
        }
    }
}

void solve() {
    input();
    process(0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
