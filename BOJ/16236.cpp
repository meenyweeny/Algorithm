//
// Created by 이경민 on 2022/12/20.
//
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;

int n;
int map[21][21];
bool visited[21][21];
bool fish_active[21][21];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int fish_count, answer;
int shark_size=2;
pair<int,int> shark;
deque<pair<int,pair<int,int>>> fish;

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
    if(a.first==b.first) {
        if(a.second.first==b.second.first) {
            return a.second.second<b.second.second;
        } else {
            return a.second.first<b.second.first;
        }
    } else {
        return a.first<b.first;
    }
}

bool is_in_range(int x,int y) {
    return x>0 && x<=n && y>0 && y<=n;
}

int bfs(pair<int,int> a, pair<int,int> b) {
    deque<pair<int,pair<int,int>>> dq;
    dq.push_back({0,{a.first, a.second}});
    memset(visited,false,sizeof(visited));
    visited[a.first][a.second] = true;
    while(!dq.empty()) {
        int count = dq.front().first;
        int fx = dq.front().second.first;
        int fy = dq.front().second.second;
        dq.pop_front();

        if(fx == b.first && fy == b.second) {
            return count;
        }

        for(int i=0; i<4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            if(map[nx][ny]>shark_size) {
                continue;
            }
            visited[nx][ny] = true;
            dq.push_back({count+1, {nx,ny}});
        }
    }
    return 999999;
}

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
            if(map[i][j]==9) {
                shark = {i,j};
            } else if(map[i][j]!=0) {
                fish.push_back({map[i][j],{i,j}});
            }
        }
    }
    map[shark.first][shark.second] = 0;
    sort(fish.begin(), fish.end(), comp);
}

void run() {
    while(1) {
        if(fish.empty()) {
            break;
        }
        for(auto f:fish) {
            if(fish_active[f.second.first][f.second.second]) {
                continue;
            } else {
                if(f.first>=shark_size) {
                    return;
                } else {
                    break;
                }
            }
        }
        int mini = 999999;
        pair<int,int> next = {0,0};
        for(auto f:fish) {
            if(f.first >= shark_size) {
                break;
            }
            if(fish_active[f.second.first][f.second.second]) {
                continue;
            } else {
                int dist = bfs(shark,f.second);
                if(dist<mini) {
                    next = f.second;
                    mini = dist;
                } else if (dist==mini) {
                    if(next.first>f.second.first) {
                        next = f.second;
                    } else if(next.first==f.second.first) {
                        if(next.second>f.second.second) {
                            next = f.second;
                        }
                    }
                }
            }
        }

        if(mini >= 99999) {
            return;
        } else {
            fish_active[next.first][next.second] = true;
            answer += mini;
            shark = next;
            ++fish_count;
            map[shark.first][shark.second] = 0;
        }
        if(fish_count == shark_size) {
            fish_count = 0;
            ++shark_size;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    run();
    cout<<answer;
}
