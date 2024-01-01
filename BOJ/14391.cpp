#include<iostream>
using namespace std;

int n,m,answer;
char map[4][4];

void copy(bool a[4][4], bool b[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void run(bool visited[4][4], int count,int sum) {
    if(count == n*m) {
        answer = max(sum,answer);
        return;
    }
    int x,y;
    x = y = 0;
    while(1) {
        if(visited[x][y]) {
            ++y;
            if(y==m) {
                y = 0;
                ++x;
            }
        } else {
            break;
        }
    }
    int number = 0;
    int loop = 0;
    int tx,ty;
    tx = x;
    ty = y;
    bool visit[4][4];
    copy(visit, visited);
    while(1) {
        if(ty==m) {
            break;
        }
        if(!visited[tx][ty]) {
            number *= 10;
            number += (map[tx][ty] - '0');
            visit[tx][ty] = true;
            ++loop;
            run(visit, count + loop, sum + number);
        } else {
            break;
        }
        ++ty;
    }
    copy(visit, visited);
    loop = number = 0;
    tx = x;
    ty = y;
    while(1) {
        if(tx==n) {
            break;
        }
        if(!visited[tx][ty]) {
            number *= 10;
            number += (map[tx][ty] - '0');
            visit[tx][ty] = true;
            ++loop;
            run(visit, count + loop, sum + number);
        } else {
            break;
        }
        ++tx;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
        }
    }

    bool visit[4][4];
    fill(&visit[0][0],&visit[3][4],false);
    run(visit,0,0);
    cout<<answer;
}
