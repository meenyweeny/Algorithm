#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int m,s;
deque<int> map[4][4];
deque<int> copied[4][4];
deque<int> tmp[4][4];
vector<int> sharkdir;
int eaten;
int smell[4][4];
int fdx[8] = {0,-1,-1,-1,0,1,1,1};
int fdy[8] = {-1,-1,0,1,1,1,0,-1};
int sdx[4] = {-1,0,1,0};
int sdy[4] = {0,-1,0,1};
pair<int,int> shark;

void input() {
    cin>>m>>s;
    int x,y,d;
    for(int i=0; i<m; i++) {
        cin>>x>>y>>d;
        --x;
        --y;
        --d;
        map[x][y].push_back(d);
    }
    cin>>shark.first>>shark.second;
    --shark.first;
    --shark.second;
}

void copy_magic() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            copied[i][j] = map[i][j];
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<4 && y>=0 && y<4;
}

int turn_fish(int dir) {
    return (dir==0) ? 7 : (dir-1);
}

void move_fish() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            tmp[i][j].clear();
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<map[i][j].size(); k++) {
                int nd = map[i][j][k];
                int nx,ny;
                while(1) {
                    nx = i + fdx[nd];
                    ny = j + fdy[nd];
                    if(!check_range(nx,ny)) {
                        nd = turn_fish(nd);
                    } else if(nx==shark.first && ny==shark.second) {
                        nd = turn_fish(nd);
                    } else if(smell[nx][ny]>0) {
                        nd = turn_fish(nd);
                    } else {
                        break;
                    }
                    if(nd==map[i][j][k]) {
                        nx = i;
                        ny = j;
                        break;
                    }
                }
                tmp[nx][ny].push_back(nd);
            }
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            map[i][j] = tmp[i][j];
        }
    }
}

void move_shark(vector<int> dirs) {
    if(dirs.size()==3) {
        //조합을 다 만들었으니, 상어를 진짜 움직일 수 있는 방향을 구한다
        bool visited[4][4];
        fill(&visited[0][0],&visited[3][4],false);
        int nx = shark.first;
        int ny = shark.second;
        bool flag = true;
        int eat = 0;
        for(int i=0; i<3; i++) {
            nx += sdx[dirs[i]];
            ny += sdy[dirs[i]];
            if(!check_range(nx,ny)) {
                flag = false;
                break;
            }
            if(!visited[nx][ny]) {
                eat += map[nx][ny].size();
                visited[nx][ny] = true;
            }
        }
        if(flag) {
            if(eaten<eat) {
                eaten = eat;
                sharkdir = dirs;
            }
        }
        return;
    }

    for(int i=0; i<4; i++) {
        dirs.push_back(i);
        move_shark(dirs);
        dirs.pop_back();
    }
}

void move_real_shark() {
    int nx = shark.first;
    int ny = shark.second;
    for(int i=0; i<3; i++) {
        nx += sdx[sharkdir[i]];
        ny += sdy[sharkdir[i]];
        if(map[nx][ny].empty()) {
            continue;
        } else {
            map[nx][ny].clear();
            smell[nx][ny] = 3;
        }
    }
    shark = {nx,ny};
}


void adjust_smell() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(smell[i][j]==0) {
                continue;
            }
            --smell[i][j];
        }
    }
}

void apply_copied() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<copied[i][j].size(); k++) {
                map[i][j].push_back(copied[i][j][k]);
            }
        }
    }
}

int get_fish_count() {
    int ret = 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            ret += map[i][j].size();
        }
    }
    return ret;
}

void solve() {
    input();
    for(int i=0; i<s; i++) {
        //1. 물고기 복제 마법
        copy_magic();
        //2. 모든 물고기가 한 칸 이동
        move_fish();
        //3. 상어 연속 3칸 이동
        eaten = -1;
        sharkdir.clear();
        vector<int> a;
        move_shark(a);
        move_real_shark();
        //4. 두번 전 이동의 냄새 사라짐
        adjust_smell();
        //5. 복제 마법 끝나서 실제 물고기 적용
        apply_copied();
    }
    cout<<get_fish_count();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
