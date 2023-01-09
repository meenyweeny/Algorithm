#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int map[51][51];
int dp[51][51];
bool visited[51][51];

bool is_in_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int dfs(int x,int y) {

    if(!is_in_range(x,y)) {
        return 0;
    } else if(map[x][y]==0) {
        return 0;
    }

    if(visited[x][y]) {
        cout<<-1;
        exit(0);
    }

    if(dp[x][y]!=-1) {
        return dp[x][y];
    }

    dp[x][y] = 0;
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx=x+(map[x][y] * dx[i]);
        int ny=y+(map[x][y] * dy[i]);
        dp[x][y] = max(dp[x][y], dfs(nx,ny) + 1);
    }
    visited[x][y] = false;
    return dp[x][y];
}

void input() {
    cin>>n>>m;
    char x;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>x;
            if(x=='H') {
                map[i][j] = 0;
            } else {
                map[i][j] = x - '0';
            }
        }
    }
}

void solution() {
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
