#include<iostream>
#include<queue>
using namespace std;

int n,m,k;
int score[20][20];
bool visited[20][20];
int dice[4][3] =  {{0,2,0},{4,1,3},{0,5,0},{0,6,0}};
unsigned long long answer;
pair<int,int> now;
int dir = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void input() {
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>score[i][j];
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void get_direction() {
    int nx = now.first + dx[dir];
    int ny = now.second + dy[dir];
    if(!check_range(nx,ny)) {
        if(dir>=2) {
            dir-=2;
        } else {
            dir+=2;
        }
    }
}

void roll_dice() {
    //이동 방향에 칸이 없으면 이동 방향을 반대로 하고 한 칸 구름
    get_direction();
    //한 칸 구르기
    now.first += dx[dir];
    now.second += dy[dir]; //현재 주사위 위치 변경
    //주사위 자체를 회전
    deque<int> dq;
    if(dir==0) {
        dq.push_back(dice[1][0]);
        dq.push_back(dice[1][1]);
        dq.push_back(dice[1][2]);
        dq.push_back(dice[3][1]);
        dice[1][1] = dq.front(); dq.pop_front();
        dice[1][2] = dq.front(); dq.pop_front();
        dice[3][1] = dq.front(); dq.pop_front();
        dice[1][0] = dq.front(); dq.pop_front();
    } else if(dir==1) {
        dq.push_back(dice[0][1]);
        dq.push_back(dice[1][1]);
        dq.push_back(dice[2][1]);
        dq.push_back(dice[3][1]);
        dice[1][1] = dq.front(); dq.pop_front();
        dice[2][1] = dq.front(); dq.pop_front();
        dice[3][1] = dq.front(); dq.pop_front();
        dice[0][1] = dq.front(); dq.pop_front();
    } else if(dir==2) {
        dq.push_back(dice[1][0]);
        dq.push_back(dice[1][1]);
        dq.push_back(dice[1][2]);
        dq.push_back(dice[3][1]);
        dice[3][1] = dq.front(); dq.pop_front();
        dice[1][0] = dq.front(); dq.pop_front();
        dice[1][1] = dq.front(); dq.pop_front();
        dice[1][2] = dq.front(); dq.pop_front();
    } else { //북
        dq.push_back(dice[0][1]);
        dq.push_back(dice[1][1]);
        dq.push_back(dice[2][1]);
        dq.push_back(dice[3][1]);
        dice[3][1] = dq.front(); dq.pop_front();
        dice[0][1] = dq.front(); dq.pop_front();
        dice[1][1] = dq.front(); dq.pop_front();
        dice[2][1] = dq.front(); dq.pop_front();
    }
}

int get_area(int b) {
    fill(&visited[0][0],&visited[19][20],false);
    int count = 1;
    queue<pair<int,int>> q;
    visited[now.first][now.second] = true;
    q.push({now.first,now.second});

    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';
            if(!check_range(nx,ny)) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            if(score[nx][ny] == b) {
                ++count;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    return count;
}

void get_score() {
    int b = score[now.first][now.second];
    int area = get_area(b);
    answer += (b*area);
}

void judge_direction() {
    int bottom = dice[3][1];
    int number = score[now.first][now.second];
    if(bottom>number) {
        //시계 90 회전
        ++dir;
        dir %= 4;
    } else if(bottom<number) {
        --dir;
        if(dir<0) {
            dir = 3;
        }
    }
}

void solve() {
    input();
    now = {0,0};
    while(k--) {
        roll_dice(); //주사위를 이동 방향으로 한 칸 굴린다
        get_score(); //칸에 대한 점수를 획득한다
        judge_direction(); //이동방향 결정
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
