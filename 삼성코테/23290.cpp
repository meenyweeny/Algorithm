#include<iostream>
#include<vector>
using namespace std;

int m,s;
int map[4][4][8]; //(x,y)에 방향 z인 물고기 몇마리인지
int smell[4][4];
int copied[4][4][8];
int fx[8] = {0,-1,-1,-1,0,1,1,1};
int fy[8] = {-1,-1,0,1,1,1,0,-1};
pair<int,int> shark;
int shx[4] = {-1,0,1,0};
int shy[4] = {0,-1,0,1};
vector<int> shark_path;
int shark_eaten_fish;

void input() {
    cin>>m>>s;
    int x,y,d;
    for(int i=0; i<m; i++) {
        cin>>x>>y>>d;
        --x;
        --y;
        --d;
        ++map[x][y][d];
    }
    cin>>shark.first>>shark.second;
    --shark.first;
    --shark.second;
}

bool check_range(int x,int y) {
    return x>=0 && x<4 && y>=0 && y<4;
}

void copy_fishes() {
    for(int k=0; k<8; k++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                copied[i][j][k] = map[i][j][k];
            }
        }
    }
}

void apply_fishes() {
    for(int k=0; k<8; k++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                map[i][j][k] += copied[i][j][k];
            }
        }
    }
}

void minus_smell() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(!smell[i][j]) {
                continue;
            }
            --smell[i][j];
        }
    }
}

int change_dir(int d) {
    return d==0 ? 7 : d-1;
}

void move_fishes() {
    int moved[4][4][8];
    for(int k=0; k<8; k++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                moved[i][j][k] = 0;
            }
        }
    }
    for(int k=0; k<8; k++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(!map[i][j][k]) {
                    continue;
                }
                int dir = k;
                int fishes = map[i][j][k];
                bool flag = false;
                for(int iter=0; iter<8; iter++) {
                    int nx = i + fx[dir];
                    int ny = j + fy[dir];
                    //불가능 -> dir 반시계방향으로 이동 후 continue
                    if(!check_range(nx,ny)) {
                        dir = change_dir(dir);
                        continue;
                    } else if(nx == shark.first && ny == shark.second) {
                        dir = change_dir(dir);
                        continue;
                    } else if(smell[nx][ny]>0) {
                        dir = change_dir(dir);
                        continue;
                    }
                    //가능
                    moved[nx][ny][dir] += fishes;
                    flag = true;
                    break;
                }

                if(!flag) {
                    moved[i][j][k] += fishes;
                }
            }
        }
    }
    //물고기를 다 움직였으면, moved가 map 자체가 된다
    for(int k=0; k<8; k++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                map[i][j][k] = moved[i][j][k];
            }
        }
    }
}

void find_shark_path(vector<int> directions, int eaten_fishes, int bx, int by, int visited[4][4]) {
    if(directions.size()==3) {
        //먹은 fishes랑 비교
        if(shark_eaten_fish<eaten_fishes) {
            shark_eaten_fish = eaten_fishes;
            shark_path = directions;
        }
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = bx + shx[i];
        int ny = by + shy[i];
        if(!check_range(nx,ny)) {
            continue;
        }
        directions.push_back(i);
        int fish_count = 0;
        if(!visited[nx][ny]) {
            for(int k=0; k<8; k++) {
                fish_count += map[nx][ny][k];
            }
        }
        ++visited[nx][ny];
        find_shark_path(directions,eaten_fishes+fish_count,nx,ny,visited);
        --visited[nx][ny];
        directions.pop_back();
    }
}

void out_fish_remain_smell() {
    for(auto sp:shark_path) {
        shark.first += shx[sp];
        shark.second += shy[sp];
        int count = 0;
        for(int k=0; k<8; k++) {
            count += map[shark.first][shark.second][k];
            map[shark.first][shark.second][k] = 0;
        }
        if(count) {
            smell[shark.first][shark.second] = 3;
        }
    }
}

void move_shark() {
    shark_path.clear();
    shark_eaten_fish = -1;
    int visit[4][4];
    fill(&visit[0][0], &visit[3][4], 0);
    find_shark_path({},0,shark.first,shark.second,visit); //상어가 이동할 방향 3개 순서대로 찾기
    out_fish_remain_smell(); //물고기를 제외시키고 냄새를 남긴다
}

void solve() {
    input();
    while(s--) {
        copy_fishes(); //상어가 복제 마법을 시전
        move_fishes(); //모든 물고기가 한 칸 이동
        move_shark(); //상어가 연속해서 3칸 이동
        minus_smell(); //냄새 감소
        apply_fishes(); //복제 마법이 적용
    }
    int answer = 0;
    for(int k=0; k<8; k++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                answer += map[i][j][k];
            }
        }
    }
    cout<<answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
