#include<iostream>
#include<deque>
using namespace std;

const int sz = 1e2;
const int apple = 111;
const int snake = 112;
int n,k,l,answer;
int map[sz][sz];
deque<pair<int,char>> change_info;
deque<pair<int,int>> monster;
int dx;
int dy=1;

void input() {
    cin>>n>>k;
    int a,b;
    for(int i=0; i<k; i++) {
        cin>>a>>b;
        --a;
        --b;
        map[a][b] = apple;
    }
    cin>>l;
    int x;
    char c;
    while(l--) {
        cin>>x;
        cin>>c;
        change_info.push_back({x,c});
    }
    l=change_info.size();
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

bool go_ahead() {
    pair<int,int> head = monster.front();
    int nx = head.first + dx;
    int ny = head.second + dy;
    if(!check_range(nx,ny)) {
        return false;
    }
    if(map[nx][ny]==snake) {
        return false;
    }
    monster.push_front({nx,ny});
    if(map[nx][ny]!=apple) {
        pair<int,int> back = monster.back();
        map[back.first][back.second] = 0;
        monster.pop_back();
    }
    map[nx][ny] = snake;
    return true;
}

void change_dir(char ch) {
    if(dx==0 && dy==1) {
        if(ch=='L') {
            dx = -1;
            dy = 0;
        } else {
            dx = 1;
            dy = 0;
        }
    } else if(dx==0 && dy==-1) {
        if(ch=='L') {
            dx = 1;
            dy = 0;
        } else {
            dx = -1;
            dy = 0;
        }
    } else if(dx==-1 && dy==0) {
        if(ch=='L') {
            dx = 0;
            dy = -1;
        } else {
            dx = 0;
            dy = 1;
        }
    } else if(dx==1 && dy==0) {
        if(ch=='L') {
            dx = 0;
            dy = 1;
        } else {
            dx = 0;
            dy = -1;
        }
    }
}

void solution() {
    map[0][0] = snake;
    monster.push_back({0,0});
    while(1) {
        ++answer;
        if(!go_ahead()) {
            break;
        }
        if(!change_info.empty() && answer==change_info.front().first) {
            change_dir(change_info.front().second);
            change_info.pop_front();
        }
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
