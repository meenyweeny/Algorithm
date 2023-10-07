#include<iostream>
using namespace std;

int n,answer = -1;
int block[20][20];
bool visited[20][20];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> block[i][j];
        }
    }
}

void copy(int a[20][20], int b[20][20]) { //a에 b copy
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = b[i][j];
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void up(int map[20][20]) {
    fill(&visited[0][0], &visited[19][20], false);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int now = map[j][i];
            answer = max(answer,now);
            int x = j;
            int y = i;
            if(now==0) {
                continue;
            }
            while(1) {
                now = map[x][y];
                if(!check_range(x-1,y)) {
                    break;
                }
                if(map[x-1][y]!=0) {
                    if(map[x-1][y]==now && !visited[x-1][y]) {
                        map[x-1][y] += now;
                        answer = max(answer, now*2);
                        map[x][y] = 0;
                        visited[x-1][y] = true;
                    }
                    break;
                } else {
                    map[x-1][y] = now;
                    map[x][y] = 0;
                    --x;
                }
            }
        }
    }
}

void down(int map[20][20]) {
    fill(&visited[0][0], &visited[19][20], false);
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>=0; j--) {
            int now = map[j][i];
            answer = max(answer,now);
            int x = j;
            int y = i;
            if(now==0) {
                continue;
            }
            while(1) {
                now = map[x][y];
                if(!check_range(x+1,y)) {
                    break;
                }
                if(map[x+1][y]!=0) {
                    if(map[x+1][y]==now && !visited[x+1][y]) {
                        map[x+1][y] += now;
                        answer = max(answer, now*2);
                        map[x][y] = 0;
                        visited[x+1][y] = true;
                    }
                    break;
                } else {
                    map[x+1][y] = now;
                    map[x][y] = 0;
                    ++x;
                }
            }
        }
    }
}

void left(int map[20][20]) {
    fill(&visited[0][0], &visited[19][20], false);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int now = map[i][j];
            answer = max(answer,now);
            int x = i;
            int y = j;
            if(now==0) {
                continue;
            }
            while(1) {
                now = map[x][y];
                if(!check_range(x,y-1)) {
                    break;
                }
                if(map[x][y-1]!=0) {
                    if(map[x][y-1]==now && !visited[x][y-1]) {
                        map[x][y-1] += now;
                        answer = max(answer, now*2);
                        map[x][y] = 0;
                        visited[x][y-1] = true;
                    }
                    break;
                } else {
                    map[x][y-1] = now;
                    map[x][y] = 0;
                    --y;
                }
            }
        }
    }
}

void right(int map[20][20]) {
    fill(&visited[0][0], &visited[19][20], false);
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>=0; j--) {
            int now = map[i][j];
            answer = max(answer,now);
            int x = i;
            int y = j;
            if(now==0) {
                continue;
            }
            while(1) {
                now = map[x][y];
                if(!check_range(x,y+1)) {
                    break;
                }
                if(map[x][y+1]!=0) {
                    if(map[x][y+1]==now && !visited[x][y+1]) {
                        map[x][y+1] += now;
                        answer = max(answer, now*2);
                        map[x][y] = 0;
                        visited[x][y+1] = true;
                    }
                    break;
                } else {
                    map[x][y+1] = now;
                    map[x][y] = 0;
                    ++y;
                }
            }
        }
    }
}

void process(int iter, int map[20][20]) {
    if(iter==5) {
        return;
    }
    ++iter;
    int tmp[20][20];
    //위로
    copy(tmp, map);
    up(tmp);
    process(iter,tmp);
    //아래로
    copy(tmp, map);
    down(tmp);
    process(iter,tmp);
    //왼쪽으로
    copy(tmp, map);
    left(tmp);
    process(iter,tmp);
    //오른쪽으로
    copy(tmp, map);
    right(tmp);
    process(iter,tmp);
}

void solution() {
    process(0, block);
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
