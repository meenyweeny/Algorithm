#include<iostream>
#include<vector>
using namespace std;

int map[9][9];
vector<pair<int,int>> puzzle;
bool flag;

void input() {
    string str;
    for(int i=0; i<9; i++) {
        cin>>str;
        for(int j=0; j<9; j++) {
            map[i][j] = str[j]-'0';
            if(map[i][j]==0) {
                puzzle.push_back({i,j});
            }
        }
    }
}

void print() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
}

bool is_valid(int x,int y,int value) {
    for(int i=0; i<9; i++) {
        if (map[x][i] == value) {
            return false;
        }
        if (map[i][y] == value) {
            return false;
        }
    }
    int px = (x/3)*3;
    int py = (y/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(map[px+i][py+j]==value) {
                return false;
            }
        }
    }
    return true;
}

void process(int index) {
    if(flag) {
        return;
    }
    if(index==puzzle.size()) {
        flag = true;
        print();
        return;
    }
    pair<int,int> loc = puzzle[index];
    for(int i=1; i<10; i++) {
        if(is_valid(loc.first,loc.second,i)) {
            map[loc.first][loc.second] = i;
            process(index+1);
            map[loc.first][loc.second] = 0;
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
