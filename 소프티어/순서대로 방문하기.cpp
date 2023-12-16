#include<iostream>
#include<vector>
using namespace std;

const int wall = 100;
int n,m;
int map[4][4];
int answer = 0;
pair<int,int> start;

void input() {
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[i][j];
      if(map[i][j]) {
        map[i][j] = wall;
      }
    }
  }
  int count = 1;
  int x,y;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    --x;
    --y;
    if(count==1) {
      start = {x,y};
    }
    map[x][y] = count++;
  }
}

bool check_range(int x, int y) {
  return x>=0 && x<n && y>=0 && y<n;
}

void solution(int next_count, int x,int y, bool visited[4][4]) {
  if(next_count == m+1) {
    ++answer;
    return;
  }
  for(int i=0; i<4; i++) {
    int nx = x + "2011"[i] -'1';
    int ny = y + "1120"[i] -'1';
    if(!check_range(nx,ny)) {
      continue;
    }
    if(visited[nx][ny]) {
      continue;
    }
    if(map[nx][ny]==wall) {
      continue;
    }
    int now = map[nx][ny];
    if(now>next_count) {
      continue;
    }
    bool newvisit[4][4];
    for(int i=0; i<4; i++) {
      for(int j=0; j<4; j++) {
        newvisit[i][j] = visited[i][j];
      }
    }
    newvisit[nx][ny] = true;
    solution(next_count==now ? next_count+1 : next_count, nx, ny, newvisit);
  }
}

void solve() {
  input();
  bool visit[4][4];
  fill(&visit[0][0], &visit[3][4], false);
  visit[start.first][start.second] = true;
  solution(2, start.first, start.second, visit);
  cout<<answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  
  return 0;
}
