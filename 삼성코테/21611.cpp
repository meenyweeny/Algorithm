#include<iostream>
#include<deque>
using namespace std;

int n,m,d,s;
int map[51][51];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};
int bombed_bead[4];
deque<int> beadlist;

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void fill_beadlist() {
    int x,y;
    x = y = n/2;
    int dir,loop,iter,itercheck;
    iter = 1;
    dir = loop = itercheck = 0;
    beadlist.clear();
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(!check_range(x,y)) {
            break;
        }
        int bead = map[x][y];
        if(bead!=0) {
            beadlist.push_back(bead);
        }
        ++itercheck;
        if(itercheck==iter) {
            itercheck = 0;
            ++loop;
            ++dir;
            dir%=4;
        }
        if(loop==2) {
            loop = 0;
            ++iter;
        }
    }
}

void fill_map() {
    int x,y;
    x = y = n/2;
    int dir,loop,iter,itercheck;
    iter = 1;
    dir = loop = itercheck = 0;
    fill(&map[0][0],&map[n][n],0);
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(!check_range(x,y)) {
            break;
        }
        if(beadlist.empty()) {
            break;
        }
        map[x][y] = beadlist.front();
        beadlist.pop_front();
        ++itercheck;
        if(itercheck==iter) {
            itercheck = 0;
            ++loop;
            ++dir;
            dir%=4;
        }
        if(loop==2) {
            loop = 0;
            ++iter;
        }
    }
}

void blizard(int dirx,int diry) {
    int cx,cy;
    cx = cy = n/2;
    for(int i=0; i<s; i++) {
        cx += dirx;
        cy += diry;
        map[cx][cy] = 0;
    }
}

bool bomb_continuous_bead() {
    bool flag = false;
    int x,y;
    x = y = n/2;
    int dir,loop,iter,itercheck;
    iter = 1;
    dir = loop = itercheck = 0;
    int before, count;
    before = count = 0;
    beadlist.clear();
    int index = 0;
    while(1) {
        ++index;
        x += dx[dir];
        y += dy[dir];
        if(!check_range(x,y)) {
            break;
        }
        int now = map[x][y];
        if(now==0) {
            break;
        }
        if(now==before) {
            ++count;
        } else {
            if(count<4) {
                for(int i=0; i<count; i++) {
                    beadlist.push_back(before);
                }
            } else {
                bombed_bead[before] += count;
                flag = true;
            }
            before = now;
            count = 1;
        }
        ++itercheck;
        if(itercheck==iter) {
            itercheck = 0;
            ++loop;
            ++dir;
            dir%=4;
        }
        if(loop==2) {
            loop = 0;
            ++iter;
        }
    }
    if(count<4) {
        for(int i=0; i<count; i++) {
            beadlist.push_back(before);
        }
    } else {
        bombed_bead[before] += count;
        flag = true;
    }
    return flag;
}

void change_bead() {
    //연속개수 세어서 beadlist에 담기
    beadlist.clear();
    int x,y;
    x = y = n/2;
    int dir,loop,iter,itercheck;
    iter = 1;
    dir = loop = itercheck = 0;
    int before, count;
    before = count = 0;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(!check_range(x,y)) {
            break;
        }
        int now = map[x][y];
        if(now==0) {
            break;
        }
        if(now==before) {
            ++count;
        } else {
            if(count!=0) {
                beadlist.push_back(count);
                beadlist.push_back(before);
            }
            before = now;
            count = 1;
        }
        ++itercheck;
        if(itercheck==iter) {
            itercheck = 0;
            ++loop;
            ++dir;
            dir%=4;
        }
        if(loop==2) {
            loop = 0;
            ++iter;
        }
    }
    if(count!=0) {
        beadlist.push_back(count);
        beadlist.push_back(before);
    }
    fill_map();
}

void solve() {
    input();
    int bx[4] = {-1,1,0,0};
    int by[4] = {0,0,-1,1};
    while(m--) {
        cin>>d>>s;
        --d;
        blizard(bx[d],by[d]);
        fill_beadlist();
        fill_map();
        while(bomb_continuous_bead()) {
            fill_map();
        }
        change_bead();
    }
    cout<<bombed_bead[1] + (2*bombed_bead[2]) + (3*bombed_bead[3]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
