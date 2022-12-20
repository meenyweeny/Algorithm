//
// Created by 이경민 on 2022/12/20.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int n,m;
int answer = INT_MAX;
int delete_count, stores;
int map[51][51];
bool visitarray[13];
vector<pair<int,int>> store;
vector<pair<int,int>> home;
int dist[13][51][51];

int calc_distance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void run(int index, int count, bool visited[]) {
    if(count>stores) {
        return;
    }

    if(count>delete_count) {
        int sum = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(map[i][j]!=1) {
                    continue;
                }

                int mini = INT_MAX;
                for(int k=0; k<stores; k++) {
                    if(visited[k]) {
                        continue;
                    }
                    mini = min(mini,dist[k][i][j]);
                }

                sum += mini;
            }
        }
        answer = min(answer,sum);
    }

    for(int i=index; i<stores; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        run(i,count+1, visited);
        visited[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
            if(map[i][j]==2) {
                store.push_back({i,j});
            } else if(map[i][j]==1) {
                home.push_back({i,j});
            }
        }
    }

    stores = store.size();
    delete_count = stores - m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]!=1) {
                continue;
            }
            for(int k=0; k<stores; k++) {
                dist[k][i][j] = calc_distance({i,j}, store[k]);
            }
        }
    }

    run(0,1,visitarray);

    cout<<answer;
}
