#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct info {
    int x,y;
    bool able;
};
int n,m,d;
bool map[15][15];
int dist[15][15][15];
int answer = 0;
vector<int> archlist;
vector<info> tmpenemy;
vector<info> enemy;

void input() {
    cin>>n>>m>>d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j]) {
                tmpenemy.push_back({i,j,true});
            }
        }
    }
}

int get_dist(int x,int y, int yy) {
    return abs(n-x) + abs(y-yy);
}

void make_dist() {
    for(int k=0; k<m; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dist[i][j][k] = get_dist(i,j,k);
            }
        }
    }
}

void run() {
    int num = enemy.size();
    int archout = 0;
    while(num>0) {
        vector<int> out;
        for(auto arch:archlist) {
            pair<int,int> target;
            int idx;
            int distance = 1e9;
            for(int i=0; i<enemy.size(); i++) {
                if(!enemy[i].able) {
                    continue;
                }
                int dx = dist[enemy[i].x][enemy[i].y][arch];
                if(dx>d) {
                    continue;
                } else {
                    if(distance > dx) {
                        distance = dx;
                        target = {enemy[i].x,enemy[i].y};
                        idx = i;
                    } else if(distance==dx) {
                        if(enemy[i].y<target.second) {
                            target = {enemy[i].x,enemy[i].y};
                            idx = i;
                        }
                    }
                }
            }
            if(distance<1e9) {
                out.push_back(idx);
            }
        }
        for(auto o:out) {
            if(enemy[o].able) {
                enemy[o].able = false;
                --num;
                ++archout;
            }
        }

        for(int i=0; i<enemy.size(); i++) {
            auto e = enemy[i];
            if(!e.able) {
                continue;
            }
            enemy[i].x++;
            if(enemy[i].x>=n) {
                enemy[i].able = false;
                --num;
            }
        }
    }
    answer = max(answer,archout);
}

void make_arch(int count,int start, vector<int> archs) {
    if(archs.size()==3) {
        archlist = archs;
        enemy = tmpenemy;
        run();
        return;
    }

    for(int i=start; i<m; i++) {
        archs.push_back(i);
        make_arch(count+1, i+1, archs);
        archs.pop_back();
    }
}

void solve() {
    input();
    make_dist();
    make_arch(0,0,{});
    cout<<answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
