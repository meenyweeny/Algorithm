//
// Created by 이경민 on 2022/10/04.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
string str;
bool map[26][26];
bool visited[26][26];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool is_in_range(int x,int y) {
    return x>=1 && x<=n && y>=1 && y<=n;
}

int bfs(int x,int y) {
    queue<pair<int,int>> q;
    int count = 0;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        ++count;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!is_in_range(nx,ny)) {
                continue;
            }
            if(!map[nx][ny]) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    return count;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>str;
        for(int k=1; k<=n; k++) {
            map[i][k] = (str[k-1] == '1');
        }
    }

    vector<int> answer;
    for(int i=1; i<=n; i++) {
        for(int k=1; k<=n; k++) {
            if(!visited[i][k] && map[i][k]) {
                answer.push_back(bfs(i,k));
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout<<answer.size()<<"\n";
    for(auto i:answer) {
        cout<<i<<"\n";
    }
}
