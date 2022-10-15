#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int w,h;
bool map[50][50];
bool visited[50][50];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool is_in_range(int x,int y) {
    return x>=0 && x<w && y>=0 && y<h;
}

void bfs(int x,int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];

            if(!is_in_range(nx,ny)) {
                continue;
            }

            if(visited[nx][ny]) {
                continue;
            }

            if(!map[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        cin>>h>>w;

        if(w==0 && h==0) {
            break;
        }

        for(int i=0; i<w; i++) {
            for(int k=0; k<h; k++) {
                cin>>map[i][k];
            }
        }

        int count = 0;
        for(int i=0; i<w; i++) {
            for(int k=0; k<h; k++) {
                if(!visited[i][k] && map[i][k]) {
                    bfs(i,k);
                    ++count;
                }
            }
        }

        cout<<count<<"\n";

        memset(visited,false,sizeof(visited));
    }
}
