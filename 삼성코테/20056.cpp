#include<iostream>
#include<vector>
using namespace std;

struct Fireball {
    int x,y,s,m,d;
    bool alive;
};

int n,m,k;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
vector<Fireball> balls;
vector<int> map[50][50];

void input() {
    cin>>n>>m>>k;
    int x,y,w,s,d;
    for(int i=0; i < m; i++) {
        cin >> x >> y >> w >> s >> d;
        --x;
        --y;
        balls.push_back({x, y, s, w, d, true});
    }
}

void init() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            map[i][j].clear();
        }
    }
}

pair<int,int> get_next_position(int x,int y,int d,int s) {
    x += (dx[d] * s);
    y += (dy[d] * s);
    while(1) {
        if(x>=0) {
            break;
        }
        x+=n;
    }
    x%=n;
    while(1) {
        if(y>=0) {
            break;
        }
        y+=n;
    }
    y%=n;
    return {x,y};
}

void move_fireball() {
    for(int i=0; i<balls.size(); i++) {
        Fireball b = balls[i];
        if(!b.alive) {
            continue;
        }
        pair<int,int> next = get_next_position(b.x,b.y,b.d,b.s);
        balls[i].x = next.first;
        balls[i].y = next.second;
        map[balls[i].x][balls[i].y].push_back(i);
    }
}

void join_fireball() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int ballsize = map[i][j].size();
            if(ballsize<2) {
                continue;
            }
            int odd,even,weight,speed;
            odd = even = weight = speed = 0;
            for(auto b:map[i][j]) {
                speed += balls[b].s;
                weight += balls[b].m;
                odd += (balls[b].d % 2);
                even += (!(balls[b].d % 2));
            }
            if(weight<5) {
                for(auto b:map[i][j]) {
                    balls[b].m = 0;
                    balls[b].alive = false;
                }
            } else {
                weight /= 5;
                speed /= ballsize;
                int start = (odd == 0 || even == 0) ? 0 : 1;
                int count = 0;
                for(int k=0; k<ballsize; k++) {
                   balls[map[i][j][k]].m = weight;
                   balls[map[i][j][k]].s = speed;
                   balls[map[i][j][k]].d = start + (count * 2);
                   ++count;
                }
                if(ballsize<4) {
                    for(int k=ballsize; k<4; k++) {
                        balls.push_back({i,j,speed,weight,start + (count*2),true});
                        ++count;
                    }
                } else if(ballsize>4) {
                    for(int k=4; k<ballsize; k++) {
                        balls[map[i][j][k]].alive = false;
                        balls[map[i][j][k]].m = 0;
                    }
                }
            }
        }
    }
}

void solution() {
    init();
    move_fireball();
    join_fireball();
}

void solve() {
    input();
    while(k--) {
        solution();
    }
    int answer = 0;
    for(auto b:balls) {
        if(!b.alive || !b.m) {
            continue;
        }
        answer += b.m;
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
