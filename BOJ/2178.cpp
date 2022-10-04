//
//  2178.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/05.
//

#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n,m;
string s;
bool map[100][100];
bool visited[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(){
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{0,0}});
    visited[0][0] = true;
    
    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if (x==n-1 && y==m-1) return cnt;
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!visited[nx][ny] && map[nx][ny]==1) {
                if(nx>=0 && nx<n && ny>=0 &&ny<m){
                    q.push({cnt+1,{nx,ny}});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    
    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int k=0; k<m; k++){
            map[i][k] = s[k] -'0';
        }
    }
    cout<<bfs();
}
