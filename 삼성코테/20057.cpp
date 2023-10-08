#include<iostream>
using namespace std;

int n,answer,a,b;
int map[500][500];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

int routine(int x,int y,double mul,int total) {
    int add = total * mul;
    if(check_range(x,y)) {
        map[x][y] += add;
    } else {
        answer += add;
    }
    return add;
}

void spread(int x,int y,int dir) {
    int nx = dx[dir];
    int ny = dy[dir];
    int total = map[x+nx][y+ny];
    map[x+nx][y+ny] = 0;
    int saved = 0;
    int fx,fy;
    fx = x+(3*nx); fy = y+(3*ny);
    saved += routine(fx,fy,0.05,total);
    if(nx==0) {
        fx = x-1; fy = y+ny;
        saved += routine(fx,fy,0.07,total);
        fx = x+1; fy = y+ny;
        saved += routine(fx,fy,0.07,total);
        fx = x-2; fy = y+ny;
        saved += routine(fx,fy,0.02,total);
        fx = x+2; fy = y+ny;
        saved += routine(fx,fy,0.02,total);
        fx = x+1; fy = y;
        saved += routine(fx,fy,0.01,total);
        fx = x-1; fy = y;
        saved += routine(fx,fy,0.01,total);
        fx = x-1; fy = y+(2*ny);
        saved += routine(fx,fy,0.1,total);
        fx = x+1; fy = y+(2*ny);
        saved += routine(fx,fy,0.1,total);
    } else {
        fx = x+nx; fy = y-1;
        saved += routine(fx,fy,0.07,total);
        fx = x+nx; fy = y+1;
        saved += routine(fx,fy,0.07,total);
        fx = x+nx; fy = y-2;
        saved += routine(fx,fy,0.02,total);
        fx = x+nx; fy = y+2;
        saved += routine(fx,fy,0.02,total);
        fx = x; fy = y-1;
        saved += routine(fx,fy,0.01,total);
        fx = x; fy = y+1;
        saved += routine(fx,fy,0.01,total);
        fx = x+(2*nx); fy = y+1;
        saved += routine(fx,fy,0.1,total);
        fx = x+(2*nx); fy = y-1;
        saved += routine(fx,fy,0.1,total);
    }
    int pass = total - saved;
    fx = x + (2*nx); fy = y + (2*ny);
    if(!check_range(fx,fy)) {
        answer += pass;
    } else {
        map[fx][fy] += pass;
    }
}

void solution() {
    int iter = 1;
    int count = 0;
    int length = 0;
    int dir = 0;
    a = b = (n/2);
    while(1) {
        int nx,ny;
        nx = a + dx[dir];
        ny = b + dy[dir];
        if(!check_range(nx,ny)) {
            break;
        }
        ++length;
        spread(a,b,dir);
        a = nx;
        b = ny;
        if(length==iter) {
            length = 0;
            ++count;
            dir = (dir+1) % 4;
            if(count==2) {
                count = 0;
                ++iter;
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
