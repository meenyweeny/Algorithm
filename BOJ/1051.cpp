#include<iostream>
using namespace std;

int n,m;
int map[51][51];

bool in_range(int x,int y,int length) {
    return n>=(x+length) && m>=(y+length);
}

bool check_point(int x,int y,int length) {
    bool ret = true;
    ret = ret && (map[x][y] == map[x+length][y]);
    ret = ret && (map[x+length][y] == map[x][y+length]);
    ret = ret && (map[x][y+length] == map[x+length][y+length]);
    return ret;
}

void input() {
    cin>>n>>m;
    string cmd;
    for(int i=1; i<=n; i++) {
        cin>>cmd;
        for(int j=0; j<m; j++) {
            map[i][j+1] = cmd[j]-48;
        }
    }
}

void solution() {
    int answer = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int dist = 1;
            while(1) {
                if(!in_range(i, j, dist)) {
                    break;
                }
                if(check_point(i, j, dist)) {
                    ++dist;
                    answer = max(answer, dist * dist);
                } else {
                    ++dist;
                }
            }
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
