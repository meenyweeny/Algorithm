#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

struct Point {
    int x,y;
};

int n,l,r;
int a[52][52];
bool visited[52][52];
int answer;
bool flag;

void input() {
    fill(&a[0][0],&a[51][51],300);
    cin>>n>>l>>r;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>a[i][j];
        }
    }
}

bool is_in_range(int x,int y) {
    return x>=1 && x<=n && y>=1 && y<=n;
}

void bfs(Point p) {
    queue<Point> q;
    q.push(p);
    int sum = 0;
    vector<Point> pnt;

    while(!q.empty()) {
        Point front = q.front();
        q.pop();
        pnt.push_back(front);
        sum += a[front.x][front.y];
        visited[front.x][front.y] = true;

        for(int i=0; i<4; i++) {
            int dx = "1120"[i] - '1';
            int dy = "2011"[i] - '1';
            dx += front.x;
            dy += front.y;
            if(!is_in_range(dx,dy)) {
                continue;
            }
            if(visited[dx][dy]) {
                continue;
            }
            int gap = abs(a[front.x][front.y] - a[dx][dy]);
            if(gap>=l && gap<=r) {
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }

    if(pnt.size()>1) {
        flag = true;
    }
    int moved = (sum/pnt.size());
    for(auto k:pnt) {
        a[k.x][k.y] = moved;
    }
}

void find_union() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(visited[i][j]) {
                continue;
            }
            bfs({i,j});
        }
    }
}

void solution() {
    while(1) {
        memset(visited,false,sizeof(visited));
        flag=false;
        find_union();
        answer += flag;
        if(!flag) {
            break;
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
