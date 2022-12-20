//
// Created by 이경민 on 2022/12/20.
//
#include<iostream>
using namespace std;

#define wall 1
#define clean 2

int n,m;
int map[50][50];
int r,c,d;
int answer;
int turn;

void go_front() {
    if(d==0) {
        --r;
    } else if(d==1) {
        ++c;
    } else if(d==2) {
        ++r;
    } else {
        --c;
    }
}

pair<int,int> get_back() {
    if(d==0) {
        return {r+1,c};
    } else if(d==1) {
        return {r,c-1};
    } else if(d==2) {
        return {r-1,c};
    } else {
        return {r,c+1};
    }
}

pair<int,int> get_left() {
    if(d==0) {
        return {r,c-1};
    } else if(d==1) {
        return {r-1,c};
    } else if(d==2) {
        return {r,c+1};
    } else {
        return {r+1,c};
    }
}

void change_direction() {
    if(d==0) {
        d=3;
    } else {
        --d;
    }
}

void input() {
    cin>>n>>m;
    cin>>r>>c>>d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
        }
    }
}

void run() {
    pair<int,int> point;

    while(1) {
        //1번 과정
        if(map[r][c]==0) {
            map[r][c]=clean;
            ++answer;
        }

        if(turn==4) {
            point = get_back();
            if(map[point.first][point.second]==wall) {
                return;
            } else {
                r = point.first;
                c = point.second;
                turn=0;
                continue;
            }
        }

        point = get_left();
        if(map[point.first][point.second]==0) {
            change_direction();
            go_front();
            turn=0;
            continue;
        } else {
            change_direction();
            ++turn;
            continue;
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
