#include<iostream>
using namespace std;

int r,c,answer;
char map[22][22];
bool visited[26];

void input() {
    cin>>r>>c;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin>>map[i][j];
        }
    }
}

bool is_in_range(int x,int y) {
    return x>0 && x<=r && y>0 && y<=c;
}

void process(int x,int y,int count) {
    answer = max(answer,count);
    for(int i=0; i<4; i++) {
        int nx = x + "2011"[i] - '1';
        int ny = y + "1120"[i] - '1';
        if(!is_in_range(nx,ny)) {
            continue;
        }
        int index = map[nx][ny] - 'A';
        if(visited[index]) {
            continue;
        }
        visited[index] = true;
        process(nx,ny,count+1);
        visited[index] = false;
    }
}

void solve() {
    input();
    process(0,1,0);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
